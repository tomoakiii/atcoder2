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
    ll N, R, C;
    cin >> N >> R >> C;    
    string S;
    cin >> S;
    vector<ll> y(N), x(N);
    map<pair<int,int>, int> mp;        
    rep(i, N) {
        if(S[i] == 'N') y[i]=-1;
        else if(S[i] == 'S') y[i]=1;
        else if(S[i] == 'E') x[i]=1;
        else if(S[i] == 'W') x[i]=-1;
    }
    vector<int> ysm(N+1), xsm(N+1);    
    vector yxsm(N+1, vector<int>{});
    rep(i,N) {
        ysm[i+1] = y[i];
        xsm[i+1] = x[i];
    }
    rep(i,N) {
        ysm[i+1] += ysm[i];
        xsm[i+1] += xsm[i];
    }
    int id = 0;
    rep(i,N+1) {
        pair<int, int> pos = {ysm[i], xsm[i]};
        if(!mp.contains(pos)) mp[pos] = i;        
    }

    for(ll i=1; i<=N; i++) {
        pair<int, int> pyx = {ysm[i]-R, xsm[i]-C};
        if( !mp.contains(pyx) ) {
            cout << 0;
        } else {            
            if(mp[pyx]<=i) cout << 1;
            else cout << 0;
        }
    }
    cout << endl;
    return 0;
}
