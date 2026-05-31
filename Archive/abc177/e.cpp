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


/*
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
vector<unordered_set<ll>> prime_factorization_vector(vector<ll> &vec, ll M) {
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll M = 1E6;
    auto f = prime_factorization_vector(A, M);
    vector<int> nm(M + 1);
    bool pw = true;
    for(auto st: f) {
        for(auto s: st) {
            nm[s]++;
            if(nm[s] > 1) pw = false;
        }
    }
    for(auto s: f[0]) {
        if(nm[s] == N) {
            cout<<"not coprime"<<endl;
            return 0;
        } 
    }
    if(!pw) cout<<"setwise coprime"<<endl;
    else cout<<"pairwise coprime"<<endl;
    return 0;
}