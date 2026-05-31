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
            P.insert( i );
        }
    }
    return P;
}



int main(){
    const ll M = 200000;
    auto D = Eratosthenes(M);
    vector<ll> P(M+1);
    for(ll i=1; i<=M-1; i+=2) {
        if(D.contains(i) && D.contains((i+1)/2)) P[i] = 1;
    }
    rep(i, M-1) {
        P[i+1] += P[i];
    }
    ll Q; cin>>Q;
    while(Q--) {
        ll l,r; cin>>l>>r;
        cout<<P[r]-P[l-1]<<endl;
    }
    return 0;
}