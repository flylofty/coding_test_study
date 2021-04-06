import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj_11502 {

    static boolean[] isPrimeNumber = new boolean[1001];
    static ArrayList<Integer> al = new ArrayList<Integer>();
    static boolean isFound;

    public static void main(String[] args) throws IOException {

        Arrays.fill(isPrimeNumber, true);
        isPrimeNumber[0] = isPrimeNumber[1] = false;

        for(int i = 2; i <= 1000; ++i) {
            if (!isPrimeNumber[i])
                continue;
            for(int j = i + i; j <= 1000; j = j + i) {
                isPrimeNumber[j] = false;
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            isFound = false;
            findAnswer(num);

            if (!isFound)
                System.out.println(0);

            al.clear();
        }
    }

    private static void findAnswer(int num) {

        if (isFound)
            return;

        if (al.size() == 3 && num == 0) {

            StringBuilder sb = new StringBuilder();
            for(int i = 2; i >= 0; --i) {
                sb.append(al.get(i)).append(" ");
            }
            System.out.println(sb);
            isFound = true;
            return;
        }

        for(int i = num; i >= 2; --i) {

            if (!isPrimeNumber[i])
                continue;

            al.add(i);
            findAnswer(num - i);

            if (!al.isEmpty())
                al.remove(al.size() - 1);
        }
    }
}