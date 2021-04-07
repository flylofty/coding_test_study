import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Boj_18352 {

    static HashMap<Integer, ArrayList<Integer>> hm = new HashMap<>();
    static Queue<Integer> q = new ArrayDeque<>();
    static StringBuilder sb = new StringBuilder();
    static int N, M, K, X;
    static int[] D;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; ++i)
            hm.put(i, new ArrayList<>());

        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            hm.get(a).add(b);
        }

        Dijkstra();

        if (sb.length() == 0)
            System.out.println("-1");
        else
            System.out.println(sb);
    }

    static void Dijkstra() {
        D = new int[N + 1];
        Arrays.fill(D, 987654321);
        D[X] = 0;
        q.add(X);

        while (!q.isEmpty()) {
            int x = q.poll();

            for(int i = 0; i < hm.get(x).size(); ++i) {

                int y = hm.get(x).get(i);

                if (D[y] > D[x] + 1) {
                    D[y] = D[x] + 1;
                    q.add(y);
                }
            }
        }

        for(int i = 1; i <= N; ++i) {
            if (D[i] == K)
                sb.append(i).append("\n");
        }
    }
}