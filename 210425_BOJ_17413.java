import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        s = s + '#';

        StringBuilder res = new StringBuilder();

        for(int i = 0; i < s.length(); ++i) {

            if (s.charAt(i) == '#')
                break;

            if (s.charAt(i) == '<') {
                int j = i;
                while(true) {
                    res.append(s.charAt(j));

                    if (s.charAt(j) == '>')
                        break;

                    j++;
                }
                i = j;
            }
            else {
                StringBuilder sb = new StringBuilder();
                int j = i;
                while(s.charAt(j) != '<' && s.charAt(j) != ' ' && s.charAt(j) != '#') {
                    sb.append(s.charAt(j));
                    j++;
                }
                res.append(sb.reverse().toString());

                if (s.charAt(j) == ' ')
                    res.append(' ');

                if (s.charAt(j) == '<')
                    j--;

                i = j;
            }
        }

        System.out.println(res);
    }
}