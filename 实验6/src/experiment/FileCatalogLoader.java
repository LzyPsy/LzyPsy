package experiment;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class FileCatalogLoader implements CatalogLoader {

	private Product readProduct(String line)
			throws DataFormatException {
		int i=0;
		String[] str = new String[4];
		StringTokenizer st=new StringTokenizer(line,"_");
		if(st.countTokens()!=4) {
			throw new DataFormatException(line);
		}
		else {
			try {
				while(st.hasMoreTokens()) {
					str[i++]=st.nextToken();
				}

				return new Product(str[1],str[2],Double.parseDouble(str[3]));
			}catch (NumberFormatException num) {
				throw new DataFormatException(line);
			}
		}
	}

	private Coffee readCoffee(String line)
			throws DataFormatException{
		int i=0;
		String[] str = new String[10];
		StringTokenizer st=new StringTokenizer(line,"_");
		if(st.countTokens()!=10) {
			throw new DataFormatException(line);
		}
		else {
			try {
				while(st.hasMoreTokens()) {
					str[i++]=st.nextToken();
				}

				return new Coffee(str[1],str[2],Double.parseDouble(str[3])
						,str[4],str[5],str[6],str[7],str[8],str[9]);
			}catch (NumberFormatException num) {
				throw new DataFormatException(line);
			}
		}
	}

	private CoffeeBrewer readCoffeeBrewer(String line) 
			throws DataFormatException{
		int i=0;
		String[] str = new String[7];
		StringTokenizer st=new StringTokenizer(line,"_");
		if(st.countTokens()!=7) {
			throw new DataFormatException(line);
		}
		else {
			try {
				while(st.hasMoreTokens()) {
					str[i++]=st.nextToken();
				}

				return new CoffeeBrewer(str[1],str[2],Double.parseDouble(str[3])
						,str[4],str[5],Integer.parseInt(str[6]));
			}catch (NumberFormatException num) {
				throw new DataFormatException(line);
			}
		}
	}

	@Override
	public Catalog loadCatalog(String filename) 
			throws FileNotFoundException, IOException, DataFormatException {

		File file = new File(filename);
		if(!file.exists())
			file.createNewFile();
		Catalog catalog = new Catalog();
		String line;
		FileReader fr = new FileReader(filename);
		BufferedReader br=new BufferedReader(fr);
		while((line=br.readLine())!=null) {
			if(line.startsWith("Product"))
				catalog.addProduct(this.readProduct(line));
			else if(line.startsWith("Coffee"))
				catalog.addProduct(this.readCoffee(line));
			else if(line.startsWith("Brewer"))
				catalog.addProduct(this.readCoffeeBrewer(line));
		}
		br.close();

		return catalog;
	}

}
