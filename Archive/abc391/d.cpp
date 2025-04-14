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
    ll N, W;
    cin >> N >> W;
    vector<ll> X(N), Y(N);
    rep(i,N) {
        cin>>X[i]>>Y[i];
        X[i]--;
    }
    ll Q;
    cin >> Q;
    vector<pair<ll,ll>> TA(Q);
    
    vector XY(W, vector<pair<ll, int>>{});
    map<int, ll> time;
    vector<ll> rows(N); 
    rep(i,N) {
        XY[X[i]].push_back({Y[i], i});
        int h = XY[X[i]].size();
        time[h] = max(time[h], Y[i]);
        rows[i] = h;
    }
    int full = INFi;
    rep(i, W) {
        chmin(full, (int)XY[i].size());
    }
    
    rep(i,Q) {
        ll t,a;
        cin >> t >> a;
        a--;
        int h = rows[a];
        if(time[h] <= t && h <= full) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    
    return 0;
}