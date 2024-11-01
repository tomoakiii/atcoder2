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


vector<int> Eratosthenes(const int N )
{
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}


map<ll, int> prime_factorization(ll K){
    map<ll, int> mp;
    ll k = K;
    ll i=2;
    while(true){
        while(k%i == 0) {
            mp[i]++;
            k /= i;
        }
        if(i*i > K) break; // break here. for(; i*i<=K ;) is NG
        i++;
    }
    if (k!=1) mp[k]++; // don't forget to add the last piece (10=2x5)   
    return mp;
}


int main()
{
    int N;
    cin >> N;
    for( const auto &x: Eratosthenes( N ) )
    {
        cout << x << " ";
    }
    cout << endl;
    cout << endl;
    for(auto m: prime_factorization(N)) {
        cout << m.first << " x " << m.second <<endl;
    }

    return 0;
}