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

vector<ll> Eratosthenes_cntP(ll M)
{
    vector<ll> v(M);
    for( int i = 2; i < M; i++ )
    {
        if(v[i] == 0) for (int j = i; j < M; j+=i) v[j]++;
    }
    return v;
}


int main(){
    ll Q;
    cin >> Q;
    const ll A = 1E6 + 1;
    vector e = Eratosthenes_cntP(A);
    vector<ll> n4{};
    rep(i, A) {
        if(e[i] == 2) n4.push_back(i * i);
    }
    while(Q--){
        ll a;
        cin >> a;
        auto it = lower_bound(n4.begin(), n4.end(), a);
        if(*it > a) it--;
        cout << *it << endl;
    }
    return 0;
}