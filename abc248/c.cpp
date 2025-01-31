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
using modint998244353 mint;
int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N, 1);
    vector<ll> nm(M+1);
    mint ans = 0;
    vector<mint> ta(M+1, 1);
    vector<mint> revta(M+1);
    for(int i=1; i<=M; i++) {
        ta[i] = ta[i-1];
        ta[i] *= i;
        revta[i] = 1 / ta[i];
    }
    
    auto func = [&](auto func, int cur, vector<ll> t, vector<ll> num, ll total) -> void {
        mint tans = ta[M];
        for(auto n: nm) {
            tans *= revta[i];
        }
        ans += tans;
        if(cur == 0) {
            if(total < K){
                num[t[cur]]--;
                t[cur]++;
                num[t[cur]]++;
                func(func, cur, )
            }
        } else {

        }
    };
    nm[1] = N;
    func(func, 0, A, nm, N);
    cout << ans.val() << endl;
    return 0;
}