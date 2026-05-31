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
    ll N, Q;
    cin >> N >> Q;    
    vector<int> to(N,-1), from(N, -1);
    
    while(Q--){
        int t; cin>>t;
        if(t==1){
            int x,y; cin>>x>>y; x--,y--;
            to[x] = y;
            from[y] = x;
        } else if(t==2){
            int x,y; cin>>x>>y; x--,y--;
            to[x] = -1;
            from[y] = -1;
        } else {
            int x; cin>>x; x--;
            int l=x;
            while(true) {
                if(from[l]!=-1) l = from[l];
                else break;
            }
            vector<int> ans{};
            while(l!=-1) {
                ans.push_back(l+1);
                l = to[l];
            }
            cout<<ans.size()<<" ";
            for(auto a:ans) cout<<a<<" ";
            cout<<endl;
        }
    }
    return 0;
}