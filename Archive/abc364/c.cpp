#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);

    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    ll ans = 0;
    ll sm = 0;
    for(ll s: A) {
        sm+=s;
        ans++;
        if(sm > X) {
            break;
        }
    }
    ll ans2 = 0;
    sm = 0;
    for(ll s: B) {
        sm+=s;
        ans2++;
        if(sm > Y) {
            break;
        }
    }
    ans = min(ans, ans2);
    cout << ans << endl;
    return 0;
}