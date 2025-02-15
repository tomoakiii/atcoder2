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
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 4;
    if(s1 == "sick" && s2 == "sick"){
        ans = 1;
    } else if (s1 == "sick" && s2 == "fine") {
        ans = 2;
    } else if (s1 == "fine" && s2 == "sick") {
        ans = 3;
    }
    cout << ans << endl;
       return 0;
}