package experiment;

import java.util.ArrayList;
import java.util.Iterator;

public class Catalog implements Iterable<Product>{

	ArrayList<Product> products;

	public Catalog() {
		super();
		products = new ArrayList<Product>();
	}

	public void addProduct(Product product) {
		this.products.add(product);
	}

	@Override
	public Iterator<Product> iterator() {
		return this.products.iterator();
	}

	public Product getProduct(String code) {
		Iterator<Product> it = this.iterator();
		while(it.hasNext()) {
			Product i = it.next();
			if(i.getCode().equals(code))
				return i;
		}
		return null;
	}

	public int getNumberOfProducts() {
		return this.products.size();
	}

	public String[] getCodes() {

		ArrayList<String> codelist = new ArrayList<String>();
		
		Iterator<Product> it = this.iterator();
		while(it.hasNext()) {
			Product i = it.next();
			codelist.add(i.getCode());
		}
		
		int number=0;
		String[] result = new String[codelist.size()];
		for(String i:codelist) {
			result[number++]=i.toString();
		}
		return result;
	}

}
