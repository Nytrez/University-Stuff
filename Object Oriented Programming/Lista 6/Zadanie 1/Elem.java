
import java.io.*;
import java.io.Serializable;

public class Elem <T> implements Serializable {

    private static final long serialVersionUID = 1337;
    T data;
    Elem<T> next;
    Elem<T> prev;

    Elem(T data)
    {
        this.data = data;
    }

    private void writeObject(ObjectOutputStream out) throws IOException {
        out.defaultWriteObject();
    }

    private void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException {
        in.defaultReadObject();

    }
}