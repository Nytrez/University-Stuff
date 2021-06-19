import java.io.*;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        List<Integer> List = new List<Integer>();

        for (int i = 1; i < 11; i++)
            List.push_back(i);
        for (int i = -11; i < 0; i++)
            List.push_front(i);
            
        List.pop_back();
        List.pop_front();

        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(new File("test.txt")))) {
            out.writeObject(List);
            out.close();
        }

        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream("test.txt"))) {
            List<Integer> readObject = (List<Integer>) inputStream.readObject();
            readObject.print();
        }

    }
}