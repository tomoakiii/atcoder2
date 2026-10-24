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
typedef modint1000000007 mint;

vector<unordered_set<ll>> prime_factorization_vector(vector<ll> &vec, ll M) {
    vector<bool> is_prime(M + 1, true );
    vector<ll> pre(M+1);
    vector<ll> P;
    rep(j,M+1) pre[j] = j;
    for( ll i = 2; i*i <= M; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= M; j += i )
            {
                is_prime[ j ] = false;
                pre[ j ] = i;
            }
        }
    }
    int sz = vec.size();
    vector<unordered_set<ll>> ret(sz);
    rep(i, sz) {
        ll v = vec[i];
        while(v != 1) {
            ll p = pre[v];
            ret[i].insert(p);
            // cerr<<i<<" "<<p<<endl;
            v /= p;
        }
    }
    return ret;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll g = 1;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    auto ret = prime_factorization_vector(A,1e6);
    map<ll,ll> mp;
    ll mn = INF;
    rep(i,N){
        ll a = A[i];
        chmin(mn,a);
        for(auto s:ret[i]){
            ll cnt = 0;
            while(a%s == 0) {
                cnt++;
                a/=s;
            }
            chmax(mp[s],cnt);
        }
    }
    mint ans = 1;
    for(auto [s,cnt]:mp){
        rep(j,cnt) ans*=s;
    }
    ans /= mn;
    cout << ans.val() << endl;
    return 0;
}