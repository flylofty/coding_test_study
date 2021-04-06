import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static int N;
    static ArrayList<Integer> al = new ArrayList<Integer>();
    static boolean[] visit = new boolean[8];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        findAnswer();
        System.out.println(sb);
    }

    public static void findAnswer() {

        if (al.size() == N) {

            for (Integer num : al) {
                sb.append(num + 1).append(" ");
            }
            sb.append("\n");

            return;
        }

        for(int i = 0; i < N; ++i) {
            if (visit[i])
                continue;

            visit[i] = true;
            al.add(i);
            findAnswer();
            al.remove(al.size() - 1);
            visit[i] = false;
        }
    }
}