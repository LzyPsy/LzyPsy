package experiment;

import java.util.ArrayList;

public class CoffeeBrewer extends Product{
	
	private String model;
	private String waterSupply;
	private int numberOfCups;
	
	public CoffeeBrewer(String initialCode, String initialDescription, double initialPrice, String model,
			String waterSupply, int numberOfCups) {
		super(initialCode, initialDescription, initialPrice);
		this.model = model;
		this.waterSupply = waterSupply;
		this.numberOfCups = numberOfCups;
	}

	public String getModel() {
		return model;
	}

	public String getWaterSupply() {
		return waterSupply;
	}

	public int getNumberOfCups() {
		return numberOfCups;
	}
	
	public String toString() {
		return this.getCode()+"_"+this.getDescription()+"_"+this.getPrice()
		+"_"+this.model+"_"+this.waterSupply+"_"+this.numberOfCups;
	}
	
	public ArrayList<DataField> getDataFields() {
		ArrayList<DataField> result = new ArrayList<DataField>();
		
		result.add(new DataField("Code:",this.getCode()));
		result.add(new DataField("Description:",this.getDescription()));
		result.add(new DataField("Price:",Double.toString(this.getPrice())));
		result.add(new DataField("Model:",this.model));
		result.add(new DataField("WaterSupply:",this.waterSupply));
		result.add(new DataField("NumberOfCups:",Integer.toString(this.numberOfCups)));
		
		return result;
	}
	
}
