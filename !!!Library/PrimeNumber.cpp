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


vector<ll> Eratosthenes(const ll N )
{
    vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<int> P;
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


/* 
数列 V=(V1​, V2, …, V1000000) を0で初期化しておき、
1E6以下の各素数p について、すべてのp の倍数iに対しViに1を加算する操作を行うと最終的なViの値がiの素因数の種類数となります。
output -- v */ 
vector<ll> Eratosthenes_cntP(const int N )
{
    const ll M = 1E6 + 1;
    vector<ll> v(M);
    for( int i = 2; i < M; i++ )
    {
        if(v[i] == 0) for (int j = i; j < M; j+=i) v[j]++;
    }
    return v;
    /*
      2 -> 4 -> 6 -> 8 -> 10...
      3 -> 6 -> 9 -> 12 -> 15 ... // 6 was counted by 2's multiplying. Means 2 and 3 are prime factors of 6;
      (4 was shown. skip)
      5 -> 10 -> 15 -> ... // 10 was counted by 2's multiplying. Means 2 and 6 are prime factors of 10;
      (6 was shown)
      7 -> 14 -> ...
      (8 was shown)
      (9 was shown)
    */
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