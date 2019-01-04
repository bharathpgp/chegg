
import java.util.Scanner;
import java.io.*;

public class TestScores implements Serializable {

    int testScores[];

    public TestScores(int[] testScores) throws IllegalArgumentException {
        for (int i = 0; i < testScores.length; i++) {

            if (testScores[i] < 0 || testScores[i] > 100) {
                try {
                    throw new InvalidTestScore("Score in the array is negative or greater than 100");
                } catch (InvalidTestScore invalidTestScore) {
                    invalidTestScore.printStackTrace();
                }
            }
        }

        this.testScores = testScores;

    }

    public double averageTestScore() {
        int sum = 0;
        double average;
        for (int i = 0; i < testScores.length; i++) {
            sum = sum + testScores[i];
        }
        average = (double) sum / testScores.length;
        return average;
    }
}