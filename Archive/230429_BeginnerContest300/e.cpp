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
    vector A(N, 0);

    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    
    cout << sm << endl;
    return 0;
}