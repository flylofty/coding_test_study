import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static StringBuilder res = new StringBuilder();
    // 이 방법 좋은 것 같음!!
    static HashMap<Integer, ArrayList<Integer>> edge = new HashMap<>();
    static Queue<Integer> q = new LinkedList<>();
    static boolean[] visit = new boolean[10001];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        String[] input = s.split(" ");
        N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        for(int i = 0; i < M; ++i) {
            s = br.readLine();
            input = s.split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            if (!edge.containsKey(b))
                edge.put(b, new ArrayList<>());
            edge.get(b).add(a);
        }

        int Max = 0;
        for(int i = 1; i <= N; ++i) {
            int cnt = bfs(i);

            if (cnt >= Max) {
                if (cnt > Max) {
                    res.delete(0, res.length());
                    Max = cnt;
                }
                res.append(i).append(" ");
            }
        }
        System.out.println(res);
    }

    static int bfs(int s) {

        for(int i = 1; i <= N; ++i)
            visit[i] = false;

        q.add(s);
        visit[s] = true;
        int cnt = 0;

        while (!q.isEmpty()) {
            int x = q.poll();

            if (!edge.containsKey(x))
                continue;

            for(int y : edge.get(x)) {
                if (!visit[y]) {
                    q.add(y);
                    visit[y] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}