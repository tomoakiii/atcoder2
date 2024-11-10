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

const int M_SIZE = 2;
ll A, X, M;

vector<vector<ll>> MProd(vector<vector<ll>> a, vector<vector<ll>> b){
    vector<vector<ll>> out(2, vector<ll>(2));
    rep(i, M_SIZE) {
        rep(j, M_SIZE) {
            rep(k, M_SIZE){
                out[i][j] += a[i][k] * b[k][j] % M;
            }
        }
    }
    return out;
}



int main(){
    
    cin >> A >> X >> M;
    if (A==1) {
        cout << X%M << endl;
        return 0;
    }

    map<ll, vector<vector<ll>>> mp;
    mp[1] = vector<vector<ll>>{{A, 1}, {0, 1}};
    mp[0] = vector<vector<ll>>{{1, 0}, {0, 1}};
    ll lasi;
    for(ll i = 1; (i-1)*(i-1) < X; i++) {
        mp[i+1] = MProd(mp[i], mp[i]);
        lasi = i;
    }
    lasi++;
    mp[lasi+1] = MProd(mp[lasi], mp[lasi]);
    X--;
    auto ans = mp[0];
    ll k = 1;
    while(X){
        if(X%2) ans = MProd(ans, mp[k]);
        k++;
        X/=2;
    }    
    cout << (ans[0][0]+ans[0][1])%M << endl;
    return 0;
}