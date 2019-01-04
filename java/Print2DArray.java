
/**
 * Print2DArray.java
 */
public class Print2DArray {

    public static void main(String[] args) {
        int[][] matrix = { { 1, 2, 3 }, { 4, 5, 6, 7 }, null, { 8, 9 } };

        print(matrix);
    }

    public static void print(int matrix[][]) {

        for (int[] row : matrix) {

            if (row != null) {
                for (int col : row) {
                    System.out.print(col + " ");
                }
                System.out.println();
            }
        }
    }
}