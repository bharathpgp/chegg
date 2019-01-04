
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

class TestDeSerialization {
    public static void main(String[] args) {
        try {
            FileInputStream file = new FileInputStream("file.ser");
            ObjectInputStream in = new ObjectInputStream(file);

            TestScores[] testScores = new TestScores[8];
            for (int i = 0; i < testScores.length; i++) {
                testScores[i] = (TestScores) in.readObject();
                System.out.println("Average = " + testScores[i].averageTestScore());
            }
            in.close();
            file.close();
            System.out.println("Object Deserialized");

        } catch (IOException e) {
            System.out.println("IO exception found.");
        } catch (ClassNotFoundException ex) {
            System.out.println("ClassNotFoundException is caught");
        }
    }
}