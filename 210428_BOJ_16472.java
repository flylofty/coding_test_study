import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] alpha = new int[26];
        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int Max = 0;
        int cnt = 1;
        int a = 0;
        alpha[str.charAt(a) - 'a'] = 1;

        for(int b = 1; b < str.length(); ++b) {

            int idx = str.charAt(b) - 'a';

            if (alpha[idx] == 0)
                cnt++;

            alpha[idx]++;

            if (cnt > N) {
                while(true) {
                    idx = str.charAt(a) - 'a';
                    alpha[idx]--;
                    a++;
                    if (alpha[idx] == 0) {
                        cnt--;
                        break;
                    }
                }
            }

            if (cnt <= N) {
                int len = b - a + 1;
                if (len > Max)
                    Max = len;
            }
        }

        System.out.println(Max);
    }
}