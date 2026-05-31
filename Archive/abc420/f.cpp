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
    vector smv = sm;
    rep(i,N) {
        rep(j,M-1){            
            if(S[i][j+1] != '#') sm[i][j+1] += sm[i][j];
        }
    }

    
    rep(j,M) {
        rep(i,N-1){            
            if(S[i+1][j] != '#') smv[i+1][j] += smv[i][j];
        }
    }

    vector ans(N, vector<ll>(M,0));    
    rep(i,N) {
        rep(j,M) {
            if(S[i][j] == '#') continue;
            if(i==0) {
                ans[i][j] = sm[i][j];
                continue;
            }
            if(j==0) {
                ans[i][j] = smv[i][j];
                continue;
            }
            if(smv[i][j] < smv[i][j-1]) {
                int lst = i - smv[i][j];   
                int lst2 = j - sm[i][j];
                if(lst2 >= 0) ans[i][j] = ans[i][j-1] - ans[lst][j-1] + ans[lst][lst2] + smv[i][j];
                else ans[i][j] = ans[i][j-1] - ans[lst][j-1] + smv[i][j];
                continue;
            }
            ans[i][j] = ans[i][j-1] + smv[i][j];            
        }
    }
    /*
    auto disp = [&]()->void{
        rep(i,N) {
            rep(j,M) cout << ans[i][j] << " ";
            cout<<endl;
        }
        
    };    
    disp();
    */
    ll ret = 0;
    rep(i,N) rep(j,M) ret += ans[i][j];
    cout << ret << endl;
    return 0;
}