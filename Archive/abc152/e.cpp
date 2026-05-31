#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef modint1000000007 mint;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


/*
    行列の要素を全部高速に素因数分解する方法
    https://atcoder.jp/contests/abc177/editorial/82
    fast prime factorization applied for all members in vector:
    if A = {4, 6, 10}, call prime_factorization_vector(A, 10).
    then, the return is 
    X = {
        {2},
        {2, 3},
        {2, 5}
    }
    the compute time is O(A log log A + M log A)
*/
vector<vector<pair<ll,ll>>> prime_factorization_vector(vector<ll> &vec, ll M) {
    vector<bool> is_prime(M + 1, true );
    vector<ll> pre(M+1);
    vector<ll> P;
    rep(j,M+1) pre[j] = j;
    for( ll i = 2; i <= M; i++ )
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
    vector ret(sz, vector<pair<ll,ll>>{});
    rep(i, sz) {
        ll v = vec[i];
        while(v != 1) {
            ll p = pre[v];            
            ll t = 0;
            while(v%p == 0) {
                t++;
                v/=p;
            }
            ret[i].push_back({p,t});        
        }
    }
    return ret;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll M = 1000000;
    auto v = prime_factorization_vector(A, M);
    unordered_map<ll,ll> mx;
    map<ll, unordered_map<ll,mint>> mp;
    for(auto vs: v) {
        for(auto [x, cnt]: vs) {
            chmax(mx[x], cnt);
        }
    }
    mint mg = 1;
    
    for(auto [x, mn]: mx) {
        mint t = 1;
        rep(i, mn){
            // mp[x][i] = t;
            mg *= x;
            //t *= x;
        }
    }

    mint ans = 0;
    /*
    for(auto vs: v) {
        mint tmp = 1;
        for(auto [x, mn]: mx) {
            tmp *= mp[x][mn-vs[x].second];
        }
        ans += tmp;
    }
    */
    rep(i,N) {
        ans += mg/A[i];
    }
    cout << ans.val() << endl;
    return 0;
}