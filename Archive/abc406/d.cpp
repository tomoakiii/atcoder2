#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    ll H,W,N;
    cin >> H >> W >> N;
    vector<set<int>> sx(H);
    vector<set<int>> sy(W);
    rep(i,N) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        sx[x].insert(y);
        sy[y].insert(x);
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int t, p;
        cin>>t>>p;
        p--;
        if(t==1) {
            cout << sx[p].size() << endl;
            for(auto s: sx[p]) {
               sy[s].erase(p);
            }
            sx[p].clear();
        } else {
            cout << sy[p].size() << endl;
            for(auto s: sy[p]) {
                sx[s].erase(p);
            }
            sy[p].clear();
        }
    }
    return 0;
}