#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
vector<ll> Eratosthenes(const ll N )
{
    vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<ll> P;
    for( ll i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}


int main(){
    ll N, a, b, c;
    cin >> N;
    ll sN = (ll)sqrtl(N+1);
    vector pn = Eratosthenes(sN);
    int cind = pn.size()-1;
    ll ans = 0;
    while(cind>=0) {
        ll key = N/pn[cind]/pn[cind];
        auto bit = lower_bound(pn.begin(), pn.end(), key);
        int bind = bit - pn.begin();
        bind = min(cind-1, bind);
        while(bind>=0){
            ll key2 = key/pn[bind];
            auto ait = lower_bound(pn.begin(), pn.end(), key2);
            int aind = ait - pn.begin();
            aind = min(aind, bind-1);
            while(aind>=0){
                if (pn[aind]*pn[aind]*pn[bind]*pn[cind]*pn[cind] <= N) {
                    break;
                }
                aind--;
            }
            if (aind >= 0) {
                ans += aind + 1;
            }
            bind--;
        }
        cind--;
    }
    
    cout << ans << endl;
    return 0;
}