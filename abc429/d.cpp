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
    ll N,M,C;
    cin >> N>>M>>C;
    map<ll,ll> mp;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        if(A[i] == 0) {
            A[i] = M;
        }
        mp[A[i]]++;
        mp[A[i]+M]++;
    }
    ll tmp = 0;   
    auto it = mp.begin(); 
    while(tmp < C) {
        auto [v,c] = *it;
        tmp += c;
        it++;
    }
    auto it2 = mp.begin();
    ll lastvb = 0;
    ll ans = 0;
    while(true) {
        while(tmp >= C){
            auto [newvb, cb] = *it2;
            if(newvb >= M) {
                ans += (M - lastvb) * tmp;
                cout << ans << endl;
                return 0;
            }            
            ans += (newvb - lastvb) * tmp;
            tmp -= cb;
            it2++;
            lastvb = newvb;            
        }
        while(tmp < C) {
            auto [v,c] = *it;
            tmp += c;
            it++;
        }
        
    }
    return 0;
}