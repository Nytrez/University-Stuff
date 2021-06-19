package Divisions;

public class Bronze extends Division {
	public String name;

	public Bronze(int key) {
		super(key);
		name = "Bronze ";

	}

	@Override
    public String toString() {
        return name + super.toString();
    }
}