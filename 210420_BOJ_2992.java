import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] number = new int[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int X = Integer.parseInt(br.readLine());
        int temp = X;

        while(temp > 0) {
            number[temp % 10]++;
            temp = temp / 10;
        }

        for(int i = X + 1; i < 1000000; ++i) {

            if (isSame(i)) {
                System.out.println(i);
                return;
            }
        }

        System.out.println(0);
    }

    private static boolean isSame(int num) {

        int[] number2 = new int[10];

        while(num > 0) {
            number2[num % 10]++;
            num = num / 10;
        }

        for(int i = 0; i < 10; ++i) {

            if (number[i] != number2[i]) {
                return false;
            }
        }

        return true;
    }
}
