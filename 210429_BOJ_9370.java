import java.io.*;
import java.util.*;

public class Boj_9370 {

    static class II implements Comparable<II> {
        public int x, d;
        public II(int x, int d){this.x = x;this.d = d;}
        @Override public int compareTo(II o) {return this.d <= o.d ? 1 : -1;}
    }

    static II[][] edge = new II[2001][2001];
    static int[] nmt = new int[3];
    static int[] sgh = new int[3];
    static int[] candidate = new int[101];
    static int[] D = new int[2001];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while((T--) > 0) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 3; ++i)
                nmt[i] = Integer.parseInt(st.nextToken());

            for(int i = 1; i < nmt[0] + 1; ++i)
                edge[i][0] = new II(1, 0);

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 3; ++i)
                sgh[i] = Integer.parseInt(st.nextToken());

            for(int i = 0; i < nmt[1]; ++i) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());

                int idx = edge[a][0].x++;
                edge[a][idx] = new II(b, d);
                idx = edge[b][0].x++;
                edge[b][idx] = new II(a, d);
            }

            for(int i = 0; i < nmt[2]; ++i)
                candidate[i] = Integer.parseInt(br.readLine());

            Arrays.sort(candidate, 0, nmt[2]);

            dijkstra();
        }

        System.out.println(sb);
    }

    static void dijkstra() {

        for(int i = 1; i <= nmt[0]; ++i)
            D[i] = Integer.MAX_VALUE;
        D[sgh[0]] = 0;

        PriorityQueue<II> q = new PriorityQueue<>();
        q.add(new II(sgh[0], 0));

        int[] visit = new int[nmt[0] + 1];

        while(!q.isEmpty()) {

            II from = q.poll();

            for(int i = 1; i < edge[from.x][0].x; ++i) {
                int to = edge[from.x][i].x;
                int d = edge[from.x][i].d + from.d;

                if (D[to] >= d) {
                    D[to] = d;
                    q.add(new II(to, d));
                    visit[to] = from.x;
                }
            }
        }

        for(int i = 0; i < nmt[2]; ++i) {
            if (findAnswer(candidate[i], visit))
                sb.append(candidate[i]).append(" ");
        }
        sb.append("\n");
    }

    static boolean findAnswer(int end, int[] visit) {

        boolean isVisited = false;
        int idx = end;

        while(idx > 0) {
            int idx2 = visit[idx];

            if (idx + idx2 == sgh[1] + sgh[2])
                isVisited = true;

            idx = idx2;
        }

        return idx == 0 && isVisited;
    }
}