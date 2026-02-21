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
    ll N,K;
    cin >> N >> K;
    vector C(N,vector<ll>(N));
    rep(i,N) rep(j,N) cin>>C[i][j];
    vector<int> ord(N);
    auto ref = ord;
    rep(i,N) ord[i] = i;
    ll ans=0;
    do{
        auto tmp = ord;
        int cnt = 0;
        rep(i,N) {
            if(tmp[i] == i) continue;
            for(int j = i+1; j<N; j++) {
                if(tmp[j] == i) {
                    swap(tmp[i], tmp[j]);
                    cnt++;
                }
            }
        }
        if(cnt > K) continue;
        ll sm = 0;
        rep(i,N) {
            int nx = (i+1)%N;
            sm += C[ord[i]][ord[nx]];
        }
        chmax(ans,sm);
    }while(next_permutation(ord.begin(), ord.end()));
    cout<<ans<<endl;
    return 0;
}