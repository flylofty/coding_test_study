import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] group = new int[300001];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= N; ++i)
            group[i] = i;

        for(int i = 0; i < N - 2; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            isSameGroup(a, b);
        }

        for(int i = 1; i < N; ++i) {
            if (!isSameGroup(i, i + 1)) {
                System.out.print(i + " ");
                System.out.println(i + 1);
                break;
            }
        }
    }

    static int find(int a) {
        if (group[a] == a) return a;
        else return group[a] = find(group[a]);
    }

    static boolean isSameGroup(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return true;

        group[b] = a;
        return false;
    }
}