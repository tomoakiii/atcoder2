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
ll cmb(ll a){
    ll c = a * (a+1);
    c/=2;
    return c;
}

const int M = 200001;

int main(){
    ll N;
    cin >> N;
    vector A(M, vector<int>{});
    rep(i,N) {
        int a;
        cin>>a;
        A[a].push_back(i);
    }
    ll ans = 0;
    ll cbN = cmb(N);
    rep(i,M) {
        if (A[i].size() == 0) continue;
        ll ta = cbN;
        int lst = -1;
        for(auto k: A[i]) {
            ta -= cmb(k-1-lst);
            lst = k;
        }
        ta -= cmb(N-1-lst);
        ans += ta;
    }
    
    cout << ans << endl;
    return 0;
}