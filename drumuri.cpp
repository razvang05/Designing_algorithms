#include <bits/stdc++.h>

using namespace std;

#define INF 1e12

class Task {
 public:
    void solve() {
        read_input();
        print_output(find_min());
    }

 private:
    int N, M;
    int x, y, z;
    vector<vector<pair<int, int>>> graph;
    vector<vector<pair<int, int>>> reverse_graph;

    void read_input() {
        ifstream fin("drumuri.in");
        fin >> N >> M;
        graph.resize(N + 1);
        reverse_graph.resize(N + 1);
        int a, b, c;
        for (int i = 0; i < M; ++i) {
            fin >> a >> b >> c;
            graph[a].push_back({b, c});
            reverse_graph[b].push_back({a, c});
        }
        fin >> x >> y >> z;
        fin.close();
    }

    vector<long long> dijkstra(int source,
                                const vector<vector<pair<int, int>>>& adj) {
        vector<long long> dist(N + 1, INF);
        // coada de prioritati
        priority_queue<pair<long long, int>, vector<pair<long long,
                            int>>, greater<pair<long long, int>>> pq;

        dist[source] = 0LL;
        pq.push({0LL, source});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            // parcurg toate muchiile adiacente
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int cost = edge.second;
                // daca gasesc o distanta mai mica
                // o actualizez si o adaug in coada
                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        // nodurile inaccesibile le setez dist pe -1
        for (int node = 1; node <= N; node++) {
            if (dist[node] == INF) {
                dist[node] == -1;
            }
        }

        return dist;
    }

    long long find_min() {
        // Calculăm distanțele minime de la x și y la toate nodurile
        vector<long long> dist_x = dijkstra(x, graph);
        vector<long long> dist_y = dijkstra(y, graph);
        // Calculăm distanțele minime de la z la toate
        // nodurile grafului transpus
        vector<long long> dist_z = dijkstra(z, reverse_graph);


        // parcurg toate nodurile și
        // verificăm dacă fac parte din drumurile minime
        long long ans = INF;
        // parcurgem toate nodurile
        // adica trebuie sa trecem prin acel nod intermediar de la z la i
        // si apoi de la i la x si y
        // adunand distantele minime
        for (int i = 1; i <= N; ++i) {
            if (dist_x[i] != -1 && dist_y[i] != -1
                && dist_z[i] != -1) {
                ans = min(ans, dist_x[i] + dist_y[i] + dist_z[i]);
            }
        }
        return ans;
    }

    void print_output(long long result) {
        ofstream fout("drumuri.out");
        fout << result;
        fout.close();
    }
};


int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
