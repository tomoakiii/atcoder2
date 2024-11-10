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
typedef pair<ll, int> pli;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N+1);
    vector Res(M+1, vector<ll>{});    
    for(ll i=1; i<=N; i++) {
        cin>>A[i];
        int mint;
        if (A[i] > 0)  {
            mint = 0;
        } else {
            ll a = -A[i];
            mint = max((ll)0, a/i - 1);
        }
        for(ll j=mint; j<=M; j++) {
            ll val = A[i] + (j*i);
            if (val > N) break;
            if (val < 0) continue;
            Res[j].push_back(val);
        }
    }
    
    for(int x=1; x<=M; x++) {
        vector<bool> value(N+1, false);
        for(auto val : Res[x]) {
            value[val] = true;
        }
        ll ans = 0;
        rep(i, N+1) {
            if (value[i] == false) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;        
    }
   return 0;
}