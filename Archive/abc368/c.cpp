#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef  long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> H(N, 0);
    rep(i,N) cin>>H[i];

    ll cnt = 0;
    rep(i, N) {
        // while(cnt%3 != 0 && H[i] > 0) {
        //     cnt++;            
        //     H[i]--;
        // }
        ll k = H[i]/5;
        H[i] -= (k * 5);
        cnt += (k * 3);
        while(H[i] > 0) {
            cnt++;
            if (cnt%3 == 0) H[i] -= 3;
            else H[i]--;
        }
    }
    
    cout << cnt << endl;
    return 0;
}