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
    string S1, S2; cin>>S1>>S2;
    if(S1[0] == '#' && S1[1] == '.' && S2[1] == '#' && S2[0] == '.') cout<<"No"<<endl;
    else if(S2[0] == '#' && S2[1] == '.' && S1[1] == '#' && S1[0] == '.') cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}