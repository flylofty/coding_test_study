import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        char[] arr = br.readLine().toCharArray();
        Arrays.sort(arr);

        int sum = 0;
        for(int i = arr.length - 1; i >= 0; --i) {
            sum += arr[i] - '0';
            sb.append(arr[i]);
        }

        if (sum % 3 == 0 && arr[0] == '0') {
            System.out.println(sb);
        }
        else {
            System.out.println(-1);
        }
    }
}