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
    string S;
    cin >> S;
    bool isOdd = true;
    ll cnt = 0;
    rep(i, S.size()) {
        if((S[i] == 'i') == isOdd) {
            isOdd = !isOdd;
            continue;            
        }
        else cnt++;        
    }
    if((S.size() + cnt)%2 == 1) cnt++;
    cout << cnt << endl;
    return 0;
}