package Divisions;

public class Gold extends Division {
	public String name;

	public Gold(int key) {
		super(key);
		name = "Gold ";

	}

    @Override
    public String toString() {
        return name + super.toString();
    }
}