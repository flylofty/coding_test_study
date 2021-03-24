  
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            String st = br.readLine();

            if (st.equals("\n"))
                break;

            String[] arr = st.split(" ");
            String s = arr[0];
            String t = arr[1];

            int a = 0, b = 0;
            for(; b < t.length() && a < s.length(); ++b) {
                if (s.charAt(a) == t.charAt(b))
                    a++;
            }

            if (a == s.length())
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}