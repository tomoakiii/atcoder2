#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N; string S;
    cin>>N>>S;
    /*
    string st = "";
    rep(i,N) st.push_back('a');
    map<string, ll> mp;
    mp[st] = 0;
    auto func = [&](auto func, string x) -> void{
        rep(i,N) {
            if(x[i] == 'c') continue;
            string y = x;
            y[i]++;
            rep(j, i) {
                if(y[j] == 'a') y[j] = 'c';
                else y[j]--;
            }
            if(!mp.contains(y) || mp[y] < mp[x] + 1) {
                mp[y] = mp[x] + 1;
                func(func, y);
            }
        }
    };
    func(func, st);
    cout << endl;
    set<pair<ll, string>> mp2;
    for(auto [m,c] : mp) {
        cout << m << " " << c << endl;
        mp2.insert({c,m});
    }
    for(auto [c,m]: mp2) {
        cout << m << " " << c << endl;
    }
    */

    ll p = 1;
    ll ans = 0;
    for(auto c: S) {
        int x = c - 'a';
        ans += x*p;
        p*=2;
    }
    cout << ans << endl;
    return 0;
}