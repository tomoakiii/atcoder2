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
    ll N,Q;
    cin >> N >> Q;    
    vector<string> S{};
    S.push_back("");
    vector<int> uv{};
    uv.push_back(0);
    vector<int> pc(N, 0);
    int Server = 0;
    while(Q--){
        int q; cin>>q;
        int p; cin >> p; p--;
        if(q == 1) {    
            pc[p] = Server;
        } else if (q == 2) {
            string s; cin >> s;
            S.push_back(s);
            int nx = pc[p];            
            uv.push_back(nx);
            pc[p] = uv.size() - 1;
        } else {
            Server = pc[p];
        }
    }

    vector<string> ans{};
    int ind = Server;    
    while(ind > 0) {
        ans.push_back(S[ind]);
        ind = uv[ind];
    }
    for(int i = ans.size()-1; i>=0; i--) cout<<ans[i];
    cout<<endl;
    return 0;
}