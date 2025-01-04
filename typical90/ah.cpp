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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    map<ll, int> last;
    rep(i,N) {
        cin >> A[i];
    }
    int l = 0;;
    int tp = 0;
    ll mx = 0;
    rep(r, N) {
        last[A[r]]++;
        if(last[A[r]] == 1) tp++;
        while(tp > K) {
            last[A[l]]--;
            if(last[A[l]] == 0) tp--;
            l++;
        }
        chmax(mx, r-l+1);
    }
    cout << mx << endl;
    return 0;
}