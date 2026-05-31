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
    string S;
    cin>>S;
    vector abc(N+1, vector<ll>(3));
    rep(i,N) {
        int x = S[i]-'A';
        abc[i+1][x]++;
    }
    unordered_map<ll,ll> ab, bc, ca;
    map<pair<ll,ll>, ll> abbc, bcca, caab;
    abbc[{0,0}]++;
    bcca[{0,0}]++;
    caab[{0,0}]++;

    map<tuple<ll,ll,ll>, ll> cmp;
    rep(k,3) rep(i,N) {
        abc[i+1][k] += abc[i][k];
    }
    ab[0]++; bc[0]++; ca[0]++;
    cmp[make_tuple(0,0,0)]++;
    ll ans=0;
    for(int i=1; i<=N; i++) {
        ll sm=0;
        int d0 = abc[i][0] - abc[i][1]; /*a-b*/
        if(ab.contains(d0)) sm += ab[d0];
        // cerr << ab[d0] << " ";
        ab[d0]++;

        int d1 = abc[i][1] - abc[i][2];
        if(bc.contains(d1)) sm += bc[d1];
        // cerr << bc[d1] << " ";
        bc[d1]++;

        int d2 = abc[i][2] - abc[i][0];
        if(ca.contains(d2)) sm += ca[d2];
        // cerr << ca[d2] << " ";
        ca[d2]++;

        pair<ll,ll> key0 = {d0,d1};
        if(abbc.contains(key0)) sm -= abbc[key0];
        // cerr << abbc[key0] << " ";
        abbc[key0]++;

        pair<ll,ll> key1 = {d1,d2};
        if(bcca.contains(key1)) sm -= bcca[key1];
        // cerr << bcca[key1] << " ";
        bcca[key1]++;

        pair<ll,ll> key2 = {d2,d0};
        if(caab.contains(key2)) sm -= caab[key2];
        // cerr << caab[key2] << " ";
        caab[key2]++;

        tuple<ll,ll,ll> p = make_tuple(d0, d1, d2);
        if(cmp.contains(p)) sm+=cmp[p];
        // cerr << cmp[p] << " ";
        cmp[p]++;

        // cerr<<endl;

        ans += (i - sm);
    }
    cout<<ans<<endl;
    return 0;
}