import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOj_2470 {

    public static void main(String[] args) throws IOException {

        int[] po = new int[100000];
        int[] ne = new int[100000];
        int p = 0, n = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            int temp = Integer.parseInt(st.nextToken());
            if (temp >= 0) {
                po[p++] = temp;
            }
            else {
                ne[n++] = temp;
            }
        }

        Arrays.sort(po,0, p);
        Arrays.sort(ne,0, n);

        int Min = 2000000001, abs;
        int[] res = new int[2];

        if (p >= 2) {
            abs = Math.abs(po[0] + po[1]);
            if (Min > abs) {
                Min = abs;
                res[0] = po[0];
                res[1] = po[1];
            }
        }

        if (n >= 2) {
            abs = Math.abs(ne[n-2] + po[n-1]);
            if (Min > abs) {
                Min = abs;
                res[0] = ne[n - 2];
                res[1] = ne[n - 1];
            }
        }

        if (p >= 1 && n >= 1) {
            for(int i = 0; i < p; ++i) {

                int index = Arrays.binarySearch(ne, 0, n - 1, -po[i]);
                index = Math.abs(index + 1) - 1;

                for(int j = 0; j < 2; ++j) {
                    int idx = index + j;
                    if (idx < 0 || idx >= n)
                        continue;

                    abs = Math.abs(ne[idx] + po[i]);
                    if (Min > abs) {
                        Min = abs;
                        res[0] = ne[idx];
                        res[1] = po[i];
                    }
                }
            }
        }

        System.out.println(res[0] + " " + res[1]);
    }
}