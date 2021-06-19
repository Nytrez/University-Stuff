public class Main {

    public static void main(String[] args) {
        MyCollection<Integer> collection = new MyCollection<Integer>();

        for (int i = 1; i < 6; i++) {
            collection.add((Integer) i);
        }

        System.out.println(collection.lista);

        System.out.println("size");
        System.out.println(collection.size());

        System.out.println("is empty");
        System.out.println(collection.isEmpty());

        System.out.println("does contain 3?");
        Integer xd = 3;
        System.out.println(collection.contains(xd));

        System.out.println("does contain 321375?");
        Integer not = 321375;
        System.out.println(collection.contains(not));

        System.out.println("add 321375");
        collection.add(not);
        System.out.println(collection.lista);

        System.out.println("remove 3");
        collection.remove((Integer) 3);
        System.out.println(collection.lista);

        MyCollection<Integer> test = new MyCollection<Integer>();
        test.add((Integer) 1);
        test.add((Integer) 2);
        test.add((Integer) 4);

        System.out.println("does contain collection of 1 2 4?");
        System.out.println(collection.containsAll(test));

        System.out.println("does contain collection of 1 2 4 122?");
        test.add((Integer) 122);
        System.out.println(collection.containsAll(test));

        test.add((Integer) 6);
        System.out.println("add collection of 1 2 3 122 6 to collection");
        collection.addAll(test);
        System.out.println(collection.lista);

        test.clear();
        test.add((Integer) 5);
        test.add((Integer) 321375);

        System.out.println("remove collection of 5 321375");
        collection.removeAll(test);
        System.out.println(collection.lista);

        MyCollection<Integer> test2 = new MyCollection<Integer>();
        test2.add((Integer) 0);
        test2.add((Integer) 6);
        test2.add((Integer) 122);

        System.out.println("retain only collection of 0 6 122");
        collection.retainAll(test2);
        System.out.println(collection.lista);

        System.out.println("clear");
        collection.clear();
        System.out.println(collection.lista);
    }

}
