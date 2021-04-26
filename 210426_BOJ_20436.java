import java.io.*;

import static java.lang.Math.*;

public class Main {

    static II[] kp = new II[26]; // keyPosition
    static II[] L = new II[101];
    static II[] R = new II[101];
    static int l = 0, r = 0;

    public static void main(String[] args) throws IOException {
        Init();
        input();
        output();
    }

    private static void output() {
        int Min = 0;
        for(int i = 0; i < l - 1; ++i)
            Min += abs(L[i].x - L[i+1].x) + abs(L[i].y - L[i+1].y) + 1;
        for(int i = 0; i < r - 1; ++i)
            Min += abs(R[i].x - R[i+1].x) + abs(R[i].y - R[i+1].y) + 1;
        System.out.println(Min);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String[] chars = s.split(" ");
        for(int i = 0; i < 2; ++i)
            findPosition(chars[i].charAt(0));
        s = br.readLine();
        for(int i = 0; i < s.length(); ++i)
            findPosition(s.charAt(i));
    }

    private static void findPosition(char ch) {
        if (ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'p' || ch == 'h' || ch == 'j' ||
                ch == 'k' || ch == 'l' || ch == 'b' || ch == 'n' || ch == 'm')
            R[r++] = new II(kp[ch - 'a'].x, kp[ch - 'a'].y);
        else
            L[l++] = new II(kp[ch - 'a'].x, kp[ch - 'a'].y);
    }

    static class II {
        int x, y;
        public II(int x, int y){this.x = x;this.y = y;}
    }
    private static void Init() {
        String[] k = new String[3];
        k[0] = "qwertyuiop";
        k[1] = "asdfghjkl";
        k[2] = "zxcvbnm";
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < k[i].length(); ++j) {
                kp[k[i].charAt(j) - 'a'] = new II(i, j);
            }
        }
    }
}