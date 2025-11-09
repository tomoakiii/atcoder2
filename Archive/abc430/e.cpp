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
typedef modint1000000007 mint1;
typedef modint998244353 mint2;
int main(){
    ll T; cin>>T;
    while(T--) {
        string A, B; cin>>A>>B;        
        mint1 p1 = 1;
        mint2 p2 = 1;
        ll N = A.size();
        rep(i,N-1) {
            p1*=10; p2*=10;
        }
        mint1 a = 0, b = 0;
        mint2 a2 = 0, b2 = 0;
        rep(i,N) {
            ll ca = A[i] - '0';
            a = a * 10 + ca;
            a2 = a2 * 10 + ca;
            ll cb = B[i] - '0';
            b = b * 10 + cb;
            b2 = b2 * 10 + cb;
        }
        bool flg = false;
        rep(i,N) {
            if(a == b && a2 == b2) {
                cout<<i<<endl;
                flg = true;
                break;
            }
            ll ca = A[i] - '0';
            a = a - ca * p1;
            a = a * 10 + ca;
            a2 = a2 - ca * p2;
            a2 = a2 * 10 + ca;  
        }
        if(!flg) cout<<-1<<endl;
    }
    
    return 0;
}