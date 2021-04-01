import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Boj_5052_02 {

    static String[] strings;

    static class Tri {
        Tri[] child;

        public Tri() {
            child = new Tri[10];
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while ((t--) > 0) {

            int n = Integer.parseInt(br.readLine());
            String[] s = new String[n];
            for(int i = 0; i < n; ++i) {
                s[i] = br.readLine();
            }
            Arrays.sort(s, Comparator.comparing(String::length));

            strings = s;

            Tri root = new Tri();

            int cnt = 0;
            boolean isCorrect = true;
            for(int i = s.length - 1; i >= 0; --i) {
                Tri find = root;
                cnt = 0;
                for(int j = 0; j < s[i].length(); ++j) {
                    int index = s[i].charAt(j) - '0';

                    if (find.child[index] == null) {
                        find.child[index] = new Tri();
                        cnt--;
                    }

                    find = find.child[index];
                    cnt++;
                }

                if (s[i].length() == cnt) {
                    isCorrect = false;
                    break;
                }
            }

            if (isCorrect)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}