import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        int num = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == ' ') continue;
            num = num * 10 + (s.charAt(i) - '0');
        }

        int Min = num;
        for(int j = 0; j < 3; ++j) {

            num = (num % 1000) * 10 + (num / 1000);

            if (Min > num)
                Min = num;
        }

        num = Min;

        int cnt = 0;
        boolean[] check = new boolean[10000];
        for(int i = 1111; i < 10000; ++i) {
            int temp = i;

            boolean isClockNumber = true;
            Min = temp;
            for(int j = 0; j < 3; ++j) {

                temp = (temp % 1000) * 10 + (temp / 1000);

                if (temp < 1000) {
                    isClockNumber = false;
                    break;
                }

                if (Min > temp)
                    Min = temp;
            }

            if (!isClockNumber || check[Min])
                continue;

            check[Min] = true;
            cnt++;

            if (Min == num)
                break;
        }

        System.out.println(cnt);
    }
}