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
    ll N,K,T;
    cin >> N >> K >> T;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    A.push_back(T);
    sort(A.begin(),A.end());
    ll last = 0;
    ll ans = 0;
    for(auto a:A) {
        if(a>T)break;
        if(a <= last){
            chmax(last,a+K);
        } else {
            ll d = a - last;
            ll p = d/K;
            ans+=p;
            last += p*K;
            if(last<a){
                ans++;
                last+=K;
                chmax(last,a+K);
            } else {
                chmax(last,a+K);
            }
        }
    }
    cout << ans << endl;
    return 0;
}