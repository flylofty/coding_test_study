import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        char[] s = new char[N];
        for(int i = 0; i < N; ++i) s[i] = '0';

        String temp = br.readLine();
        char[] memo = new char[N];
        int index = 0;
        for(int i = 0; i < temp.length(); ++i) {
            if (temp.charAt(i) == ' ')
                continue;

            memo[index++] = temp.charAt(i);
        }

        int cnt = 0;
        index = 0;
        while(index < N) {

            if (s[index] != memo[index]) {
                s[index] = theOther(s[index]);

                if (index + 1 < N) {
                    s[index + 1] = theOther(s[index + 1]);
                }

                if (index + 2 < N) {
                    s[index + 2] = theOther(s[index + 2]);
                }

                cnt++;
            }
            
            // 시간 초과 날 수 있음.
            // if (String.valueOf(s).equals(String.valueOf(memo)))
            //     break;

            index++;
        }

        System.out.println(cnt);
    }

    public static char theOther(char ch) {
        if (ch == '0')
            return '1';
        else
            return '0';
    }
}