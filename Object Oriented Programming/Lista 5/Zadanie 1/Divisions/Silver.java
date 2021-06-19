package Divisions;

public class Silver extends Division {
	public String name;

	public Silver(int key) {
		super(key);
		name = "Silver ";

	}

	@Override
    public String toString() {
        return name + super.toString();
    }
}