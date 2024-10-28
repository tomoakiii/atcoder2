#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll a;
    rep(i,N) cin >> A[i];

    mint invN = 1;
    invN = invN / N;
    mint ans = 0;
    mint Psm = invN;

    rep(i,N) {
        ans = ans + A[i] * Psm;
        Psm += Psm*invN;
    }
    
    cout << ans.val() << endl;
    return 0;
    
}