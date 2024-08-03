#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, Q;
    cin >> N >> Q;    
    vector<ll> A(N);    
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());    
        
    while(Q--) {
        ll b;
        int k;
        cin >> b >> k;     
        ll ng = -1, ok = 2e8+10;
        ll mid;
        while (ok - ng > 1) {            
            mid = (int)(ng+ok)/2;
            auto f = [&](ll key)->bool{
                auto it = lower_bound(A.begin(), A.end(), b - key);
                auto it2 = upper_bound(A.begin(), A.end(), b + key);
                return (it2-it)>=k;
            };
            if (f(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;

    }    
    return 0;
}