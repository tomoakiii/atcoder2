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

bool is_prime(long long n) {  // is n prime or not
    for (long long i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    ll N;
    cin >> N;

    ll Ns2 = sqrt(N);
    auto pn = Eratosthenes(Ns2);
    
    ll ans = 0;    
    ll j = pn.size()-1;

    rep(i, pn.size()) {
        ll p1 = pn[i];
        ll p2 = pn[j];
        while(p1*p1*p2*p2 > N) {
            j--;
            if(j < 0) break;
            if(i >= j) break;
            p2 = pn[j];
        }
        if(j < 0) continue;
        if(i >= j) continue;
        ans += j-i;
    }

    int sz = pn.size();
    rep(i, pn.size()) {
        ll p1 = pn[i];
        if(p1*p1*p1*p1*p1*p1*p1*p1 > N) break;
        ans++;
    }

/*
    vector<int> arr(sz);
    rep(i,9) arr[i] = -1;
	do {
        ll k = 1;
        rep(i,sz) {
            if(arr[i] == -1) {
                k *= pn[i];
            }
        }
		if(k <= N) ans++;
        else break;
	} while (next_permutation(arr.begin(), arr.end()));
*/	

    cout << ans << endl;

    return 0;
}