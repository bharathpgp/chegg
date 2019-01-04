
// safeadd calss to add numbers safely
public class safeadd {
    public static void main(String[] args) {
        int x = -2147483648;
        System.out.println(x);
        x--;
        System.out.println(x);
        System.out.println(safeAdd(214748364, 100));
        System.out.println(safeAdd(2147483647, 100));
    }

    public static int safeAdd(int left, int right) throws ArithmeticException {
        if (right < 0) {
            // If the second integer is negative check this condition
            if (left < Integer.MIN_VALUE - right) {
                throw new ArithmeticException("Integer Overflow");
            }
        } else {
            // If the second integer is positive check this condition
            if (left > Integer.MAX_VALUE - right) {
                throw new ArithmeticException("Integer Overflow");
            }
        }
        return left + right;
    }
}
