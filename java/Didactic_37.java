import java.util.Scanner;

public class Didactic_37 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        File_In_37 test;
        Analysis_37 analysis = new Analysis_37();
        boolean status;
        String input = "";
        while (true) {
            System.out.print("Enter the filename or quit to quit: ");
            input = scanner.nextLine();

            if (input.equalsIgnoreCase("quit")) {
                break;
            }

            test = new File_In_37(input);
            int matrix[][] = test.matrix();

            if (matrix != null) {
                for (int i = 0; i < matrix.length; i++) {
                    for (int j = 0; j < matrix[0].length; j++) {
                        System.out.print(matrix[i][j] + " ");
                    }
                    System.out.println();
                }
                status = analysis.isDidactic(matrix);

                if (status)
                    System.out.println("given square array is didactic.");
                else
                    System.out.println("given square array is not didactic.");
            }
        }
    }
}