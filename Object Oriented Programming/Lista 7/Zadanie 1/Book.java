import java.io.Serializable;

public class Book implements Serializable {
	private static final long serialVersionUID = 4661681646491395516L;
	public String Title, Author;
	public int Release;

	public Book(String T, String A, int R) {
		Title = T;
		Author = A;
		Release = R;
	}

	public Book() {
		this("Title", "Author", 1);
	}

	public String toString() {
		return Title + "\n" + Author + "\n" + Integer.toString(Release);
	}
}