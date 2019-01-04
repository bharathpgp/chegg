import java.math.*;

class LibFunctions {
    double sqrtM(double x) {
        return Math.sqrt(x);
    }
    double sqrtN(double x) {
        double approx = 0.5 * x;
        double better = 0.5 * (approx + x / approx);
        while (better != approx) {
            approx = better;
            better = 0.5 * (approx + x / approx);
        }
        return approx;
    }
    double sqrtR(double x) {
        return Math.sqrt(x);
    }
    int sumNF(int N) {
        return (N * (N + 1)) / 2;
    }
    int sumNL(int N) {
        int i, sum = 0;
        for (i = 1; i <= N; i++)
            sum += i;
        return sum;
    }
    int sumNR(int N) {
        if (0 == N)
            return N;
        else
            return N + sumNR(N - 1);
    }
}