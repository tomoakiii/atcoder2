#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
    int N;
    cin >> N;
    double sm = 0;
    vector<ll> X(5*N);
    rep(i, 5*N)        cin >> X[i];
    sort(X.begin(), X.end());
    for(int i=N ; i<4*N; i++)  sm+=X[i];
    cout << setprecision(24) << sm/(3*N) << endl;
    return 0;
}