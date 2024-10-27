#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int dist[] = {3,1,4,1,5,9};
    char p,q;
    cin >> p >> q;
    int pp, qq;    
    pp = p-'A';
    qq = q-'A';
    if(qq<pp) swap(qq, pp);    
    ll ans = 0;
    for (int i = pp; i < qq; i++){
        ans += dist[i];
    }
    
    cout << ans << endl;
    return 0;
}