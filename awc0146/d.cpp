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
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<string> S(N), C(N), T(N);
    rep(i,N) cin>>S[i]>>C[i];
    rep(i,N) cin>>T[i];

    vector lib(N, vector(N, vector<ll>(M, 0)));
    rep(m,M){
        vector<int> ord(N);
        rep(i,N)ord[i]=i;
        rep(i,N) rep(i2,N) rep(j,M){
            int nj=(j+m)%M;
            if(C[i][j] == '0' && S[i][j]!=T[i2][nj]) lib[i][i2][m]++;
        }
    }
    while(Q--){
        int op; cin>>op;
        if(op==1){
            int i, p; char x;
            cin>>i>>p>>x; i--,p--;
            rep(i2,N) rep(m,M){
                int nj=(p+m)%M;
                if(C[i][p] == '0' && S[i][p]!=T[i2][nj]) lib[i][i2][m]--;
            }
            S[i][p]=x;
            rep(i2,N) rep(m,M){
                int nj=(p+m)%M;
                if(C[i][p] == '0' && S[i][p]!=T[i2][nj]) lib[i][i2][m]++;
            }
        }else if(op==2){
            int i, p; char x;
            cin>>i>>p>>x; i--,p--;
            rep(i2,N) rep(m,M){
                int nj=(p+m)%M;
                if(C[i][p] == '0' && S[i][p]!=T[i2][nj]) lib[i][i2][m]--;
            }
            C[i][p]=x;
            rep(i2,N) rep(m,M){
                int nj=(p+m)%M;
                if(C[i][p] == '0' && S[i][p]!=T[i2][nj]) lib[i][i2][m]++;
            }
        }else{
            int i2, nj; char x;
            cin>>i2>>nj>>x; i2--,nj--;
            rep(i,N) rep(m,M){
                int p=(nj+M-m)%M;
                if(C[i][p] == '0' && S[i][p]!=T[i2][nj]) lib[i][i2][m]--;
            }
            T[i2][nj]=x;
            rep(i,N) rep(m,M){
                int p=(nj+M-m)%M;
                if(C[i][p] == '0' && S[i][p]!=T[i2][nj]) lib[i][i2][m]++;
            }
        }
        ll ans = INF;
        vector<ll> ord(N);
        rep(i,N)ord[i]=i;
        do{
            rep(m,M){
                ll cnt = 0;
                rep(i,N){
                    int j = ord[i];
                    cnt += lib[i][j][m];
                }
                chmin(ans,cnt);
            }
        }while(next_permutation(ord.begin(),ord.end()));
        cout<<ans<<"\n";
    }
    return 0;
}