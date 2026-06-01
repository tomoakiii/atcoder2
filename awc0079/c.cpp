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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i]>>B[i];

    while(Q--){
        int query;
        cin >> query;
        if(query == 1){
            int i;
            ll a,b;
            cin >> i >> a >> b;
            i--;
            A[i]=a;
            B[i]=b;
        } else {
            ll d; cin>>d;
            ll aa=0,bb=0;
            bool flg=false;
            ll mx=0;
            ll Asm=0, Bsm=0;
            rep(i,N){
                aa+=A[i],bb+=B[i];
                if(bb-aa>=d){
                    cout<<i+1<<endl;
                    flg=true;
                    break;
                }
                chmax(mx,bb-aa);
                Asm+=A[i];
                Bsm+=B[i];
            }
            if(flg)continue;
            if(Asm>=Bsm){
                cout<<-1<<endl;
                continue;
            }
            ll BA=Bsm-Asm;
            ll p = (d-mx+BA-1)/BA;
            ll ans=p*N;
            ll rm = d - p*BA;
            ll aaa=0,bbb=0;
            rep(i,N){
                aaa+=A[i],bbb+=B[i];
                if(bbb-aaa>=rm){
                    cout<<ans+i+1<<endl;
                    break;
                }
            }

        }
    }
    return 0;
}