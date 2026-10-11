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
    ll Q;
    cin >> Q;
    string S,T; cin>>S>>T;
    vector<int> pos;
    int sz=S.size(), sz2=T.size();
    rep(i,sz){
        bool f=true;
        rep(j,sz2){
            if(i+j>=sz){
                f=false;
                break;
            }
            if(S[i+j]!=T[j])f=false;
        }
        if(f)pos.push_back(i);
    }
    while(Q--){
        int l,r; cin>>l>>r; l--,r--;
        if(pos.empty()){
            cout<<"No"<<endl;
            continue;
        }
        int it = lower_bound(pos.begin(),pos.end(),l)-pos.begin();
        int ed = pos[it] + sz2 - 1;
        if(it==pos.size()){
            cout<<"No"<<endl;
            continue;
        }
        if(ed <= r){
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }

    }
    return 0;
}