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
    vector<string> SW = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    string S;
    cin >> S;
    rep(i, 5) {
        if (SW[i] == S) {
            cout << 5-i << endl;
            return 0;
        }
    }
    return 0;
}