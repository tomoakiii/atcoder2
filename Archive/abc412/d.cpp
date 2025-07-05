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
    ll N, M;
    cin >> N >> M;
    vector<set<int>> uv(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].insert(v);
        uv[v].insert(u);
    }
    vector<int> ord(N); 
    rep(i,N) ord[i]=i;
    //vector<int> ord = {0,3,2,1,5,4};
    ll ans = INF;
    auto chk = [&uv, &N](vector<set<int>> &uv2)->ll{
        ll cnt = 0;
        rep(i,N) {
            for(auto s: uv[i]) {
                if(uv2[i].contains(s)) uv2[i].erase(s);
                else cnt++;
            }
            cnt+=uv2[i].size();
        }
        return cnt;
    };
    do{
        vector<set<int>> uv2(N);
        rep(i,N) {
            int cur = ord[i], nx = ord[(i+1)%N];
            uv2[cur].insert(nx);
            uv2[nx].insert(cur);
        }
        chmin(ans, chk(uv2)/2);

        if(N<6) continue;
        vector<set<int>> uv3(N);
        rep(i,3) {
            int cur = ord[i], nx = ord[(i+1)%3];
            uv3[cur].insert(nx);
            uv3[nx].insert(cur);
        }
        rep(i,N-3) {
            int cur = ord[i+3], nx;
            if(i+3==N-1) {
                nx = ord[3];                
            } else {
                nx = ord[i+4];
            }
            uv3[cur].insert(nx);
            uv3[nx].insert(cur);
        }
        chmin(ans, chk(uv3)/2);

        if(N<7) continue;
        vector<set<int>> uv4(N);
        rep(i,4) {
            int cur = ord[i], nx = ord[(i+1)%4];
            uv4[cur].insert(nx);
            uv4[nx].insert(cur);
        }
        rep(i,N-4) {
            int cur = ord[i+4], nx;
            if(i+4==N-1) {
                nx = ord[4];                
            } else {
                nx = ord[i+5];
            }
            uv4[cur].insert(nx);
            uv4[nx].insert(cur);
        }
        chmin(ans, chk(uv4)/2);
    }while(next_permutation(ord.begin(), ord.end()));
    cout<<ans<<endl;
    return 0;
}