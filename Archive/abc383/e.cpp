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
typedef tuple<ll, int, int> tlii;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<tlii> uvw(M);
    rep(i,M) {
        int u,v,w;
        cin>>u>>v>>w;
        u--, v--;
        uvw[i] = make_tuple(w, u, v);
    }
    sort(uvw.begin(), uvw.end());
    vector<int> A(K), B(K);
    vector<int> unrgA(N), unrgB(N);
    rep(i,K) {
        cin>>A[i];
        A[i]--;
        unrgA[A[i]]++;
    }
    rep(i,K) {
        cin>>B[i];
        B[i]--;
        unrgB[B[i]]++;
    }
    
    dsu UF(N);
    ll acm = 0;
    for(auto [w, u, v]: uvw){
        if(UF.same(u, v)) continue;
        int pu = UF.leader(u);
        int pv = UF.leader(v);        
        int nu = UF.merge(pu, pv);        
        int uA = unrgA[pu] + unrgA[pv];
        int uB = unrgB[pu] + unrgB[pv];
        int m = min(uA, uB);
        unrgA[nu] = uA - m;
        unrgB[nu] = uB - m;
        acm += w*m;        
    }
    cout << acm << endl;
    return 0;
}