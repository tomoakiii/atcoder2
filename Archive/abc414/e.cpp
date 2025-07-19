// count up numbers a % b == 0 (a>b)
//https://atcoder.jp/contests/abc414/tasks/abc414_e
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
    ll N;
    cin >> N;    
    mint ans = 0;
    ans += mint(N) * (N+1) / 2;    
    mint ng = 0;
    ll now = 1; // N以下で、かつnowの倍数となる数値の個数をngとして積み上げる
    while(now <= N){
        ll nxi = N/now; // nowの倍数であるN以下の数の個数。
        ll x = N/nxi; // N/now = N/x が保証される。かつ、xは考えられる最大の値
        ll nxp = x + 1; // 
        ng += mint(nxi) * mint(nxp-now); // N/now + N/(now+1) + .... + N/x （全部同じ値だからnxp-now個ある）と同じ効果
        now = nxp; // next number of x
    }
    ans -= ng;
    cout << ans.val() << endl;
}