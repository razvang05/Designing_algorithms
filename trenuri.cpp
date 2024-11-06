#include <bits/stdc++.h>

using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    // stochez nodul sub forma de string
    unordered_map<string, vector<string>> adj;
    string start, end;

    void read_input() {
        ifstream fin("trenuri.in");
        int m;
        fin >> start >> end >> m;

        string x, y;
        for (int i = 0; i < m; i++) {
            fin >> x >> y;
            adj[x].push_back(y);
        }
        fin.close();
    }
    // sortare topologica
    // parcurg toti vecinii nodului curent si incrementez gradul intern
    vector<string> topological_sort() {
        unordered_map<string, int> indegree;
        for (auto& pair : adj) {
            for (const string& neighbor : pair.second) {
                indegree[neighbor]++;
            }
        }

        queue<string> q;
        vector<string> topoSort;
        // adaug in coada nodurile cu gradul 0
        for (auto& pair : adj) {
            if (indegree[pair.first] == 0) {
                q.push(pair.first);
            }
        }

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            topoSort.push_back(node);
            // adaug in vectorul topologic nodurile cand au gradul intern 0
            for (const string& neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topoSort;
    }

    int get_result() {
        vector<string> topoSort = topological_sort();
        unordered_map<string, int> dist;
        // distanta de la nodul start
        dist[start] = 1;

        for (const string& node : topoSort) {
            // daca nodul a fost vizitat
            if (dist[node] > 0) {
                // pentru fiecare vecin al nodului curent actualizez distanta
                // maxima la el daca calea prin nodul curent este mai lunga
                for (const string& neighbor : adj[node]) {
                    if (dist[neighbor] < dist[node] + 1) {
                        dist[neighbor] = dist[node] + 1;
                    }
                }
            }
        }

        return dist[end];
    }

    void print_output(int result) {
        ofstream fout("trenuri.out");
        fout << result;
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
