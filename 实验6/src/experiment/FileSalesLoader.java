package experiment;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileSalesLoader implements SalesLoader {

	@Override
	public Sales loadSales(String filename,Catalog catalog) throws FileNotFoundException, IOException, DataFormatException {
		File file = new File(filename);
		if(!file.exists())
			file.createNewFile();
		Sales sales = new Sales();
		FileReader fr = new FileReader(filename);
		BufferedReader br=new BufferedReader(fr);
		String line = br.readLine();
		while(true) {
			if(line==null)
				break;
			Order order = new Order();
			while(true) {
				line=br.readLine();
				if(line==null || line.equals("----------"))
					break;
				int quantity = Integer.parseInt(line);
				line=br.readLine();
				Product product = catalog.getProduct(line);
				OrderItem orderitem = new OrderItem(product,quantity);
				order.addItem(orderitem);
			}
			sales.addOrder(order);
		}
		br.close();

		return sales;
	}

}
