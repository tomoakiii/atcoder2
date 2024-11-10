#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int N;
    cin >> N;
    map<int, ll> x;
    map<int, ll> y;
    struct xyp{
        int x;
        int y;
        ll p;
    };
    vector<xyp> city(N); 

    int tx, ty;
    ll tp;
    for(int i=0; i<N; i++){
        cin >> tx >> ty >> tp;
        x[tx] += tp;
        y[ty] += tp;
        city[i].x = tx;
        city[i].y = ty;
        city[i].p = tp;
    }

    ll maxp = 0;
    ll p = 0;
    for(int i=0; i<N; i++){
        p = x[city[i].x] + y[city[i].y] - city[i].p;
        maxp = max(maxp, p);
    }
    cout << maxp << endl;
    return 0;
}

