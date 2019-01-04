import java.util.Scanner;

class InvalidTestScore extends Throwable {
    public InvalidTestScore(String s) {
        System.out.println(s);
    }
}

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int totalTestScores;
        try {
            System.out.print("Enter total number of Test Scores: ");
            totalTestScores = sc.nextInt();
            int[] testScores = new int[totalTestScores];
            for (int i = 0; i < testScores.length; i++) {
                System.out.print("Please enter Test Scores: ");
                testScores[i] = sc.nextInt();
            }
            TestScores testScoresObj = new TestScores(testScores);
            System.out.println(testScoresObj.averageTestScore());

        } catch (IllegalArgumentException e) {
            System.out.println("Test scores must have a value less than 100 and greater than 0.");
        }
    }
}