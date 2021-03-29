import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj_17471 {

    static final int INF = 987654321;
    static int N;
    static int Min = INF;
    static int[] p;
    static int[][] e;
    static boolean[] connectionInfo;
    static int target;
    static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        target = N / 2;

        p = new int[N];
        String s = br.readLine();
        String[] arr = s.split(" ");
        for(int i = 0; i < N; ++i) {
            p[i] = Integer.parseInt(arr[i]);
        }

        e = new int[N][];
        for(int i = 0; i < N; ++i) {
            s = br.readLine();
            arr = s.split(" ");
            int m = Integer.parseInt(arr[0]);
            e[i] = new int[m];
            for(int j = 1; j <= m; ++j) {
                e[i][j - 1] = Integer.parseInt(arr[j]) - 1;
            }
        }

        boolean[] t = new boolean[N];
        findAnswer(t, 0);

        if (Min < INF)
            System.out.println(Min);
        else
            System.out.println(-1);
    }

    static boolean isConnected(int start) {

        int cnt = 0;
        boolean[] check = new boolean[N];
        q.add(start);
        check[start] = true;

        while (!q.isEmpty()) {

            int x = q.poll();

            if (connectionInfo[start] == connectionInfo[x])
                cnt++;

            for(int i = 0; i < e[x].length; ++i) {

                int y = e[x][i];

                if (!check[y] && connectionInfo[x] == connectionInfo[y]) {
                    q.add(y);
                    check[y] = true;
                }
            }
        }

        int realCnt = 0;
        for(int i = 0; i < N; ++i) {
            if (connectionInfo[start] == connectionInfo[i])
                realCnt++;
        }

        q.clear();
        return realCnt == cnt;
    }

    static void findAnswer(boolean[] t, int cnt) {

        if (0 < cnt && cnt <= target) {

            int firstFalse = 0;
            while(t[firstFalse])
                firstFalse++;

            int firstTrue = 0;
            while(!t[firstTrue])
                firstTrue++;

            connectionInfo = t;

            if (isConnected(firstFalse) && isConnected(firstTrue)) {
                int a = 0, b = 0;
                for(int i = 0; i < N; ++i) {
                    if (t[i]) {
                        a += p[i];
                    }
                    else {
                        b += p[i];
                    }
                }
                Min = Math.min(Min, Math.abs(a - b));
            }

            if (cnt == target)
                return;
        }

        for(int i = 0; i < N; ++i) {

            if (t[i]) continue;

            t[i] = true;
            findAnswer(t, cnt + 1);
            t[i] = false;
        }
    }
}