package experiment;

import java.util.ArrayList;

public class Coffee extends Product{
	
	private String origin;
	private String roast;
	private String flavor;
	private String aroma;
	private String acidity;
	private String body;
	
	public Coffee(String initialCode, String initialDescription, double initialPrice, String origin, String roast,
			String flavor, String aroma, String acidity, String body) {
		super(initialCode, initialDescription, initialPrice);
		this.origin = origin;
		this.roast = roast;
		this.flavor = flavor;
		this.aroma = aroma;
		this.acidity = acidity;
		this.body = body;
	}

	public String getOrigin() {
		return origin;
	}

	public String getRoast() {
		return roast;
	}

	public String getFlavor() {
		return flavor;
	}

	public String getAroma() {
		return aroma;
	}

	public String getAcidity() {
		return acidity;
	}

	public String getBody() {
		return body;
	}
	
	public String toString() {
		return this.getCode()+"_"+this.getDescription()+"_"+this.getPrice()
				+"_"+this.origin+"_"+this.roast
				+"_"+this.flavor+"_"+this.aroma
				+"_"+this.acidity+"_"+this.body;
	}
	
	public ArrayList<DataField> getDataFields() {
		ArrayList<DataField> result = new ArrayList<DataField>();
		
		result.add(new DataField("Code:",this.getCode()));
		result.add(new DataField("Description:",this.getDescription()));
		result.add(new DataField("Price:",Double.toString(this.getPrice())));
		result.add(new DataField("Origin:",this.origin));
		result.add(new DataField("Roast:",this.roast));
		result.add(new DataField("Flavor:",this.flavor));
		result.add(new DataField("Aroma:",this.aroma));
		result.add(new DataField("Acidity:",this.acidity));
		result.add(new DataField("Body:",this.body));
		
		return result;
	}
	
}
