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
    ll N, D;
    cin >> N >> D;
    string S;
    cin >> S;

    ll pk = 0;
    
    reverse(S.begin(), S.end());
    rep(i,N) {
        if (S[i] == '@') {
            pk++;
            S[i] = '.';
        }
        if(pk >= D) break;
    }
    reverse(S.begin(), S.end());
    rep(i, N) cout << S[i]; 
    cout << endl;

    return 0;
}