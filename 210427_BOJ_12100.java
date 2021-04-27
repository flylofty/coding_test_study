import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] board = new int[20][20];
    static int[] command = new int[5];
    static int N, Max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; ++j) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        findAnswer(0);
        System.out.println(Max);
    }

    static void findAnswer(int cnt) {

        if (cnt == 5) {
            // init Map
            Integer[][] t = new Integer[N][N];
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    t[i][j] = board[i][j];
                }
            }

            // move
            for(int i = 0; i < 5; ++i) {
                if (command[i] == 0)
                    moveUp(t);
                else if (command[i] == 1)
                    moveRight(t);
                else if (command[i] == 2)
                    moveDown(t);
                else
                    moveLeft(t);
            }

            // find Max
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if (t[i][j] > Max)
                        Max = t[i][j];
                }
            }

            return;
        }

        for(int i = 0; i < 4; ++i) {
            command[cnt] = i;
            findAnswer(cnt + 1);
        }
    }

    static void moveLeft(Integer[][] t) {

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                // 오른편에 같은 수를 찾는다
                boolean isExist = true;
                int k = j + 1;
                for(; k < N; ++k) {

                    if (t[i][k] == 0)
                        continue;

                    if (!t[i][j].equals(t[i][k]))
                        isExist = false;

                    break;
                }
                // 같은 수가 있으면 더한다
                if (isExist && k < N) {
                    t[i][j] *= 2;
                    t[i][k] = 0;
                }

                // 최대한 왼편으로 밀어낸다
                int col = j - 1;
                while (col >= 0 && t[i][col] == 0) {
                    t[i][col] = t[i][col + 1];
                    t[i][col + 1] = 0;
                    col--;
                }
            }
        }
    }

    static void moveRight(Integer[][] t) {

        for(int i = 0; i < N; ++i) {
            for(int j = N - 1; j >= 0; --j) {
                // 왼편에 같은 수를 찾는다.
                boolean isExist = true;
                int k = j - 1;
                for(; k >= 0; --k) {

                    if (t[i][k] == 0)
                        continue;

                    if (!t[i][j].equals(t[i][k]))
                        isExist = false;

                    break;
                }

                // 같은 수가 있으면 더한다
                if (isExist && k >= 0) {
                    t[i][j] *= 2;
                    t[i][k] = 0;
                }

                // 최대한 오른편으로 밀어낸다
                int col = j + 1;
                while(col < N && t[i][col] == 0) {
                    t[i][col] = t[i][col - 1];
                    t[i][col - 1] = 0;
                    col++;
                }
            }
        }
    }

    static void moveUp(Integer[][] t) {

        for(int j = 0; j < N; ++j) {
            for(int i = 0; i < N; ++i) {

                if (t[i][j] == 0)
                    continue;

                // 아래로 같은 수가 있는지 찾는다
                boolean isExist = true;
                int k = i + 1;
                for(; k < N; ++k) {

                    if (t[k][j] == 0)
                        continue;

                    if (!t[i][j].equals(t[k][j]))
                        isExist = false;

                    break;
                }

                // 같은 수가 있다면 더한다
                if (isExist && k < N) {
                    t[i][j] *= 2;
                    t[k][j] = 0;
                }

                // 최대한 위로 밀어낸다
                int low = i - 1;
                while(low >= 0 && t[low][j] == 0) {
                    t[low][j] = t[low + 1][j];
                    t[low + 1][j] = 0;
                    low--;
                }
            }
        }
    }

    static void moveDown(Integer[][] t) {

        for(int j = 0; j < N; ++j) {
            for(int i = N - 1; i >= 0; --i) {

                if (t[i][j] == 0)
                    continue;

                // 위로 같은 수가 있는지 찾는다
                boolean isExist = true;
                int k = i - 1;
                for(; k >= 0; --k) {

                    if (t[k][j] == 0)
                        continue;

                    if (!t[i][j].equals(t[k][j]))
                        isExist = false;

                    break;
                }

                // 같은 수가 있다면 더한다
                if (isExist && k >= 0) {
                    t[i][j] *= 2;
                    t[k][j] = 0;
                }

                // 최대한 아래로 밀어낸다
                int low = i + 1;
                while (low < N && t[low][j] == 0) {
                    t[low][j] = t[low - 1][j];
                    t[low - 1][j] = 0;
                    low++;
                }
            }
        }
    }
}