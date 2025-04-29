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
    ll N, M;
    cin >> N >> M;

    vector<int> Acnt(M);
    vector Aind(N, vector<int>{});
    rep(i,M) {
        int K;
        cin >> K;             
        Acnt[i] = K;
        rep(j,K){
            int a;
            cin >> a;
            a--;            
            Aind[a].push_back(i);
        }
    }
    ll ans = 0;
    rep(i,N) {
        int b;
        cin >> b;
        b--;
        for(auto j: Aind[b]) {
            Acnt[j]--;
            if(Acnt[j] == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}