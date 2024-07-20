#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> L(N, 0);
    vector<ll> R(N, 0);
    ll lsm = 0, rsm = 0;
    rep(i, N) {
        cin >> L[i] >> R[i];
        lsm += L[i];
        rsm += R[i];
    }
    if (lsm > 0 || rsm < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (abs(lsm) >= abs(rsm)){
        ll x = lsm * -1; 
        ll t;
        rep(i, N) {                    
            t = min(R[i] - L[i], x);
            x -= t;        
            cout << (L[i] + t) << " ";            
        }
        cout << endl;
        return 0;
    }

    
    ll x = rsm; 
    ll t;
    rep(i, N) {                    
        t = min(R[i] - L[i], x);
        x -= t;        
        cout << (R[i] - t) << " ";            
    }
    cout << endl;

    return 0;
}