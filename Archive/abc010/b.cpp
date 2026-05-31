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
    ll N;
    cin >> N;
    vector<ll> A(N);
    int X[2] = {0, 1};
    int Y[3] = {0, 1, 0};

    set<int> NGs;
    rep(k,100) {
        if(X[k%2] || Y[k%3]) NGs.insert(k+1);
    }
    int ans = 0;
    rep(i,N) {
        ll a; cin>>a;
        while(NGs.contains(a)){
            ans++;
            a--;
        }
    }
    cout << ans << endl;
    return 0;
}