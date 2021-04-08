import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static String leftPattern;
    static String rightPattern;
    static int a;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        rightPattern = br.readLine();
        while(rightPattern.charAt(a) != '*') a++;
        leftPattern = rightPattern.substring(0, a);
        rightPattern = rightPattern.substring(a + 1, rightPattern.length());

        for(int i = 0; i < N; ++i) {
            String right = br.readLine();

            if (right.length() < leftPattern.length() + rightPattern.length()) {
                System.out.println("NE");
                continue;
            }

            String left = right.substring(0, leftPattern.length());
            right = right.substring(right.length() - rightPattern.length());

            if (leftPattern.equals(left) && rightPattern.equals(right))
                System.out.println("DA");
            else
                System.out.println("NE");
        }
    }
}