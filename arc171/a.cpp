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
    ll T;
    cin >> T;
    while(T--){
        ll N, A, B;
        cin >> N >> A >> B;
        if(A > N) {
            cout << "No" << endl;
            continue;
        }
        ll rN = N - A;
        ll mx = rN * min((N+1)/2, rN);
        if (B > mx) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
   return 0;
}