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
typedef modint998244353 mint;



template<typename T=int>
vector<T> Eratosthenes(const T N)
{
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<T> P;
    for( T i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( T j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll N, D, K;
        cin >> N >> D >> K;
        K--;
        ll P = lcm(N, D);
        ll F = D*K;
        ll A = F/P;
        cout << F%N + A << endl;
    }
    return 0;
}