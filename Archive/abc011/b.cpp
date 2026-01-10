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
    bool flg = true;
    if('A' > S[0] || 'Z' < S[0]) S[0] = S[0] - 'a' + 'A';
    for(int i=1; i<S.size(); i++) if('a' > S[i] || 'z' < S[i]) S[i] = S[i] - 'A' + 'a';
    cout << S << endl;
    return 0;
}