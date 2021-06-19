package Divisions;

public class Iron extends Division {
	public String name;

	public Iron(int key) {
		super(key);
		name = "Iron ";

	}

    @Override
    public String toString() {
        return name + super.toString();
    }
}