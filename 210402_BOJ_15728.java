import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, K, Max = -987654321;
        Integer[] S, T, res;
        boolean[] check;

        String s = br.readLine();
        String[] arr = s.split(" ");
        N = Integer.parseInt(arr[0]);
        K = Integer.parseInt(arr[1]);
        check = new boolean[N];

        S = new Integer[N];
        s = br.readLine();
        arr = s.split(" ");
        for(int i = 0; i < N; ++i) {
            S[i] = Integer.parseInt(arr[i]);
        }
        Arrays.sort(S);

        T = new Integer[N];
        s = br.readLine();
        arr = s.split(" ");
        for(int i = 0; i < N; ++i) {
            T[i] = Integer.parseInt(arr[i]);
        }
        Arrays.sort(T);

        int a = 0;
        int b = N - 1;

        while((b - a + 1) != (N - K)) {

            int left = -987654321;
            for(int i = 0; i < N; ++i) {
                if (S[i] * T[a] > left)
                    left = S[i] * T[a];
            }

            int right = -987654321;
            for(int i = 0; i < N; ++i) {
                if (S[i] * T[b] > right)
                    right = S[i] * T[b];
            }

            if (left > right) {
                check[a] = true;
                a++;
            }
            else {
                check[b] = true;
                b--;
            }
        }

        for(int i = 0; i < N; ++i) {
            if (check[i]) continue;
            for(int j = 0; j < N; ++j) {
                if (T[i] * S[j] > Max)
                    Max = T[i] * S[j];
            }
        }

        System.out.println(Max);
    }
}