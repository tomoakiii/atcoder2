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
    ll N,Q,M;
    cin >> N >> Q >> M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    string S; cin>>S;
    while(M--){
        int op; cin>>op;
        if(op==1){
            int p; char c;
            cin>>p>>c;
            p--;
            S[p]=c;
        } else {
            ll ans=0;
            int st=0;
            vector<bool>visit(N);
            for(auto c:S){
                if(c=='B')st=0;
                if(c=='P'&&!visit[st])visit[st]=true,ans+=A[st];
                if(c=='R'&&st<N-1)st++;
                if(c=='L'&&st>0)st--;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}