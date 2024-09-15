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
    ll N, Mg;
    cin >> N >> Mg;
    vector uv(N, vector<bool>(N, false));
    rep(i,Mg) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u][v] = true;
        uv[v][u] = true;
    }
    ll Mh;
    cin >> Mh;
    vector ab(N, vector<bool>(N, false));
    rep(i,Mh){
        int a,b;
        cin >> a >> b;
        a--, b--;
        ab[a][b] = true;
        ab[b][a] = true;
    }
    vector A(N, vector<ll>(N));
    rep(i,N-1) for(int j=i+1; j<N; j++) {
        cin>>A[i][j];
        A[j][i] = A[i][j];
    }

    vector<int> arr(N);
    rep(i,N) arr[i] = i;
    ll cmin = INF;
    do {
        ll tc = 0;
        rep(i,N-1) for(int j=i+1; j<N; j++){
            if (ab[i][j] != uv[arr[i]][arr[j]]) {
                tc+=A[i][j];
            }
        }
        cmin = min(cmin, tc);
	} while (next_permutation(arr.begin(), arr.end()));
    
    cout << cmin << endl;
    return 0;
}