import java.io.*;
import java.util.*;

public class 210505_BOJ_9536 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        
        for(int t = 0; t < T; ++t) {

            String s = br.readLine();
            String[] sounds = s.split(" ");

            Map<String, String> animal = new HashMap<>();

            String c;
            String[] cries;
            while (true) {

                c = br.readLine();
                cries = c.split(" ");

                if (cries.length > 3)
                    break;

                animal.put(cries[2], cries[0]);
            }

            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < sounds.length; ++i) {

                if (animal.containsKey(sounds[i]))
                    continue;

                sb.append(sounds[i]).append(" ");
            }
            System.out.println(sb);
        }
    }
}