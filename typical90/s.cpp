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
    ll N;
    cin >> N;
    N*=2;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 0;
    while(A.size() > 0) {
        ll mn = INF;
        ll mind = -1;
        rep(i, A.size()-1) {
            ll d = abs(A[i] - A[i+1]);
            if(mn > d) {
                mn = d;
                mind = i;
            }
        }
        ans += mn;
        int i = mind;
        A.erase(A.begin() + i+1);
        A.erase(A.begin() + i);
    }
    cout << ans << endl;
    return 0;
}