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
    vector A(N, vector<ll>{});    
    rep(i,N) {
        ll k;
        cin >> k;
        A[i].resize(k);
        rep(j,k) {
            cin>>A[i][j];
            A[i][j]--;
        }
    }
    vector<unordered_map<ll, double>> P(N);
    rep(i,N) {        
        double d = (double)1/(double)A[i].size();
        for(auto a: A[i]) {
            P[i][a] += d;
        }
    }

    double ans = 0;
    rep(i,N) for(int j=i+1; j<N; j++){
        double t = 0;
        if(P[i].size() < P[j].size()) {
            for(auto p: P[i]) {
                if(!P[j].contains(p.first)) continue;
                t += p.second * P[j][p.first];
            }
        } else {
            for(auto p: P[j]) {
                if(!P[i].contains(p.first)) continue;
                t += p.second * P[i][p.first];
            }
        }
        chmax(ans, t);
    }

    printf("%.10f\n", ans);

    return 0;
}