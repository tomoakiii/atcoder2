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
    ll K2 = K*2;
    vector W(4*K+1, vector<ll>(4*K+1));
    auto B = W;
    int bc = 0, wc = 0;
    rep(i,N) {
        int x,y; char c;
        cin>>x>>y>>c;
        x%=K2; y%=K2;
        x++, y++;
        if(c=='W') {
            W[x][y]++;
            W[x][y+K2]++;
            W[x+K2][y+K2]++;
            W[x+K2][y]++;
            wc++;
        } else {
            B[x][y]++;
            B[x][y+K2]++;
            B[x+K2][y+K2]++;
            B[x+K2][y]++;
            bc++;
        }
    }
    rep(i,4*K) rep(j, 4*K) {
        W[i][j+1] += W[i][j];
        B[i][j+1] += B[i][j];
    }
    rep(i,4*K) rep(j, 4*K) {
        W[i+1][j] += W[i][j];
        B[i+1][j] += B[i][j];
    }
    auto show = [](vector<vector<ll>> &v)->void{
        for(auto y:v) {
            for(auto x:y) cerr<<x<<" ";
            cerr<<endl;
        }
        cerr<<endl;
    };
    /*
    show(B);
    show(W);
    */
    ll ans = 0;
    for(int i=0; i<=2*K; i++) for(int j=0; j<=2*K; j++) {
        ll b = B[i+K][j+K] + B[i][j] - B[i][j+K] - B[i+K][j];
        b += B[i+K2][j+K2] + B[i+K][j+K] - B[i+K][j+K2] - B[i+K2][j+K];
        ll w = W[i+K2][j+K] + W[i+K][j] - W[i+K][j+K] - W[i+K2][j];
        w += W[i+K][j+K2] + W[i][j+K] - W[i][j+K2] - W[i+K][j+K];
        ll sm = b + w;

        if(chmax(ans, sm)) {
            /*
            cerr<<i<<" "<<j<<endl;
            cerr<<w<< " "<<b<<endl;
            */
        }

    }
    cout<<ans<<endl;
    return 0;
}