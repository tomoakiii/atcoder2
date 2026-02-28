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
    string S; cin>>S;
    int N=S.size();
    vector<bool> visit(N);
    vector<int> cnt(3);
    for(auto c:S) {
        if(c=='A') cnt[0]++;
        else if(c=='B') {
            if(cnt[0]==0)continue;
            cnt[0]--;
            cnt[1]++;
        }else{
            if(cnt[1]==0)continue;
            cnt[1]--;
            cnt[2]++;
        }
    }
    cout<<cnt[2]<<endl;
    return 0;
}