#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    rep(i, N){
        ll h;
        cin >> h;
        if (M < h) {
            cout << i << endl;
            return 0;
        }
        M-=h;
    }
    cout << N << endl;
    return 0;
}