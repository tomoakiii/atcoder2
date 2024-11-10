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
    string S;
    cin >> N >> S;
    string S2="";
    rep(i,N-1){
        if(S[i] == 'n' && S[i+1] == 'a') {
            S2 = S2 + "ny";
        } else {
            S2 = S2 + S[i];
        }
    }
    S2 = S2 + S[N-1];
    cout << S2 << endl;
    return 0;
}