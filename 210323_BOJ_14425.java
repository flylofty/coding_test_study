import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M;
        String s = br.readLine();
        String[] a = s.split(" ");
        N = Integer.parseInt(a[0]);
        M = Integer.parseInt(a[1]);

        String temp;
        HashSet<String> strings = new HashSet<>();

        for(int i = 0; i < N; ++i) {
            temp = br.readLine();
            strings.add(temp);
        }

        int cnt = 0;
        for(int i = 0; i < M; ++i) {
            temp = br.readLine();

            if (strings.contains(temp))
                cnt++;
        }

        System.out.println(cnt);
    }
}