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
typedef modint998244353 mint;
int main(){
    ll T;
    cin>>T;
    while(T--){
        int N; cin>>N;
        string S; cin>>S;        
        string T="";
        rep(i,N/2) {
            T.push_back(S[i]);
        }
        string T2 = T;
        reverse(T2.begin(), T2.end());
        if(N%2 == 1) T.push_back(S[N/2]);
        int sz = T.size();
        T = T + T2;
        mint ans = 0;        
        mint x = 1;
        mint k = 'Z'-'A'+1;
        for(int i = sz-1; i>=0; i--) {
            ans += x * (S[i]-'A');
            x *= k;
        }
        if(T<=S) ans++;        
        cout << ans.val() << endl;
    }
    return 0;
}