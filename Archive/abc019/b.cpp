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
    string s; cin>>s;
    s.push_back('!');
    char last = s[0];
    int n = 0;
    string ans = "";
    for(auto c:s) {
        if(c==last) n++;
        else {
            ans.push_back(last);
            ans = ans + to_string(n);
            n = 1;
            last = c;
        }
    }
    cout << ans << endl;
    return 0;
}