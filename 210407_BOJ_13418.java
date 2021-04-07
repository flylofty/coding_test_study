import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int entrance;
    static int[] group;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[][] edge, edge2; // 최악, 최선

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < 3; ++i)
            entrance = Integer.parseInt(st.nextToken());

        edge = new int[M][3];
        edge2 = new int[M][3];

        // 0 오르막, 1 내리막
        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            int a, b, c;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            edge[i][1] = edge2[i][1] = a;
            edge[i][2] = edge2[i][2] = b;

            // 오르막일 경우
            if (c == 0) {
                edge[i][0] = 1;
                edge2[i][0] = 2;
            } // 내리막일 경우
            else {
                edge[i][0] = 2;
                edge2[i][0] = 1;
            }
        }

        arraySort(edge);
        arraySort(edge2);

        int Max = Kruskal(edge, 1);
        int Min = Kruskal(edge2, 2);

        if (entrance == 0) {
            Max++;
            Min++;
        }

        System.out.println(Max * Max - Min * Min);
    }

    static void arraySort(int[][] arr) {
        Arrays.sort(arr, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
    }

    static int Kruskal(int[][] edge, int choice) {
        int cnt = 0;

        // 초기화
        group = new int[N + 1];
        for(int i = 1; i <= N; ++i)
            group[i] = i;

        for(int i = 0; i < edge.length; ++i) {
            int a = edge[i][1];
            int b = edge[i][2];

            if (!isSameGroup(a, b)) {
                if (edge[i][0] == choice)
                    cnt++;
            }
        }

        return cnt;
    }

    static boolean isSameGroup(int a, int b) {

        a = find(a);
        b = find(b);

        if (a == b)
            return true;

        group[b] = a;
        return false;
    }

    static int find(int a) {
        if (group[a] == a) return a;
        else return group[a] = find(group[a]);
    }
}