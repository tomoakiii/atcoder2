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
typedef modint1000000007 mint;
int main(){
    ll N;
    cin >> N;
    string S0, S1; cin>>S0>>S1;
    /*
    vector<set<int>> uv(N);
    int id = 0;
    map<char,int> mp;
    for(char c='a';c<='z';c++) mp[c] = id++;
    for(char c='A';c<='Z';c++) mp[c] = id++;
    rep(i,N-1) {
        auto reg = [&](char a, char b)->void{
            uv[mp[a]].insert(mp[b]);
        };
        reg(S0[i], S1[i]);
        reg(S0[i], S0[i+1]);
        reg(S1[i], S1[i+1]);
    }
    */
    //const int M = 2*('z'-'a'+1);
    mint ans = 3;
    if(S0[0] != S1[0]) ans *= 2;
    rep(i,N-1) {
        if(S1[i] == S0[i]) { // 縦同じ
            if(S0[i+1] != S1[i+1]) ans *= 2; // 横
            else ans *= 2; // 縦
        } else {
            if(S0[i] == S0[i+1]) continue;
            if(S0[i+1] != S1[i+1]) ans *= 3;
            else ans *= 1;
        }
    }
    cout<<ans.val()<<endl;
    return 0;
}