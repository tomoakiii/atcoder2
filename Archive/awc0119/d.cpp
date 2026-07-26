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
    ll N,M;
    cin >> N >> M;
    deque<ll>D(M); 
    deque<pair<ll,ll>> EC(N);
    rep(i,N) cin>>EC[i].first>>EC[i].second;
    rep(i,M) cin>>D[i];
    sort(EC.begin(),EC.end());
    sort(D.begin(),D.end());
    ll ans = 0;
    while(!D.empty() && !EC.empty()){
        if(D.front() <= EC.front().first){
            D.pop_front();
            EC.front().second--;
            ans++;
            if(EC.front().second == 0) EC.pop_front();
        } else {
            EC.pop_front();
        }        
    }
    cout << ans << endl;
    return 0;
}