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
    string s0,s1;
    cin>>s0>>s1;
    string t1=s0, t0=s1;
    reverse(t0.begin(), t0.end());
    reverse(t1.begin(), t1.end());
    if(s0==t0&&s1==t1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}