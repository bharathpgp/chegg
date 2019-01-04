
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

class TestSerialization {
    public static void main(String[] args) {
        try {
            int[][] numbers = { { 10, 25, 34, 42, 50 }, { 1, 2, 3, 4, 5 }, { 20, 30, 40 }, { 3, 6, 7, 3, 6 },
                    { 12, 45 }, { 99, 12, 67 }, { 24, 56 }, { 86, 10, 11 } };

            TestScores[] testScores = new TestScores[8];
            for (int i = 0; i < testScores.length; i++) {
                testScores[i] = new TestScores(numbers[i]);
            }
            FileOutputStream file = new FileOutputStream("file.ser");
            ObjectOutputStream out = new ObjectOutputStream(file);

            for (int i = 0; i < testScores.length; i++) {
                out.writeObject(testScores[i]);
            }
            out.close();
            file.close();
            System.out.println("Object Serialized");

        } catch (IllegalArgumentException e) {
            System.out.println("Test scores must have a value less than 100 and greater than 0.");
        } catch (IOException e) {
            System.out.println("IO exception found.");
        }
    }
}