import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

public class MyCollection<T> implements Collection<T> {

    List<T> lista = new ArrayList<T>();

    public int size() {
        return this.lista.size();
    }

    public boolean isEmpty() {
        if (this.size() == 0) {
            return true;
        }
        return false;
    }

    public boolean contains(Object o) {
        for (int i = 0; i < this.size(); i++) {
            if (this.lista.get(i).equals(o)) {
                return true;
            }
        }
        return false;
    }

    public Iterator<T> iterator() {
        return this.lista.iterator();
    }

    public Object[] toArray() {
        Object[] tab = new Object[this.size()];
        for (int i = 0; i < this.size(); i++) {
            tab[i] = this.lista.get(i);
        }
        return tab;
    }

    @SuppressWarnings("unchecked")
    public <T> T[] toArray(T[] Ts) {
        T[] tab = (T[]) new Object[this.size()];
        for (int i = 0; i < this.size(); i++) {
            tab[i] = (T) this.lista.get(i);
        }
        return tab;
    }

    public boolean add(T t) {
        int start_size = this.size();
        this.lista.add(t);
        if (start_size + 1 == this.size()) {
            return true;
        }
        return false;
    }

    public boolean remove(Object o) {
        for (int i = 0; i < this.size(); i++) {
            if (this.lista.get(i).equals(o)) {
                this.lista.remove(i);
                return true;
            }
        }
        return false;
    }

    public boolean containsAll(Collection<?> collection) {
        for (Object obj : collection) {
            if (!(this.lista.contains(obj))) {
                return false;
            }
        }
        return true;
    }

    @SuppressWarnings("unchecked")
    public boolean addAll(Collection<? extends T> collection) {
        int start_size = this.size();
        for (Object obj : collection) {
            this.lista.add((T) obj);
        }
        if (start_size + collection.size() == this.size()) {
            return true;
        }
        return false;
    }

    public boolean removeAll(Collection<?> collection) {
        int counter = 0;
        int start_size = this.size();
        for (Object obj : collection) {
            if ((this.contains(obj))) {
                this.remove(obj);
                counter++;
            }
        }
        if (this.size() == start_size - counter) {
            return true;
        }
        return false;
    }

    @SuppressWarnings("unchecked")
    public boolean retainAll(Collection<?> collection) {
        int counter = 0;
        int startSize = this.size();
        MyCollection<T> newCollection = new MyCollection<T>();
        for (Object obj : collection) {
            if (this.contains(obj)) {
                newCollection.add((T) obj);
                counter++;
            }
        }
        this.lista = newCollection.lista;
        if (newCollection.size() == startSize - counter) {
            return true;
        }
        return false;
    }

    public void clear() {
        this.lista = new ArrayList<T>();
    }
}
