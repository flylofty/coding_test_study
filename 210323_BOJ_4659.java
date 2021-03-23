import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String res = "is acceptable.";
        String res2 = "is not acceptable.";

        while (true) {
            String s = br.readLine();

            if (s.equals("end"))
                break;

            // 모음체크
            int i = 0;
            for(; i < s.length(); ++i) {
                if (isVowel(s.charAt(i)))
                    break;
            }

            // 모음 자음 3연속 체크
            int j = 0;
            for(; j < s.length() - 2; ++j) {
                if (isVowel(s.charAt(j)) && isVowel(s.charAt(j + 1)) && isVowel(s.charAt(j + 2)))
                    break;
                if (!isVowel(s.charAt(j)) && !isVowel(s.charAt(j + 1)) && !isVowel(s.charAt(j + 2)))
                    break;
            }

            int k = 0;
            for(; k < s.length() - 1; ++k) {
                if (s.charAt(k) == 'e' || s.charAt(k) == 'o')
                    continue;
                if (s.charAt(k) == s.charAt(k + 1))
                    break;
            }

            if (i == s.length() || j < s.length() - 2 || k < s.length() - 1)
                System.out.println("<" + s + "> " + res2);
            else
                System.out.println("<" + s + "> " + res);
        }
    }

    public static boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
}