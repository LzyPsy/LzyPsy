package experiment;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SwingConstants;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

//import javafx.stage.*;

/**
 * Gourmet Coffee System.
 *
 * @author iCarnegie
 * @version 1.1.0
 * @see Product
 * @see Coffee
 * @see CoffeeBrewer
 * @see Catalog
 * @see OrderItem
 * @see Order
 * @see Sales
 * @see CatalogLoader
 * @see FileCatalogLoader
 * @see DataFormatException
 * @see SalesFormatter
 * @see PlainTextSalesFormatter
 * @see HTMLSalesFormatter
 * @see XMLSalesFormatter
 * @see DataField
 */
public class GourmetCoffeeGUI extends JPanel {

	/**
	 * 
	 */
	private static final long serialVersionUID = -7920360244650888771L;

	/* Standar error stream */
	static private PrintWriter  stdErr = new  PrintWriter(System.err, true);

	/* Window width in pixels */
	static private int WIDTH = 720;

	/* Window height in pixels */
	static private int HEIGHT = 630;

	/* Size of the catalog list cell in pixels */
	static private int CATALOG_CELL_SIZE = 50;

	/* Visible rows in catalog list */
	static private int CATALOG_LIST_ROWS = 14;

	/* Size of the order list cell in pixels */
	static private int ORDER_CELL_SIZE = 100;

	/* Visible rows in order list */
	static private int ORDER_LIST_ROWS = 6;

	/* Size quantity text field */
	static private int QUANTITY__TEXTFIELD_SIZE = 5;

	/* Size total text field */
	static private int TOTAL__TEXTFIELD_SIZE = 8;

	/* Rows in status text area rows */
	static private int STATUS_ROWS = 8;

	/* Rows in status text area cols */
	static private int STATUS_COLS = 40;

	private JList<String> catalogList;
	private JList<String> orderList;
	private JButton addModifyButton;
	private JButton removeButton;
	private JButton registerSaleButton;
	private JButton displaySalesButton;
	private JButton saveSalesButton;
	private JPanel productPanel;
	private JLabel quantityLabel;
	private JLabel totalLabel;
	private JTextField quantityTextField;
	private JTextField totalTextField;
	private JTextArea statusTextArea;
	private JRadioButton  plainRadioButton;
	private JRadioButton  HTMLRadioButton;
	private JRadioButton  XMLRadioButton;

	private Catalog  catalog;
	private Order  currentOrder;
	private static Sales sales = new Sales();;

	private SalesFormatter salesFormatter;
	private NumberFormat dollarFormatter;

	/**
	 * Loads a product catalog and starts the application.
	 *
	 * @param args  String arguments.  Not used.
	 * @throws IOException if there are errors in the loading the catalog.
	 */
	public static void  main(String[]  args) throws IOException {

		String filename1 = "";
		String filename2 = "";

		if (args.length != 2) {
			filename1 = "catalog.dat";
			filename2 = "Sales Information.txt";
		} else {
			filename1 = args[0];
			filename2 = args[1];
		}
		try {
			Catalog catalog =(new FileCatalogLoader()).loadCatalog(filename1);
			sales = (new FileSalesLoader()).loadSales(filename2,catalog);
			
			JFrame frame = new JFrame("Gourmet Coffee");
			frame.setIconImage(new ImageIcon("¿§·È.png").getImage());
			frame.setContentPane(new GourmetCoffeeGUI(catalog));
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setSize(WIDTH, HEIGHT);
			frame.setResizable(true);
			frame.setVisible(true);

		} catch (FileNotFoundException fnfe) {
			stdErr.println("The file does not exist");

			System.exit(1);

		} catch (DataFormatException dfe) {
			stdErr.println("The file contains malformed data: "
					+ dfe.getMessage());

			System.exit(1);
		}
	}

	/**
	 * Instantiates the components and arranges them in a window.
	 *
	 * @param initialCatalog a product catalog.
	 */
	public  GourmetCoffeeGUI(Catalog initialCatalog) {

		// create the components
		catalogList = new JList<String>();
		orderList = new JList<String>();
		catalogList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		catalogList.setVisibleRowCount(CATALOG_LIST_ROWS);
		catalogList.setFixedCellWidth(CATALOG_CELL_SIZE);
		orderList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		orderList.setVisibleRowCount(ORDER_LIST_ROWS);
		orderList.setFixedCellWidth(ORDER_CELL_SIZE);
		addModifyButton = new JButton("Add|Modify Order Item");
		removeButton = new JButton("Remove Order Item");
		registerSaleButton = new JButton("Register Sale of Current Order");
		displaySalesButton = new JButton("Display Sales");
		saveSalesButton = new JButton("Save Sales");
		quantityLabel = new JLabel("Quantity:");
		totalLabel = new JLabel("Total:");
		quantityTextField = new JTextField("", QUANTITY__TEXTFIELD_SIZE);
		totalTextField = new JTextField("$0.00", TOTAL__TEXTFIELD_SIZE);
		totalTextField.setEditable(false);
		statusTextArea = new JTextArea(STATUS_ROWS, STATUS_COLS);
		statusTextArea.setEditable(false);
		plainRadioButton = new JRadioButton("Plain", true);
		HTMLRadioButton = new JRadioButton("HTML");
		XMLRadioButton = new JRadioButton("XML");

		ButtonGroup group = new ButtonGroup();

		group.add(plainRadioButton);
		group.add(HTMLRadioButton);
		group.add(XMLRadioButton);

		// Product Information panel
		productPanel = new JPanel();
		productPanel.setBorder(
				BorderFactory.createTitledBorder("Product Information"));

		// Catalog panel
		JPanel catalogPanel = new JPanel();

		catalogPanel.setBorder(BorderFactory.createTitledBorder("Catalog"));
		catalogPanel.add (
				new JScrollPane(catalogList,
						JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
						JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));

		// "Add|Modify Product" panel
		JPanel centralPanel = new JPanel(new BorderLayout());
		JPanel addModifyPanel = new JPanel(new GridLayout(2, 1));
		JPanel quantityPanel = new JPanel();

		quantityPanel.add(quantityLabel);
		quantityPanel.add(quantityTextField);
		addModifyPanel.add(quantityPanel);
		addModifyPanel.add(addModifyButton);
		centralPanel.add(productPanel, BorderLayout.CENTER);
		centralPanel.add(addModifyPanel, BorderLayout.SOUTH);

		// Order panel
		JPanel orderPanel = new JPanel(new BorderLayout());

		orderPanel.setBorder(BorderFactory.createTitledBorder("Order"));

		JPanel totalPanel = new JPanel();

		totalPanel.add(totalLabel);
		totalPanel.add(totalTextField);

		JPanel buttonsPanel = new JPanel(new GridLayout(2, 1));

		buttonsPanel.add(removeButton);
		buttonsPanel.add(registerSaleButton);
		orderPanel.add(totalPanel, BorderLayout.NORTH);
		orderPanel.add(new JScrollPane(orderList,
				JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
				JScrollPane.HORIZONTAL_SCROLLBAR_NEVER), BorderLayout.CENTER);
		orderPanel.add(buttonsPanel, BorderLayout.SOUTH);

		// Status panel
		JPanel bottomPanel = new JPanel(new BorderLayout());

		bottomPanel.setBorder(BorderFactory.createTitledBorder("Status"));

		JPanel salesButtonsPanel = new JPanel(new GridLayout(1, 5));

		salesButtonsPanel.add(plainRadioButton);
		salesButtonsPanel.add(HTMLRadioButton);
		salesButtonsPanel.add(XMLRadioButton);
		salesButtonsPanel.add(displaySalesButton);
		salesButtonsPanel.add(saveSalesButton);
		bottomPanel.add (new JScrollPane(statusTextArea,
				JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.CENTER);
		bottomPanel.add(salesButtonsPanel, BorderLayout.SOUTH);

		// arrange panels in window
		setLayout(new BorderLayout());
		add(catalogPanel, BorderLayout.WEST);
		add(centralPanel, BorderLayout.CENTER);
		add(orderPanel, BorderLayout.EAST);
		add(bottomPanel, BorderLayout.SOUTH);

		// start listening for list and buttons events
		catalogList.addListSelectionListener(new DisplayProductListener());
		addModifyButton.addActionListener(new AddModifyListener());
		removeButton.addActionListener(new RemoveListener());
		registerSaleButton.addActionListener(new RegisterSaleListener());
		displaySalesButton.addActionListener(new DisplaySalesListener());
		saveSalesButton.addActionListener(new SaveSalesListener());
		plainRadioButton.addActionListener(new PlainListener());
		HTMLRadioButton.addActionListener(new HTMLListener());
		XMLRadioButton.addActionListener(new XMLListener());

		// populate the product catalog
		catalog = initialCatalog;
		catalogList.setListData(catalog.getCodes());

		currentOrder = new Order(); 
		salesFormatter = PlainTextSalesFormatter.getSingletonInstance();
		dollarFormatter = NumberFormat.getCurrencyInstance();
	}

	/*
	 * Obtains a {@link JPanel} object with the information of a product.
	 *
	 * @param dataFields  an {@link ArrayList} of {@link DataField}
	 *                    with the product information.
	 * @return  a {@link JPanel} with the product information.
	 */
	private JPanel getDataFieldsPanel(ArrayList<DataField> dataFields) {

		/* PLACE YOUR CODE HERE */
		JPanel DataFieldsPanel = new JPanel();
		DataFieldsPanel.setLayout(new GridLayout(dataFields.size(),2,-15,0));
		Font font1 = new Font("Î¢ÈíÑÅºÚ",Font.BOLD,15);
		Font font2 = new Font("Î¢ÈíÑÅºÚ",Font.PLAIN,13);
		for(DataField i:dataFields) {
			JLabel text1 = new JLabel(i.getName(),JLabel.LEFT);
			text1.setFont(font1);
			text1.setHorizontalAlignment(SwingConstants.LEFT);
			JLabel text2 = new JLabel(i.getValue(),JLabel.LEFT);
			text2.setHorizontalAlignment(SwingConstants.LEFT);
			text2.setFont(font2);
			DataFieldsPanel.add(text1);
			DataFieldsPanel.add(text2);
		}

		return DataFieldsPanel;
	}

	/**
	 * This inner class handles list-selection events.
	 */
	class DisplayProductListener implements ListSelectionListener {

		/**
		 * Displays the information of the selected product.
		 *
		 * @param event  the event object.
		 */
		public void valueChanged(ListSelectionEvent event) {

			if (! catalogList.getValueIsAdjusting()) {

				String code = (String) catalogList.getSelectedValue();
				Product product = catalog.getProduct(code);

				productPanel.removeAll();
				productPanel.setVisible(false);                   // Use this
				productPanel.add(                                 // to update
						getDataFieldsPanel(product.getDataFields())); // the panel
				productPanel.setVisible(true);                    // correctly

				Font font = new Font("Î¢ÈíÑÅºÚ",Font.PLAIN,15);
				statusTextArea.setFont(font);
				statusTextArea.setText("Product " + code
						+ " has been displayed");
			}
		}
	}

	/**
	 * This inner class processes <code>addModifyButton</code> events.
	 */
	class AddModifyListener implements ActionListener {

		/**
		 * Adds an order item to the current order.
		 *
		 * @param event  the event object.
		 */

		private boolean hasint(String str) {
			for(int i=0;i<str.length();i++) {
				if(str.charAt(i)>=48&&str.charAt(i)<=57)
					return true;
			}
			return false;
		}

		public void actionPerformed(ActionEvent event) {

			/* PLACE YOUR CODE HERE */
			statusTextArea.setText("");
			if(catalogList.getSelectedValue()==null) {
				statusTextArea.setText(
						"The user has not selected a product.");
				return;
			}
			String code = catalogList.getSelectedValue();
			String quantityText = quantityTextField.getText().toString();
			if(!quantityText.matches("^[-\\+]?[\\d]*$")||quantityText.equals("")||!hasint(quantityText)) {
				statusTextArea.setText(
						"The quantity text field does not contain an integer.");
				return;
			}
			int quantity=Integer.parseInt(quantityText);
			if(quantity<=0) {
				statusTextArea.setText(
						"The quantity text field contains a negative integer or zero.");
				return;
			}

			for(OrderItem i:currentOrder) {
				if(i.getProduct().getCode().equals(code)) {
					i.setQuantity(i.getQuantity()+quantity);
					totalTextField.setText(dollarFormatter.format(currentOrder.getTotalCost()));
					orderList.setListData(currentOrder.getItems());
					return;
				}
			}
			OrderItem order = new OrderItem(catalog.getProduct(code),quantity);
			currentOrder.addItem(order);
			totalTextField.setText(dollarFormatter.format(currentOrder.getTotalCost()));
			orderList.setListData(currentOrder.getItems());
			statusTextArea.setText(
					"The user has selected "+ quantity + " * " + code +" in the order.");
		}
	}

	/**
	 * This inner class processes <code>removeButton</code> events.
	 */
	class RemoveListener implements ActionListener {

		/**
		 * Removes an order item from the current order.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			/* PLACE YOUR CODE HERE */
			statusTextArea.setText("");
			if(currentOrder.items.size()==0) {
				statusTextArea.setText(
						"The current order is empty.");
				return;
			}
			if(orderList.getSelectedValue()==null) {
				statusTextArea.setText(
						"The user has not selected an item in the order.");
				return;
			}

			String str = orderList.getSelectedValue();
			String code = str.substring(2,6);
			System.out.println(code);
			for(OrderItem i:currentOrder) {
				if(i.getProduct().getCode().equals(code)) {
					currentOrder.removeItem(i);
					break;
				}
			}
			totalTextField.setText(dollarFormatter.format(currentOrder.getTotalCost()));
			orderList.setListData(currentOrder.getItems());
			statusTextArea.setText(
					"The user has removed "+ code +" in the order.");
		}
	}

	/**
	 * This inner class processes <code>registerSaleButton</code> button events.
	 */
	class RegisterSaleListener implements ActionListener {

		/**
		 * Registers the sale of the current order.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			if (currentOrder.getNumberOfItems() == 0) {
				statusTextArea.setText("The order is empty.");
			} else {
				sales.addOrder(currentOrder);
				currentOrder = new Order();
				orderList.setListData(currentOrder.getItems());
				totalTextField.setText(dollarFormatter.format(0));
				statusTextArea.setText("The sale has been registered.");
				File file = new File("Sales Information.txt");
				try {
					BufferedWriter bw=new BufferedWriter(new FileWriter(file));
					for(Order i:sales.orders) {
						bw.write("----------");
						bw.newLine();
						for(OrderItem j:i) {
							bw.write(Integer.toString(j.getQuantity()));
							bw.newLine();
							bw.write(j.getProduct().getCode());
							bw.newLine();
						}
					}
					bw.flush();
					bw.close();
				} catch (IOException e) {
					// TODO ×Ô¶¯Éú³ÉµÄ catch ¿é
					e.printStackTrace();
				}
			}
		}
	}

	/**
	 * This inner class processes <code>displaySalesButton</code>events.
	 */
	class DisplaySalesListener implements ActionListener {

		/**
		 * Displays the sales information.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			if (sales.getNumberOfOrders() == 0) {
				statusTextArea.setText("No orders have been sold.");
			} else {
				statusTextArea.setText(salesFormatter.formatSales(sales));
			}
		}
	}

	/*
	 * This inner class processes <code>saveSalesButton</code>  events.
	 */
	class SaveSalesListener implements ActionListener {

		/**
		 * Saves the sales informations in a file.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			/* PLACE YOUR CODE HERE */
			statusTextArea.setText("");
			if(currentOrder.items.size()==0) {
				statusTextArea.setText(
						"No orders have been sold.");
				return;
			}
			if(!sales.orders.isEmpty())
			sales.orders.remove(sales.orders.size()-1);
			sales.addOrder(currentOrder);
		}
	}

	/*
	 * This inner class processes <code>plainRadioButton</code> events.
	 */
	class PlainListener implements ActionListener {

		/**
		 * Sets the sales formatter to plain text.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			salesFormatter =
					PlainTextSalesFormatter.getSingletonInstance();
		}
	}

	/*
	 * This inner class processes <code>HTMLRadioButton</code> events.
	 */
	class HTMLListener implements ActionListener {

		/**
		 * Sets the sales formatter to HTML.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			salesFormatter = HTMLSalesFormatter.getSingletonInstance();
		}
	}

	/*
	 * This inner class processes <code>XMLRadioButton</code> events.
	 */
	class XMLListener implements ActionListener {

		/**
		 * Sets the sales formatter to XML.
		 *
		 * @param event  the event object.
		 */
		public void actionPerformed(ActionEvent event) {

			salesFormatter = XMLSalesFormatter.getSingletonInstance();
		}
	}
}