import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node {
    int v, c;

    public Node(int v, int c) {
        this.v = v;
        this.c = c;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();


        for (int tc = 1; tc <= t; tc++) {
            System.out.println("Case " + tc + ":");

            int n = sc.nextInt();
            int[] busy = new int[n];
            ArrayList<ArrayList<Integer>> roads = new ArrayList<>();
            int[] dist = new int[n];
            int MAX = 10000000;

            for (int i = 0; i < n; ++i) {
                busy[i] = sc.nextInt();

                ArrayList<Integer> edges = new ArrayList<>();
                roads.add(edges);
                dist[i] = MAX;
            }

            int m = sc.nextInt();
            for (int i = 0; i < m; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;

                roads.get(u).add(v);
            }

            Comparator<Node> comparator = (Node u, Node v) -> Integer.compare(v.c, u.c);
            PriorityQueue<Node> pq = new PriorityQueue<>(comparator);

            pq.add(new Node(0, 0));
            dist[0] = 0;

            while (!pq.isEmpty()) {
                Node u = pq.poll();

//                System.out.println(u.v + " " + u.c);

                for (Integer v : roads.get(u.v)) {
                    int cost = (busy[v] - busy[u.v]) * (busy[v] - busy[u.v]) * (busy[v] - busy[u.v]) + dist[u.v];
                    if (cost < dist[v] && cost > -1000) {
                        pq.add(new Node(v, cost));
                        dist[v] = cost;
                    }
                }
            }

            int q = sc.nextInt();
            while (q-- > 0) {
                int v = sc.nextInt() - 1;
                if (dist[v] < 3 || dist[v] == MAX) {
                    System.out.println("?");
                } else {
                    System.out.println(dist[v]);
                }
            }
        }
    }
}