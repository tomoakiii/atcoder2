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
    vector<string> dir{"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    string D;
    cin >> D;
    rep(i, 8) {
        if(dir[i] == D) {
            cout << dir[(i + 4)%8] << endl;
        }
    }
    return 0;
}