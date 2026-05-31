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
    string S; cin>>S;
    ll ans = 0;
    auto f=[&](auto f, int cur, vector<vector<ll>> v)->void{
        if(cur == S.size()) {
            if(v[0].empty() || v[1].empty()) return;
            sort(v[0].rbegin(), v[0].rend());
            sort(v[1].rbegin(), v[1].rend());
            if(v[0][0] == 0 || v[1][0] == 0) return;
            else {
                ll x1=0,x2=0;
                for(auto c: v[0]) x1 = x1*10 + c;
                for(auto c: v[1]) x2 = x2*10 + c;
                chmax(ans, x1*x2);
                return;
            }
        }
        v[0].push_back(S[cur]-'0');
        f(f,cur+1, v);
        v[0].pop_back();        
        v[1].push_back(S[cur]-'0');
        f(f,cur+1, v);
    };
    f(f,0,vector(2, vector<ll>{}));
    cout<<ans<<endl;
    return 0;
}