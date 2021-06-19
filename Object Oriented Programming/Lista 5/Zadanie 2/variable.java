import java.util.*;

public class variable implements expression {
	String s;
	Hashtable<String, Integer> Tree;

	public variable(String s, Hashtable<String, Integer> l) {
		this.s = s;
		this.Tree = l;
	}

	public int evaluate() {
		return Tree.get(s);
	}

	public String toString() {
		return s;
	}
}