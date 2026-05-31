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
    N--;
    ll nm = 26;
    int ln = 1;
    while(N >= nm){
        N -= nm;
        nm *= 26;
        ln++;
    }
    string ans;
    rep(i,ln) {
        int ofs = N % 26;
        char c = 'a' + ofs;
        ans = ans + c;
        N/=26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}