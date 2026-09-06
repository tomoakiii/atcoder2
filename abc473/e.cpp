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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N) {
        A[i+1]+=A[i];
        A[i+1] %= K;
    }
    map<ll, deque<ll>> mp;
    rep(i,N){
        mp[A[i+1]].push_back(i+1);
    }
    ll ans = 0;
    ll last = INF;
    if(mp.contains(0)) {
        ans++;
        last = mp[0][0];
    } else {
        last = -1;
    }
    rep(i,N) {
        if(mp.contains(A[i]) && *mp[A[i]].rbegin() > i) {
            if(i>=last) {
                ans++;
                last = INF;
            }
            ll it = upper_bound(mp[A[i]].begin(), mp[A[i]].end(), i) - mp[A[i]].begin();

            /*
            if(last >= mp[A[i]][it]) {
                cerr << "dbg1::; " << i << " " << last << "-->" << mp[A[i]][it] << endl;
            } else {
                cerr << "dbg2::; " << i << " " << last << "-->" << mp[A[i]][it] << endl;
            }
            */

           chmin(last, mp[A[i]][it]);
        }
    }
    cout << ans << endl;
    return 0;
}