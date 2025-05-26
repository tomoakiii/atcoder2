#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

set<ll> Eratosthenes(const ll N )
{
    vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    set<ll> P;
    for( ll i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.insert(i);
        }
    }
    return P;
}


int main(){
    ll a,b,c,d;
    cin >> a>>b>>c>>d;
    auto v = Eratosthenes(200);
    for(int i = a; i<=b; i++) {
        bool flg = true;
        for(int j = c; j<=d; j++) {
            if(v.contains(i+j)) flg = false;
        }
        if(flg) {
            cout<<"Takahashi" <<endl;
            return 0;
        }        
    }
    cout<<"Aoki" <<endl;
    return 0;
}