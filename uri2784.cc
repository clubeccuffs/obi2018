#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


struct G {
    int N;
    typedef pair<int, int> ii;
    vector<vector<ii>> adj;
    vector<int> dst;

    G(int n): N(n), adj(n) {}

    void add_edge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    void reset() {
    }


    void dijkstra(int o) {
        priority_queue<ii, vector<ii>, greater<ii> > q;
        dst.assign(N, numeric_limits<int>::max());
        dst[o] = 0;
        q.push({0, o});

        while(!q.empty()) {
            auto [c, u] = q.top(); q.pop();
            //printf("\nworking c=%d u=%d\n", c, u);

            for(auto [v, w] : adj[u]) {
                //printf("edge %d -> %d : %d\n", u, v, w);
                int nc = c+w;
                if(nc < dst[v]) {
                    //printf("relaxing %d + %d = %d   %d\n", c, w, nc, dst[v]);
                    dst[v] = nc;
                    q.push({nc, v});
                    //printf("qsize: %d\n", q.size());
                }
            }

        }

        //for(int x : dst) { cout << x << ' '; }
        //cout << '\n';
    }
};

int main() {

    int N, M;
    cin >> N >> M;

    G g(N);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u-1, v-1, w);
    }

    int S;
    cin >> S;

    int mi = 0;
    int li = numeric_limits<int>::max();
    g.dijkstra(S-1);
    
    /*
    for(int u = 0; u < N; ++u) {
        for(auto [v, w] : g.adj[u]) {
            printf("%d -> %d : %d\n", u, v, w);
        }
        printf("dst[%d] = %d\n\n", u, g.dst[u]);
    }
    */

    for(int u = 0; u < N; ++u) {
        if(u+1 != S) {
            mi = max(mi, g.dst[u]);
            li = min(li, g.dst[u]);
        }
    }
    cout << (mi - li) << '\n';
}

