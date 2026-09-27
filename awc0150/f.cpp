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
    ll N,Q;
    cin >> N >> Q;
    dsu UF(N);
    vector<int> num(N,1);
    while(Q--){
        int query; cin>>query;
        if(query==1){
            int a,b; cin>>a>>b; a--,b--;
            int la=UF.leader(a), lb=UF.leader(b);
            if(la==lb)continue;
            int na=num[la], nb=num[lb];
            int c = UF.merge(a,b);
            num[c] = na+nb;
        } else {
            int x; cin>>x; x--;
            cout<<num[UF.leader(x)]<<endl;
        }
    }
    return 0;
}