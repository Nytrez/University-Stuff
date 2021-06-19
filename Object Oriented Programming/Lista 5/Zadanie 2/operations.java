
//dodawanie
class add implements expression {
	expression a;
	expression b;

	public add(expression a, expression b) {
		this.a = a;
		this.b = b;
	}

	public int evaluate() {
		return a.evaluate() + b.evaluate();
	}

	public String toString() {
		return "(" + a + "+" + b + ")";
	}
}

//odejmowanie
class subs implements expression {
	expression a;
	expression b;

	public subs(expression a, expression b) {
		this.a = a;
		this.b = b;
	}

	public int evaluate() {
		return a.evaluate() - b.evaluate();
	}

	public String toString() {
		return "(" + a + "-" + b + ")";
	}
}
