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
    vector<bool> is_prime(N + 1, true );
    set<ll> P;
    for( ll i = 2; i*i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
        }
    }
    for(ll i=2; i<=N; i++) {
        if(is_prime[i]) P.insert(i);
    }
    return P;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S; cin>>S;
    set<char> st;
    auto primes = Eratosthenes(1e7);
    for(auto c:S){
        st.insert(c);
    }
    int ind = 0;
    map<char,int> mp;
    for(auto c:st){
        mp[c] = ind++;
    }
    vector<int> ord(10);
    rep(i,10) ord[i]=i;
    do{
        if(ord[mp[S[0]]] == 0) continue;
        string p = S;
        rep(i,S.size()){
            p[i] = ord[mp[S[i]]] + '0';
        }
        ll v = stol(p);
        if(primes.contains(v)){
            cout << p << endl;
            return 0;
        }
    }while(next_permutation(ord.begin(),ord.end()));
    cout << -1 << endl;
    return 0;
}