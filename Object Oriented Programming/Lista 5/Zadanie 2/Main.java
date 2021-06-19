
import java.util.*;

public class Main {
	public static void main(String[] args) {
		//stworzenie hash table ktora mapuje klucze do wartosci w tym przpadku nazwa zmiennej do wartosci tej zmiennej np <x,2>
		Hashtable<String, Integer> Tree = new Hashtable<String, Integer>();
		Tree.put("x", 2);
		System.out.println("x = " + Tree.get("x"));
		Tree.put("y", 4);
		System.out.println("y = " + Tree.get("y"));

		expression hard_mathematical_equation = new add(new fixed_num(2), new variable("x", Tree));
		hard_mathematical_equation = new subs(hard_mathematical_equation, new fixed_num(5));
		hard_mathematical_equation = new add(hard_mathematical_equation, new variable("y", Tree));

		System.out.print(hard_mathematical_equation.toString() + " = " + hard_mathematical_equation.evaluate());
	}
}