import java.awt.EventQueue;
import javax.swing.JFrame;

public class Main {
    public static void main(String[] args) {
        /*
         * String test_file = args[0]; String test_type = args[1];
         */

        EventQueue.invokeLater(new Runnable() {
            public void run() {
                JFrame ex;
                String test_file = "";
                String test_type = "Journal";

                if (test_type == "Book")
                    ex = new BookEditor(test_file);
                else if (test_type == "Journal")
                    ex = new JournalEditor(test_file);
                else
                    ex = new ComicBookEditor(test_file);

                ex.setVisible(true);
            }
        });
    }
}