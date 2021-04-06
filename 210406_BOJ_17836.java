import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;
import static java.lang.Math.*;

public class Main {

    static class II {
        int x, y;
        public II(int x, int y) {
            this.x = x;this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {

        final int INF = 987654321;
        final int WALL = 1;
        int N, M, T, Min = INF;
        int[][] castle = new int[101][101];
        int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        boolean[][] visit = new boolean[101][101];
        int[][] dist = new int[101][101];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; ++j) {
                castle[i][j] = Integer.parseInt(st.nextToken());
                dist[i][j] = INF;
            }
        }

        Queue<II> q = new ArrayDeque<>();
        q.add(new II(0, 0));
        dist[0][0] = 0;
        visit[0][0] = true;

        while(!q.isEmpty()) {
            II a = q.poll();

            if (castle[a.x][a.y] == 2)
                dist[N - 1][M - 1] = min(dist[N - 1][M - 1] ,(N - 1 - a.x + M - 1 - a.y) + dist[a.x][a.y]);

            for(int i = 0; i < 4; ++i) {
                int x = a.x + dir[i][0];
                int y = a.y + dir[i][1];

                if (x < 0 || x >= N || y < 0 || y >= M)
                    continue;

                if (castle[x][y] == WALL || visit[x][y])
                    continue;

                q.add(new II(x, y));
                dist[x][y] = min(dist[x][y], dist[a.x][a.y] + 1);
                visit[x][y] = true;
            }
        }

        if (dist[N - 1][M - 1] > T)
            System.out.println("Fail");
        else
            System.out.println(dist[N - 1][M - 1]);
    }
}