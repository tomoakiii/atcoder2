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
    int a[3][6] = {{2, 4, 5, 7, 9, -1}, {0, 1, 6, 8, -1, -1}, {3, -1, -1, -1, -1, -1}};
    string s[3] = {"hon", "pon", "bon"};
    rep(i,3) rep(j,6) if(N%10==a[i][j]) cout<<s[i]<<endl;
    return 0;
}