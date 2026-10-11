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
    vector<pair<int,char>> col;
    vector<int> mask(N,0);
    vector til(N, vector<pair<int,int>>{});
    for(int i=1;i<=Q;i++){
        int op; cin>>op;
        if(op==1){
            int x; cin>>x; x--;
            if(mask[x]!=-1){ // to close
                til[x].push_back({mask[x],i-1});
                mask[x]=-1;
            } else { // to open
                mask[x]=i;
            }
        } else {
            char c; cin>>c;
            col.push_back({i,c});
        }
    }
    rep(i,N){
        if(mask[i]!=-1){
            til[i].push_back({mask[i],Q});
        }
        reverse(til[i].begin(),til[i].end());
    }
    rep(i,N){
        bool flg=false;
        if(col.empty()){
            cout<<'a';
            continue;
        }
        for(auto [st,ed] : til[i]){
            pair<int,char> key = {ed, 'z'};
            auto it = upper_bound(col.begin(),col.end(),key)-col.begin();
            if(it-1<0) continue;
            auto [j,c] = col[it-1];
            if(j>=st){
                cout<<c;
                flg=true;
                break;
            }
        }
        if(!flg)cout<<'a';
    }
    cout<<endl;
    return 0;
}