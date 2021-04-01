import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while ((t--) > 0) {

            int n = Integer.parseInt(br.readLine());
            String[] strings = new String[n];
            for(int i = 0; i < n; ++i) {
                strings[i] = br.readLine();
            }

            Arrays.sort(strings, Comparator.comparing(String::length));

            boolean isCorrect = true;
            for(int i = 0; i < n - 1; ++i) { // O(N^2) ==> 시간 초과
                for(int j = i + 1; j < n; ++j) {

                    if (strings[i].length() == strings[j].length())
                        continue;

                    if (strings[j].substring(0, strings[i].length()).equals(strings[i])) {
                        isCorrect = false;
                        break;
                    }
                }

                if (!isCorrect)
                    break;
            }

            if (isCorrect)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}