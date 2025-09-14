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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    vector sm(N, vector<ll>(M,0));
    rep(i,N) {
        rep(j,M){
            if(S[i][j] == '#') sm[i][j] = 0;
            else sm[i][j] = 1;
        }
    }

    rep(i,N) {
        rep(j,M-1){            
            if(S[i][j+1] != '#') sm[i][j+1] += sm[i][j];
        }
    }

    rep(j,M) {
        rep(i,N-1){            
            if(S[i+1][j] != '#') {                
                sm[i+1][j] += sm[i][j];
            } else {
                if(j < M-1 && sm[i][j+1] > 0 && S[i+1][j+1] != '#') sm[i+1][j+1] -= sm[i][j];
            }
        }
    }

    auto disp = [&]()->void{
        rep(i,N) {
            rep(j,M) cout << sm[i][j] << " ";
            cout<<endl;
        }
        
    };
    disp();
    ll ans = 0;
    rep(i,N) rep(j,M) ans += sm[i][j];

    cout << ans << endl;
    return 0;
}