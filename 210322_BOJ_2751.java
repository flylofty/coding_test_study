import java.io.*;

public class boj_2751 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        boolean[] po = new boolean[1000001];
        boolean[] ne = new boolean[1000001];

        for(int i = 0; i < N; i++) {
            int index = Integer.parseInt(br.readLine());

            if (index >= 0)
                po[index] = true;
            else
                ne[index * -1] = true;
        }

        for(int i = 1000000; i >= 1; --i) {
            if (ne[i])
                sb.append((i * -1)).append('\n');
        }

        for(int i = 0; i <= 1000000; ++i) {
            if (po[i])
                sb.append((i)).append('\n');
        }

        System.out.println(sb);
    }
}
