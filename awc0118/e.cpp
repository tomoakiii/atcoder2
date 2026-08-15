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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,L;
    cin >> N >> M >> L;
    string S,P,T; cin >> S >> P >> T;
    vector<ll> Q(L);
    rep(i,L) cin>>Q[i];
    vector nx(N, vector<bool>(N+1));
    rep(i,N){
        vector<char> vc;
        for(int j=i+1;j<N;j++){
            if(vc.empty()) nx[i][j] = true;
            if(!vc.empty() && vc.back() == P[j]) {
                vc.pop_back();
            } else {
                vc.push_back(P[j]);
            }
        }
        if(vc.empty()) nx[i][N] = true;
        vc.clear();
    }
    vector uv(L, vector<int>{});
    vector<char> vc;
    rep(i,N){
        if(S[i]==T[0]) {
            if(vc.empty()) uv[0].push_back(i);
        }
        if(!vc.empty() && vc.back() == P[i]) {
            vc.pop_back();
        } else {
            vc.push_back(P[i]);
        }
    }
    vc.clear();
    for(int l=1;l<L;l++){
        rep(i,N) {
            if(S[i]==T[l]) {
                for(auto j:uv[l-1]){
                    if(j>i) break;
                    if(nx[j][i]) {
                        uv[l].push_back(i);
                        break;
                    }
                }
            }
        }
    }
    for(auto i:uv[L-1]){
        if(nx[i][N]) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}