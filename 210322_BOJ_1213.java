import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] arr = br.readLine().toCharArray();

        int[] alpha = new int[26];

        for (char c : arr) {
            alpha[c - 'A']++;
        }

        int cnt = 0;
        StringBuilder mid = new StringBuilder();
        for(int i = 0; i < 26; ++i) {
            if (alpha[i] % 2 == 0)
                continue;

            mid.append((char)('A' + i));
            alpha[i]--;
            cnt++;
        }

        StringBuilder head = new StringBuilder();
        for(int i = 0; i < 26; ++i) {
            int Max = alpha[i] / 2;

            for(int j = 0; j < Max; ++j) {
                head.append((char)('A' + i));
                alpha[i]--;
            }
        }

        StringBuilder tail = new StringBuilder();
        for(int i = 25; i >= 0; --i) {
            while(alpha[i] > 0) {
                tail.append((char)('A' + i));
                alpha[i]--;
            }
        }

        if (cnt >= 2) {
            System.out.println("I'm Sorry Hansoo\n");
        }
        else {
            System.out.print(head);
            System.out.print(mid);
            System.out.println(tail);
        }
    }
}