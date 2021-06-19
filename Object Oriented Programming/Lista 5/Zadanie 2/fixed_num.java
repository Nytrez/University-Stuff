public class fixed_num implements expression {
	int val;

	public fixed_num(int x) {
		val = x;
	}

	public int evaluate() {
		return val;
	}

	public String toString() {
		return "" + val;
	}
}