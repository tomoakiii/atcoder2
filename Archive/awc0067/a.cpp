#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    while(Q--){
        int q; cin>>q;
        if(q==1){
            int a,b,v; cin>>a>>b>>v;
            a--,b--;
            A[a]-=v;
            A[b]+=v;
        } else if(q == 2) {
            int x,l,r; cin>>x>>l>>r;
            int cnt=0;
            l--,r--,x--;
            for(int i=l; i<=r; i++){
                if(A[i]>A[x]) cnt++;
            }
            cout<<cnt<<endl;
        } else {
            int l,r,v; cin>>l>>r>>v;
            l--,r--;
            for(int i=l; i<=r; i++){
                A[i]+=v;
            }
        }
    }
    return 0;
}