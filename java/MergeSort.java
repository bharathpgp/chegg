import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MergeSort {

    public void Sort(Integer[] numbers, int paramLow, int n) {
        int low = paramLow;
        int high = n;
        if (low >= high) {
            return;
        }

        int mid = (low + high) / 2;
        Sort(numbers, low, mid);
        Sort(numbers, mid + 1, high);
        int endLow = mid;
        int startHigh = mid + 1;
        while ((paramLow <= endLow) && (startHigh <= high)) {
            if (numbers[low] < numbers[startHigh]) {
                low++;
            } else {
                int tmp = numbers[startHigh];
                for (int i = startHigh - 1; i >= low; i--) {
                    numbers[i + 1] = numbers[i];
                }
                numbers[low] = tmp;
                low++;
                endLow++;
                startHigh++;
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        MergeSort msort = new MergeSort();
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                List<Integer> numbers = new ArrayList<Integer>();
                String[] strNums = line.split(" ");
                for (int i = 0; i < strNums.length; i++)
                    numbers.add(Integer.parseInt(strNums[i]));
                Integer[] inputArray = numbers.toArray(new Integer[numbers.size()]);
                msort.Sort(inputArray, 0, inputArray.length - 1);
                for (Integer i : inputArray) {
                    bw.write(i + " ");
                }
                bw.write("\n");
            }
            br.close();
            bw.close();

        } catch (IOException ie) {
            System.out.print(ie.getMessage());
        }
    }
}