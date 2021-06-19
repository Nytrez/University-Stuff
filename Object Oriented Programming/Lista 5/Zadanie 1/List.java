public class List<T extends Comparable<T>>{
    private Element<T> begin;

    public List(){
        begin = null;
    }

    public void add(T item){
        Element<T> element = new Element<>(item);
        begin = add(element, begin);
    }
    
    private Element<T> add(Element<T> to_add, Element<T> current){
        if (current == null){
            return to_add;
        }
        if (to_add.val.compareTo(current.val) == 1){
            to_add.next = current;
            return to_add;
        }
        current.next = add(to_add, current.next);
        return current;
    }

    public T get_first() throws Exception{
        if (begin == null)
            throw new Exception("queue is empty");
        return begin.val;
    }

    @Override
    public String toString() {
        String s = "";
        Element<T> temp = begin;
        while (temp != null){
            s += temp.val + "\n";
            temp = temp.next;
        }
        return s;
    }
}