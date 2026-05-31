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
        ll N;
        cin>>N;
        ll p;
        for(int i=2; i<N; i++) {
            if ( (N%i) == 0) {
                p = i;
                break;
            }
        }
        N = N/p;
        ll q;
        if ( (N%p) == 0) {
            q = N/p;
        } else {
            q = sqrt(N);
            swap(p, q);
        }
        cout << p << " " << q << endl;
    }
    
    return 0;
}