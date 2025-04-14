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
    int N, K;
    cin >> N >> K;
    struct abc{ int a, b, c; };
    vector<ll> A(N), B(N), C(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    map<ll, vector<int>> mp;
    auto abbcca = [&](vector<int> in)->ll{
        int a = in[0], b=in[1], c=in[2];
        if(a<0 || b<0 || c<0) return -INF;
        return A[a]*B[b] + B[b]*C[c] + C[c]*A[a];
    };
    rep(i,N) rep(j,N) rep(k,N) {
        vector<int> v = {i,j,k};
        mp[abbcca(v)] = v;
    }
    for(auto m: mp) {
        cout << m.first << " {" << m.second[0] << "_" << m.second[1] << "_" << m.second[2] << "_" << "}" << endl;
    }
    return 0;
}
