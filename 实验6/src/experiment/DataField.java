package experiment;

public class DataField {
	
	private String name;
	private String value;
	
	public DataField(String initName, String initValue) {
		super();
		this.name = initName;
		this.value = initValue;
	}

	public String getName() {
		return name;
	}

	public String getValue() {
		return value;
	}
	
}
