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
    if(N%2 == 1) {
        return 0;
    }
    auto f=[&](auto f, int cur, int cnt, ll t)->void{
        if (cur == N) {
            rep(i, N) {
                if(((t>>i) & 1)>0) printf(")");
                else printf("(");
            }
            printf("\n");
            return;
        }
        if(cnt == 0) {            
            f(f, cur+1, cnt+1, t);
        } else if (N-cur == cnt) {
            ll t2 = t | (1<<cur);
            f(f, cur+1, cnt-1, t2);
        } else {
            ll t2 = t | (1<<cur);
            f(f, cur+1, cnt+1, t);
            f(f, cur+1, cnt-1, t2);
        }
    };
    f(f, 0, 0, 0);
    return 0;
}