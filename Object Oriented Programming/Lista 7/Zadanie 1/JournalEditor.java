import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

import java.io.Serializable;
import java.util.Scanner;

public class JournalEditor extends JFrame implements ActionListener, Serializable {
	private static final long serialVersionUID = 1L;
	public JButton SaveButton, OpenButton;
	public JTextField TextTitle, TextAuthor, TextRelease, TextFrequency;
	public Journal TheFile;

	public JournalEditor(String s) {
		initUI();
		TheFile = new Journal();

		if (s != "") {
			File file = new File(s);
			ReadFromFile(file);
		}
	}

	public final void initUI() {
		SaveButton = new JButton("Save to file");
		OpenButton = new JButton("Open file");

		SaveButton.setBounds(20, 10, 200, 30);
		OpenButton.setBounds(20, 50, 200, 30);

		this.setLayout(null);

		getContentPane().add(SaveButton);
		getContentPane().add(OpenButton);
		SaveButton.addActionListener(this);
		OpenButton.addActionListener(this);

		TextTitle = new JTextField("Title");
		TextTitle.setBounds(230, 10, 200, 30);
		getContentPane().add(TextTitle);

		TextAuthor = new JTextField("Author");
		TextAuthor.setBounds(230, 50, 200, 30);
		getContentPane().add(TextAuthor);

		TextRelease = new JTextField("Release date");
		TextRelease.setBounds(230, 90, 200, 30);
		getContentPane().add(TextRelease);

		TextFrequency = new JTextField("Frequency of releases (days)");
		TextFrequency.setBounds(230, 130, 200, 30);
		getContentPane().add(TextFrequency);

		setSize(500, 250);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public void ReadJournal() {
		TextTitle.setText(TheFile.Title);
		TextAuthor.setText(TheFile.Author);
		TextRelease.setText(Integer.toString(TheFile.Release));
		TextFrequency.setText(Integer.toString(TheFile.Frequency));
	}

	public void ReadFromFile(File file) {
		try {
			Scanner in = new Scanner(file);

			String T = in.nextLine();
			String A = in.nextLine();
			String R = in.nextLine();
			String X = in.nextLine();

			TheFile = new Journal(T, A, Integer.parseInt(R), Integer.parseInt(X));
			ReadJournal();
			in.close();
		} catch (FileNotFoundException e1) {
		}
	}

	public void SaveJournal() {
		TheFile = new Journal(TextTitle.getText(), TextAuthor.getText(), Integer.parseInt(TextRelease.getText()),
				Integer.parseInt(TextFrequency.getText()));
	}

	public void SaveToFile(File file) {
		try {
			PrintWriter ToSave = new PrintWriter(file);
			SaveJournal();
			ToSave.println(TheFile.toString());
			ToSave.close();
		} catch (FileNotFoundException e1) {
		}
	}

	public void actionPerformed(ActionEvent e) {
		Object source = e.getSource();

		if (source == SaveButton) {
			JFileChooser fileChooser = new JFileChooser();
			if (fileChooser.showSaveDialog(SaveButton) == JFileChooser.APPROVE_OPTION) {
				File file = fileChooser.getSelectedFile();
				SaveToFile(file);
			}
		}

		if (source == OpenButton) {
			JFileChooser fileChooser = new JFileChooser();

			if (fileChooser.showOpenDialog(OpenButton) == JFileChooser.APPROVE_OPTION) {
				File file = fileChooser.getSelectedFile();
				ReadFromFile(file);

			}
		}
	}
}