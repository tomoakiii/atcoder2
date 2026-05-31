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

int main(){
    ll N;
    cin >> N;
    ll ok = 1, ng = 1e6 + 5;
    while(ng - ok > 1) {
        ll c = (ok + ng) / 2;
        if(c*c*c > N) ng = c;
        else ok = c;
    } 
    ll ans = 0;
    vector v = Eratosthenes(ok);
    for(int i = 1; i < v.size(); i++) {
        ll c = v[i];
        ll mx = N/(c*c*c);
        int id = lower_bound(v.begin(), v.end(), mx) - v.begin();
        if(v[id] * c * c * c > N) id--;
        chmin(id, i-1);
        ans += id+1;
    }
    cout << ans << endl;
    return 0;
}