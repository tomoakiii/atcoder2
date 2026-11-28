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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll H,W;
    cin >> H >> W;
    rep(i,H){
        string s; cin>>s;
        bool flg=false;
        for(auto c:s){
            if(c=='T')flg=true;
        }
        cout<<((flg)?"o":"x")<<((i==H-1)?"\n":"");
    }
    return 0;
}