public class Journal extends Book {
	int Frequency;

	private static final long serialVersionUID = -3614949347444157588L;

	public Journal(String T, String A, int R, int F) {
		super(T, A, R);
		this.Frequency = F;
	}

	public Journal() {
		super();
		this.Frequency = 1;
	}

	public String toString() {
		return super.toString() + '\n' + this.Frequency;
	}
}