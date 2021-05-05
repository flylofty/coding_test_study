import java.io.*;
import java.util.*;

public class 210505_BOJ_17144 {

    static int N, M, T;
    static int[][] home = new int[51][51];
    static int[][] temp = new int[51][51];
    static int[][] dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static int[][] ap = {{0, 0}, {0, 0}};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        int idx = 0;
        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; ++j) {
                home[i][j] = Integer.parseInt(st.nextToken());

                if (home[i][j] == -1 && idx < 2) {
                    ap[idx][0] = i;
                    ap[idx][1] = j;
                    idx++;
                }
            }
        }

        for(int i = 0; i < T; ++i) {
            spread();
            activateAirPurifier();
        }

        System.out.println(findRemain());
    }

    static void spread() {

        for(int i = 0; i < N; ++i) {

            for(int j = 0; j < M; ++j) {

                if (home[i][j] <= 0)
                    continue;

                int cnt = 0;
                for(int k = 0; k < 4; ++k) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];

                    if (x < 0 || x >= N || y < 0 || y >= M)
                        continue;

                    if (home[x][y] == -1)
                        continue;

                    cnt++;
                    temp[x][y] += home[i][j] / 5;
                }

                home[i][j] = home[i][j] - (home[i][j] / 5) * cnt;
            }
        }

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                home[i][j] += temp[i][j];
                temp[i][j] = 0;
            }
        }
    }

    static void activateAirPurifier() {

        int i = ap[0][0];
        int j = ap[0][1] + 1;
        Deque<Integer> dq = new ArrayDeque<>();

        for(; j < M - 1; ++j)
            dq.addLast(home[i][j]);
        for(; i > 0; --i)
            dq.addLast(home[i][j]);
        for(; j > 0; --j)
            dq.addLast(home[i][j]);
        for(; i < ap[0][0] - 1; ++i)
            dq.addLast(home[i][j]);
        dq.addLast(0);

        dq.addFirst(dq.removeLast());

        i = ap[0][0];
        j = ap[0][1] + 1;

        for(; j < M - 1; ++j)
            home[i][j] = dq.removeFirst();
        for(; i > 0; --i)
            home[i][j] = dq.removeFirst();
        for(; j > 0; --j)
            home[i][j] = dq.removeFirst();
        for(; i < ap[0][0]; ++i)
            home[i][j] = dq.removeFirst();

        i = ap[1][0];
        j = ap[1][1] + 1;

        for(; j < M - 1; ++j)
            dq.addLast(home[i][j]);
        for(; i < N - 1; ++i)
            dq.addLast(home[i][j]);
        for(; j > 0; --j)
            dq.addLast(home[i][j]);
        for(; i > ap[1][0] + 1; --i)
            dq.addLast(home[i][j]);
        dq.addLast(0);

        dq.addFirst(dq.removeLast());

        i = ap[1][0];
        j = ap[1][1] + 1;

        for(; j < M - 1; ++j)
            home[i][j] = dq.removeFirst();
        for(; i < N - 1; ++i)
            home[i][j] = dq.removeFirst();
        for(; j > 0; --j)
            home[i][j] = dq.removeFirst();
        for(; i > ap[1][0]; --i)
            home[i][j] = dq.removeFirst();
    }

    static int findRemain() {

        int sum = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if (home[i][j] == -1)
                    continue;
                sum += home[i][j];
            }
        }
        return sum;
    }
}