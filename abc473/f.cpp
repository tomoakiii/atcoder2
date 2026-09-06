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
    ll N;
    string S;
    ll Q;
    cin >> N >> S >> Q;
    ll cnt = 0;
    fenwick_tree<ll> FT(N);
    rep(i,N) {
        if(S[i] != 'B') continue;
        if(i>0 && S[i-1]=='B')FT.add(i,1);
        if(i<N-1 && S[i+1]=='B')FT.add(i,1);
    }
    while(Q--){
        int quu; cin>>quu;

        if(quu == 1){
            int x; char c; cin>>x>>c; x--;
            if(S[x] == 'B' && c == 'A') {
                if(x>0 && S[x-1] == 'B') FT.add(x,-1);
                if(x<N-1 && S[x+1] == 'B') FT.add(x,-1);
            } else if (S[x] == 'A' && c == 'B'){
                if(x>0 && S[x-1] == 'B') FT.add(x,1);
                if(x<N-1 && S[x+1] == 'B') FT.add(x,1);
            }
            S[x] = c;
        } else {
            int l, r; cin >> l >> r;
            l--,r--;
            ll sm = FT.sum(l,r+1);
            if(l>0 && S[l]=='B' && S[l-1]=='B') sm--;
            if(r<N-1 && S[r]=='B' && S[r+1]=='B') sm--;
            if(sm<=0) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}