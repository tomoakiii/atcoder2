#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    vector<int> g(101);
    for(int i=L1; i<=R1; i++) g[i]++;
    for(int i=L2; i<=R2; i++) g[i]++;
    ll len = 0;
    rep(i,101) if(g[i]==2) len++;
    cout << max((ll)0, len-1) << endl;
    return 0;
}