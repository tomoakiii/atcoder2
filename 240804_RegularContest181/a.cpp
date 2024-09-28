#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        int ans = 0;
        vector<ll> P(N);
        bool flgA=false, flgB=false;
        ll mx = 0;
        rep(i, N) {
            cin >> P[i];
            P[i]--;
            mx = max(mx, P[i]);
            if (P[i] == i && mx == i) flgB = true;
            if (P[i] != i) flgA = true;
        }        
        if (!flgA) ans = 0;
        else if (flgB){
            ans = 1;
        } else {
            ans = 2;
        }
        cout << ans << endl;

    }
    return 0;
}