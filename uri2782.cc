#include <iostream>
#include <vector>
using namespace std;

vector<int> escadinha;
vector<int> ds;

int main() {
    int N;
    cin >> N;
    escadinha.resize(N);
    ds.resize(N);
    for(int & e : escadinha) {
        cin >>e;
    }

    for(int i = 1; i < N; ++i) {
        ds[i] = escadinha[i] - escadinha[i-1];
    }

    int n = 1;
    for(int i = 2; i < N; ++i) {
        if(ds[i]!=ds[i-1]) {
            ++n;
        }
    }

    //for(int d : ds) { cout << d << ' '; } cout << '\n';

    cout << n << '\n';

    return 0;
}
