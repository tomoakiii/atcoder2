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
    ll N;
    cin >> N;
    auto et = Eratosthenes(5 * 55555);
    vector<ll> ans;
    auto e = et.lower_bound(55555);
    e--;
    while(true) {
        if(ans.size() == N) {
            rep(i,ans.size()) cout<<ans[i]<<((i==N-1)?"\n":" ");
            cout<<endl;
            return 0;
        }
        if(ans.size() < 4) {
            ans.push_back(*e);
            e--;
            if(e == et.end()) {
                cout<<-1<<endl;
                return 0;
            }
            continue;
        }
        vector<int> bit(ans.size(), 0);
        rep(i,4) bit[ans.size() - 1 - i] = 1;
        bool flg = true;
        do{
            ll sm = 0;
            rep(i,ans.size()) {
                if(bit[i]) sm += ans[i];
            }
            ll x = sm + *e;
            if(et.contains(x)) {
                flg = false;
                break;
            }
        } while(next_permutation(bit.begin(), bit.end()));
        if(flg) {
            ans.push_back(*e);
            e--;
            if(e == et.end()) {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    return 0;
}