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
    ll H,W;
    cin >> H>>W;
    vector A(H, vector<ll>(W));
    ll mx = 0;
    rep(i,H)rep(j,W) {
        cin>>A[i][j];
        mx = mx ^ A[i][j];
    }
    vector visit(H, vector<ll>(W));
    
    auto disp = [&H, &W, &visit]()->void{
        rep(i,H) {
            rep(j,W) {
                cout << visit[i][j] << " ";
            }            
            cout << endl;
        }
        cout << endl;
    };

    auto f = [&](auto f, int i, int j, ll score)->void{        
        // disp();
        chmax(mx, score);
        if(j >= W) {
            j=0;
            i++;
        }
        if(i>=H) return;        
        if(!visit[i][j]) {            
            if(j+1<W && !visit[i][j+1]){
                visit[i][j+1] = true;
                visit[i][j] = true;
                f(f, i, j+2, score^A[i][j]^A[i][j+1]);
                visit[i][j+1] = false;
                visit[i][j] = false;
            }
            if(i+1<H && !visit[i+1][j]){
                visit[i+1][j] = true;
                visit[i][j] = true;
                f(f, i, j+1, score^A[i][j]^A[i+1][j]);
                visit[i+1][j] = false;
                visit[i][j] = false;
            }
        }
        f(f, i, j+1, score);
        return;
    };
    f(f, 0, 0, mx);
    cout << mx << endl;
    return 0;
}