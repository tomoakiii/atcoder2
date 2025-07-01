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


ll sm(ll a, ll b) {
    ll c = b*(b+1)/2;
    if(a==0) return c;
    ll d = (a-1)*(a)/2;
    return c-d;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    map<ll, int> mp;
    rep(i,N) {
        cin>>A[i];
        mp[-1*A[i]]++;
    }
    auto it = mp.begin();
    ll a = it->first * -1;
    ll p = it->second;
    ll ans = 0;
    it++;
    while(true){
        ll a2=0, p2=0;
        bool flg = true;
        if(it == mp.end()) {
            flg = false;
        } else {        
            a2 = it->first * -1;
            p2 = it->second;
        }
        if((a-a2)*p <= K) {
            K -= (a-a2)*p;
            ans += sm(a2+1, a) * p;
            p2 += p;
        } else {
            while(K) {
                if(a==0) {
                    cout << ans << endl;
                    return 0;
                }
                if(K>=p){
                    K -= p;
                    ans += a * p;
                    a--;
                } else {                    
                    ans += a * K;
                    a--;
                    K = 0;
                }
            }
        }
        if(!flg) break;
        swap(a, a2);
        swap(p, p2);
        it++;
    }
    cout<<ans<<endl;
    return 0;
}