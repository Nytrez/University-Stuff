public class ComicBook extends Book {
	public int NumberOf;

	private static final long serialVersionUID = -7676814061879257639L;

	public ComicBook(String T, String A, int R, int N) {
		super(T, A, R);
		this.NumberOf = N;
	}

	public ComicBook() {
		super();
		this.NumberOf = 1;
	}

	public String toString() {
		return super.toString() + '\n' + this.NumberOf;
	}

}