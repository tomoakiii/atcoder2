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

    ll lpos[2] = {-1,-1};
    ll ans=0;
    rep(i,N){
        ll x;
        char s;
        cin >> x >> s;
        int k;
        if(s=='L') k=0;
        else k=1;
        if(lpos[k] != -1) ans+=abs(lpos[k]-x);
        lpos[k]=x;
    }
    cout << ans << endl;
    return 0;
}