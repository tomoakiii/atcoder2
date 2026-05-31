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
    ll N,M; cin>>N>>M;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    set<string> st;
    for(int i=0; i<=N-M; i++) {
        for(int j=0; j<=N-M; j++) {
            string t = "";
            for(int x=0; x<M; x++) {
                for(int y=0; y<M; y++) {
                    t = t + S[y+i][x+j];                    
                }
            }
            st.insert(t);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}