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
    string S;
    cin >> S;
    bool isany = false;
    rep(i,N) {
        if (S[i] == 'x') {
            cout << "No" << endl;
            return 0;
        }
        if (S[i] == 'o') isany = true;
    }
    if (isany) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}