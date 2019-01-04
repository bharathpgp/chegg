import java.util.ArrayList;

public class Analysis_37 {

    public boolean isDidactic(int matrix[][]) {

        int rowSum, colSum, lDiagSum = 0, rDiagSum = 0;
        boolean status = true;

        ArrayList sums = new ArrayList();

        for (int i = 0; i < matrix.length; i++) {
            rowSum = colSum = 0;
            for (int j = 0; j < matrix[0].length; j++) {
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
            }
            sums.add(rowSum);
            sums.add(colSum);
        }

        for (int i = 0; i < matrix.length; i++) {
            lDiagSum += matrix[i][i];
            rDiagSum += matrix[i][matrix.length - i - 1];
        }

        sums.add(lDiagSum);
        sums.add(rDiagSum);

        for (int i = 0; i < sums.size(); i++)
            if (sums.get(0) != sums.get(i))
                status = false;

        return status;
    }
}