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
    ll ans = (ll)S.size();
    int i = 0;
    while(i < (int)S.size()) {
        if (i != S.size()-1 && S[i] == '0' && S[i+1] == '0') {
            ans--;
            i++;
        }
        i++;
    }
    
    cout << ans << endl;
    return 0;
}