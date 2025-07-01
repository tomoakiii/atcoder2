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
    string s; cin >> s;
    int r = s[s.size()-1] - '0';
    s.pop_back(); s.pop_back();
    if(r <= 2) {        
        cout << s << "-" << endl;
    } else if (r <= 6){
        cout << s << endl;
    } else {
        cout << s << "+" << endl;
    }

    return 0;
}