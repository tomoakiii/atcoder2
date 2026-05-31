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
    vector<ll> cnt('z'-'a'+1,INF);
    rep(i,N) {
        string S; cin>>S;
        vector<ll> tmp('z'-'a'+1,0);
        for(auto c:S){
            tmp[c-'a']++;
        }
        for(int c=0; c<='z'-'a'; c++){
            chmin(cnt[c], tmp[c]);
        }
    }
    for(int c=0; c<='z'-'a'; c++){
        rep(i, cnt[c]) cout<<(char)('a'+c);
    }
    cout<<endl;
    return 0;
}