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

int main(){
    ll N;
    cin >> N;
    ll M = 1e6;
    vector<ll> cnt(M+1,INF), cnt2(M+1,-1);
    cnt[0] = cnt2[0] = 0;
    cnt[1] = cnt2[1] = 0;
    cnt[2] = cnt2[2] = 1;
    vector<bool> is_prime(M + 1, true );
    vector<ll> mxg(M+1,INF);
    for( ll i = 2; i <= M; i++ )
    {
        if( is_prime[ i ] )
        {
            cnt[i] = cnt2[i] = 1;
            for( ll j = 2 * i; j <= M; j += i )
            {
                is_prime[ j ] = false;
                chmax(cnt2[j], 1+cnt2[j/i]*i);
                chmin(mxg[j], i);
            }
        }
    }

    for(ll i=2; i<=M; i++) {
        if(cnt[i]<=1)continue;
        ll p=i/mxg[i];
        chmin(cnt[i], cnt[p] * mxg[i]  + 1);
    }
    ll mn=0, mx=0;
    rep(i,N) {
        ll a; cin>>a;
        mn+=cnt[a];
        mx+=cnt2[a];
    }
    cout<<mn<<" "<<mx<<endl;

    return 0;
}