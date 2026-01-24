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
    ll N,K;
    cin >> N >> K;
    string S; cin>>S;
    string ans;
    auto func = [&](auto func, string T, int R, int p) -> void{
        ans = T;
        if(R == 0) return;
        if(p == N-1) return;
        int x;
        char mn = 'z'+1;
        for(int i = p+1; i<N; i++) {
            if(chmin(mn, T[i])) {
                x = i;
            }
        }
        if(mn < T[p]) {
            swap(T[p], T[x]);
            int sm = 0;
            rep(i,N) if(S[i]!=T[i]) sm++;
            func(func, T, K-sm, p+1);
            return;
        }
        func(func, T, R, p+1);
    };
    func(func, S, K, 0);
    cout << ans << endl;
    return 0;
}