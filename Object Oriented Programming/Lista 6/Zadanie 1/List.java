
import java.io.*;
import java.util.EmptyStackException;

public class List<T> implements Serializable {

    private static final long serialVersionUID = 1337;
    private int size = 0;
    private Elem<T> first;
    private Elem<T> last;

    public List() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }

    public boolean is_empty() {
        return (this.size == 0);
    }

    public void push_front(T data) {
        Elem<T> new_elem = new Elem<T>(data);
        if (this.size == 0) {
            this.last = new_elem;
            this.first = new_elem;

        } else {
            this.first.prev = new_elem;
            this.first.prev.next = this.first;
            this.first = this.first.prev;
        }
        this.size++;
    }

    public void push_back(T elem) {
        Elem<T> new_elem = new Elem<T>(elem);
        if (this.size == 0) {
            this.last = new_elem;
            this.first = new_elem;
        } else {
            this.last.next = new_elem;
            this.last.next.prev = this.last;
            this.last = this.last.next;
        }
        this.size++;
    }

    public T pop_front() throws EmptyStackException {
        if (this.size == 0)
            throw new EmptyStackException();

        T ret = first.data;

        if (size == 1) {
            first = last = null;
        } else {
            first = first.next;
            first.prev.next = null;
            first.prev = null;
        }
        size--;
        return ret;
    }

    public T pop_back() throws EmptyStackException {
        if (this.size == 0) {
            throw new EmptyStackException();
        }

        T ret = last.data;

        if (size == 1) {
            first = last = null;
        } else {
            last = last.prev;
            last.next.prev = null;
            last.next = null;
        }
        size--;
        return ret;
    }

    public void print() {
        Elem<T> to_print = this.first;
        String to_string = "";
        to_string += to_print.data;
        while (to_print.next != null) {
            to_string += " " + to_print.next.data;
            to_print = to_print.next;
        }

        System.out.println(to_string);

    }

    private void writeObject(ObjectOutputStream out) throws IOException {
        out.defaultWriteObject();

    }

    private void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException {
        in.defaultReadObject();
    }

}