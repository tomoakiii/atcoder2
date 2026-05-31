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
    ll N,M;
    cin >> N >> M;
    vector uv(N, vector<int>{});
    vector vu = uv;
    rep(i,M) {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        uv[a].push_back(b);
        vu[b].push_back(a);        
    }    
    ll ans = 0;
    rep(i,N) {        
        ll d = 0;
        vector<bool> visit(N);
        auto f=[&](auto f, int cur)->void{
            visit[cur] = true;
            d++;
            for(auto nx: uv[cur]) {
                if(visit[nx]) continue;
                f(f, nx);
            }
        };
        f(f,i);
        ans+=d;            
    }
    cout<<ans<<endl;
    return 0;
}