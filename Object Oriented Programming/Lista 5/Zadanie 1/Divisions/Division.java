package Divisions;

public class Division implements Comparable<Division>{

	public int value;
	
	public Division(int val){
		this.value = val;
    }

	@Override
    public int compareTo(Division o) {
        if(o.value>this.value){return 1;}
		else if(o.value<this.value){return -1;}
		else return 0;
    }

	@Override
    public String toString() {
		String x = "" + this.value;
        return x;
    }
	
	
}