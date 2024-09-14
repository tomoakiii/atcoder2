#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

using mint = modint998244353;


mint mk[1001];
mint mkinv[1001];

void init(){
    mint ret = 1;
    mk[0] = 1;
    mkinv[0] = 1;
    for(int i=1; i<=1000; i++) {
        ret *= i;
        mk[i] = ret;
        mkinv[i] = 1/ret;
    }
}

mint CMB(ll a, ll b){ // aCb    
    mint ret = mk[a];
    ret = ret * mkinv[a-b];
    ret = ret * mkinv[b];
    return ret;
}


int main(){
    init();
    ll K;
    cin >> K;
    vector<ll> C{};
    ll c;
    int Z=26;
    for(int j=0; j<Z; j++) {
        cin >> c;
        if (c > 0) C.push_back(c);
    }
    if (C.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    Z = (int)C.size();
    vector<mint> dp(K+1); // length, alphabet    
    for(int i=0; i<=min(K, C[0]); i++){ // first alphabet scanning 
        dp[i] = 1;
    }

    for(int j=1; j<Z; j++){ // alphabet scanning from second
        auto ldp = dp;
        for(int k=0; k<K; k++){ // base length
            for(int i=1; i<=C[j] && (i+k)<=K; i++) // how many letters of the character added    
            {
                dp[k+i] += ldp[k] * CMB(k+i, i);
            }
        }        
    }
    mint ans = 0;
    for(int i=1; i<=K; i++) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}