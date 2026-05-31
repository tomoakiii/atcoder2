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
typedef modint998244353 mint;
int main(){
    int T; cin>>T;
    ll M = 1e7;
    vector<bool> is_prime(M + 1, true );
    vector<ll> pre(M+1);
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


    while(T--) {
        ll N;
        cin >> N;
        unordered_map<ll,pair<ll,int>> rank0;
        unordered_map<ll,pair<ll,int>> rank1;
        rep(i,N) {
            ll a; cin>>a;
            ll b = a;
            vector<ll> st;
            while(a != 1) {
                ll p = pre[a];
                st.push_back(p);
                a /= p;
            }
            for(auto s: st) {
                int cnt = 0;
                while(b > 0) {
                    if(b%s != 0) break;
                    cnt++;
                    b /= s;
                }
                if(!rank0.contains(s)) rank0[s] = {cnt, i};
                else if(!rank1.contains(s)) {
                    rank1[s] = {cnt, i};
                    if(rank0[s].first < rank1[s].first) {
                        swap(rank0[s], rank1[s]);
                    }
                } else if (rank0[s].first < cnt) {
                    rank1[s] = rank0[s];
                    rank0[s] = {cnt, i};
                } else if (rank1[s].first < cnt) {
                    rank1[s] = {cnt, i};
                }
            }
        }
        mint lcm = 1;
        vector<mint> change(N,1);
        for(auto [s, vj]: rank0) {
            auto [v, j] = vj;
            rep(kkk, v) lcm *= s;
            if(!rank1.contains(s)) {
                rep(kkk, v) change[j] *= s;
            } else {
                auto [v2,j2] = rank1[s];
                rep(kkk, v-v2) change[j] *= s;
            }

        }

        rep(i,N) {
            mint ans = lcm * change[i].inv();
            cout << ans.val() << " ";
        }
        cout << endl;
    }
    return 0;
}