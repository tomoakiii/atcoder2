#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll n[6];
    rep(i, 6) cin>>n[i];
    ll v[] = {1, 5, 10, 50, 100, 500};
    int N;
    cin >> N;
    bool flg = true;
    rep(i, N) {
        ll X;
        cin >> X;
        for (int j=5; j>=0; j--){
            ll p = min(X/v[j], n[j]);
            n[j] -= p;
            X -= p * v[j];
        }
        if (X!=0) {
            flg = false;
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}