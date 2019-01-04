import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class File_In_37 {

    private int matrix_size;
    private String filename;

    public File_In_37(String filename) {
        this.filename = filename;
    }

    private boolean scan_File() {

        File file = new File(filename);

        if (file.exists()) {
            return true;
        }
        return false;
    }

    private void size_matrix() {
        try {
            Scanner scanner = new Scanner(new File(filename));

            matrix_size = 0;

            while (scanner.hasNextInt()) {

                scanner.nextInt();

                matrix_size++;

            }

            scanner.close();

        } catch (FileNotFoundException e) {

            e.printStackTrace();
        }

    }

    private boolean check_square() {

        int root = (int) Math.sqrt(matrix_size);

        if (root * root == matrix_size) {
            return true;
        }
        return false;
    }

    private int[][] form_matix() {

        Scanner scanner;
        int matrix[][] = null;

        try {

            scanner = new Scanner(new File(filename));

            int size = (int) Math.sqrt(matrix_size);

            matrix = new int[size][size];

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    matrix[i][j] = scanner.nextInt();
                }
            }

            scanner.close();

        } catch (FileNotFoundException e) {

            e.printStackTrace();
        }
        return matrix;
    }

    public int[][] matrix() {
        if (!scan_File()) {
            System.out.println("FILE NOT FOUND = " + filename);
            return null;
        }

        System.out.println("FILE FOUND = " + filename);

        size_matrix();

        if (!check_square()) {

            System.out.println("This file does not contain a square number of integers");
            return null;
        }

        System.out.println("The file produced the following square matrix");
        return form_matix();
    }
}
