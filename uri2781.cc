#include <iostream>
#include <vector>
using namespace std;


vector<int> in, out;

int main() {

    int N, M;
    cin >> M >> N;

    in.assign(N, 0);
    out.assign(N, 0);


    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> w >> v;
        in[v-1] += w;
        out[u-1] +=w;
    }

    bool b = false;

    int tot = 0;
    for(int i= 0; i < N; ++i) {
        //printf("in[%d]=%d out[%d]=%d\n", i+1, in[i], i+1, out[i]);

        if(in[i] != 0 && out[i] != 0) {
            b = true;
        }
        tot += max(out[i] - in[i], 0);
    }

    cout << (b ? "S" : "N") << '\n';
    cout << tot << '\n';

    return 0;
}

