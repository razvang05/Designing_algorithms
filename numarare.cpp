#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    static constexpr int NMAX = 100005;
    static constexpr int MOD = 1000000007;

    int n, m;
    vector<int> adj1[NMAX];
    vector<unordered_set<int>> adj2;
    vector<int> indegree;
    // citesc datele de intrare
    // stochez in 2 vectori cele 2 grafuri
    void read_input() {
        ifstream fin("numarare.in");
        fin >> n >> m;
        int x, y;
        adj2.resize(n+1);
        for (int i = 1; i <= m; i++) {
            fin >> x >> y;
            adj1[x].push_back(y);
        }
        for (int i = 1; i <= m; i++) {
            fin >> x >> y;
            adj2[x].insert(y);
        }
        fin.close();
    }

    int get_result() {
        vector<int> topsort = topological_sort();
        return compute_paths(topsort);
    }
    // sortare topologica
    vector<int> topological_sort() {
        queue<int> q;
        vector<int> topsort;
        vector<int> indegree(n+1, 0);
        // pentru fiecare nod ii parcurg vecinii
        // si incrementez gradul intern al vecinilor
        for (int i = 1; i <= n; i++) {
            for (auto neigh : adj1[i]) {
                indegree[neigh]++;
            }
        }
        // dupa aceea pun in coada nodurile care au gradul intern 0
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // extrag pe rand elementele din coada
        // si le adaug in vectorul topsort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topsort.push_back(node);
            // parcurg vecinii nodului curent si decrementez gradul intern
            for (int neighbor : adj1[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return topsort;
    }

    int compute_paths(const vector<int>& topsort) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        // ieterez prin fiecare nod din vectorul topologic
        // si verific daca arcele curente sunt comune
        for (int node : topsort) {
            for (int neighbor : adj1[node]) {
                if (adj2[node].find(neighbor) != adj2[node].end()) {
                    // adaug la neighbor numarul de cai ajung la node
                    // arcul fiind valid si poate fi extins pana la neighbor
                    dp[neighbor] = (dp[neighbor] + dp[node]) % MOD;
                }
            }
        }
        // numarul total de cai de la sursa la destinatie
        return dp[n];
    }

    void print_output(int result) {
        ofstream fout("numarare.out");
        fout << result << '\n';
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
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
