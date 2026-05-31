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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> A(M);
    multiset<pair<ll,ll>> dwn;
    rep(i, M) {
        ll a,b; cin>>a>>b;
        A[i].first = a;
        A[i].second = a-b;
        dwn.insert({A[i].second, A[i].first});
    }    
    sort(A.begin(), A.end());
    ll ans = 0;
    while(A.size() > 0) {
        int i;
        while(true){            
            i = A.size()-1;
            if(i<0) break;
            if(A[i].first <= N) break;
            A.pop_back();
            dwn.erase(dwn.find({A[i].second, A[i].first}));            
        }
        if(dwn.empty()) break;
        auto [mnd, a] = *dwn.begin();        
        ll p = (N - a) / mnd;
        N -= p * mnd;
        ans += p;
        if(N >= a) {
            N-=mnd;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}