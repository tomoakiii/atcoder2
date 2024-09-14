#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll A,B;
    cin>>A>>B;
    ll ans = A/B;

    if(A%B != 0){
        ans++;
    }
    cout << ans << endl;
    return 0;
}