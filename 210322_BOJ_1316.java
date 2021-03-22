import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int res = 0;
        for(int i = 0; i < N; ++i) {
            String s = br.readLine();

            s += '#';

            HashSet<Character> set = new HashSet<>();
            int j = 0;
            for(; j < s.length() - 1; ++j) {

                Character a = s.charAt(j);
                Character b = s.charAt(j + 1);

                if (!a.equals(b)) {
                    if (set.contains(a)) {
                        break;
                    }
                    else {
                        set.add(a);
                    }
                }
            }

            if (j == s.length() - 1)
                res++;
        }

        System.out.println(res);
    }
}