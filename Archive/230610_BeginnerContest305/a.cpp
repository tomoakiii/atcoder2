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
    ll mn = INF;
    ll ans = 0;
    rep(i, 21){
        if (mn > abs(i*5 - N)){
            mn = abs(i*5 - N);
            ans = i*5;
        }        
    }  
    
    cout << ans << endl;
    return 0;
}