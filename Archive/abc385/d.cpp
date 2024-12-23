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
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    map<ll, set<ll>> Row, Col;
    
    rep(i,N) {
        int x, y;
        cin>>x>>y;
        Row[y].insert(x);
        Col[x].insert(y);
        
    }
    
    
    ll ans = 0;    
    while(M--) {
        char t;
        int C;
        cin >> t >> C;
        ll l, r;        
        if(t == 'U') {
            auto it = Col[X].lower_bound(Y);
            while(it != Col[X].end() && *it <= Y+C){
                ans++;                                   
                Row[*it].erase(X);
                it = Col[X].erase(it);                            
            }
            Y+=C;
        } else if (t == 'D') {
            auto it = Col[X].lower_bound(Y-C);
            while(it != Col[X].end() && *it <= Y){
                ans++;                                   
                Row[*it].erase(X);
                it = Col[X].erase(it);                            
            }
            Y-=C;
        } else if (t == 'R') {
            auto it = Row[Y].lower_bound(X);
            while(it != Row[Y].end() && *it <= X+C){
                ans++;                                   
                Col[*it].erase(Y);
                it = Row[Y].erase(it);                            
            }
            X+=C;
        } else {
            auto it = Row[Y].lower_bound(X-C);
            while(it != Row[Y].end() && *it <= X){
                ans++;                                   
                Col[*it].erase(Y);
                it = Row[Y].erase(it);                  
            }
            X-=C;
        }
    }
    cout << X << " " << Y << " " << ans << endl;
    return 0;
}