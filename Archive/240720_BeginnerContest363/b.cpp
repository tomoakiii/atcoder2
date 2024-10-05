#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,T,P;
    cin >> N >> T >> P;
    vector<ll> L(N, 0);
    
    rep(i,N) {
        cin >> L[i];        
    }
    
    rep(j,T+3){
        ll cnt = 0;
        rep(i,N) {
            if (L[i] >= T) cnt++;
        }
        if(cnt >= P) {
            cout << j << endl;
            return 0;
        }
        rep(i,N) {
            L[i]++;
        }        
    }

    return 0;
}