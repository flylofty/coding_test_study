import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {

    static class II {
        int x;
        int y;

        public II(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class IC {
        int s;
        char d;

        public IC(int s, char d) {
            this.s = s;
            this.d = d;
        }
    }

    public static void main(String[] args) throws IOException {

        int N = 0;
        int m = 0;
        int L = 0;
        boolean[][] isApple = new boolean[101][101];
        IC[] order = new IC[101];
        int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        m = Integer.parseInt(br.readLine());
        for(int i = 0; i < m; ++i) {
            String c = br.readLine();
            String[] arr = c.split(" ");
            isApple[Integer.parseInt(arr[0])][Integer.parseInt(arr[1])] = true;
        }

        L = Integer.parseInt(br.readLine());
        for(int i = 0; i < L; ++i) {
            String c = br.readLine();
            String[] arr = c.split(" ");
            order[i] = new IC(Integer.parseInt(arr[0]), arr[1].charAt(0));
        }
        order[L] = new IC(0, 'N');

        ArrayDeque<II> dq = new ArrayDeque<>();
        dq.offerLast(new II(1, 1));

        int oIndex = 0;
        int x = 1;
        int y = 1;
        int head = 1;
        int seconds = 1;
        while(true) {

            int px = x + dir[head][0];
            int py = y + dir[head][1];

            if (px <= 0 || px > N || py <= 0 || py > N)
                break;

            boolean isSnakeBody = false;
            for (II p : dq) {
                if (p.x == px && p.y == py) {
                    isSnakeBody = true;
                    break;
                }
            }

            if (isSnakeBody)
                break;

            x = px;
            y = py;

            dq.offerFirst(new II(x, y));
            if (isApple[x][y]) {
                isApple[x][y] = false;
            }
            else {
                dq.pollLast();
            }

            if (order[oIndex].s == seconds) {
                if (order[oIndex].d == 'L') {
                    head--;
                    if (head == -1)
                        head = 3;
                    head = head % 4;
                }
                else if (order[oIndex].d == 'D') {
                    head = (head + 1) % 4;
                }
                oIndex++;
            }

            seconds++;
        }

        System.out.println(seconds);
    }
}