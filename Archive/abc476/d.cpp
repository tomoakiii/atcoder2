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
    ll N,M,K;
    cin >> N >> M >> K;
    ll X,Y; cin>>X>>Y;
    vector<pair<ll,bool>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second=true;
    }
    rep(i,M) {
        cin>>A[i+N].first;
        A[i+N].second=false;
    }
    sort(A.begin(),A.end());
    ll ans = 0;
    for(auto [a,b]:A){
        if(b){ // A
            if(X>a){
                X-=a;
                ans++;
            } else{
                ll p = (a-X+K-1)/K;
                Y-=p;
                ll rm=p*K-Y;
                X+=rm;
                ans++;
            } else {
                break;
            }
        } else {

        }
    }
    cout<<ans<<endl;
    return 0;
}