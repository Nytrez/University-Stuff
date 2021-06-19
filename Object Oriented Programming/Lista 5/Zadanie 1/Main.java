import Divisions.*;

public class Main {
    public static void main(String[] args) throws Exception{
        List<Division> Divisions = new List<Division>();

        Divisions.add(new Gold(4));
        Divisions.add(new Silver(3));
        Divisions.add(new Iron(1));
        System.out.println(Divisions.toString());
		System.out.println("Pierwszy element kolejki: " + Divisions.get_first() + "\n");
		Divisions.add(new Bronze(0));
		System.out.println("Po dodaniu elementu Bronze 0: \n" + Divisions.toString());
		System.out.println("Pierwszy element kolejki: " + Divisions.get_first());



        

    }
}