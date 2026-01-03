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
    ll N;
    cin >> N;
    map<ll, bool> mp;
    auto dfs = [&](auto dfs, ll x)->bool{
        if(2*x > N) {
            mp[2*x] = false;
            return false;
        }
        if(!mp.contains(2*x)) mp[2*x] = dfs(dfs, 2*x);
        if(!mp.contains(2*x+1)) mp[2*x+1] = dfs(dfs, 2*x+1);
        if(mp[2*x] && mp[2*x+1]) {
            mp[x] = false;
            return false;
        }
        mp[x] = true;
        return true;
    };
    if(dfs(dfs, 1)) cout << "Takahashi" << endl;
    else cout<<"Aoki"<<endl;
    return 0;
}