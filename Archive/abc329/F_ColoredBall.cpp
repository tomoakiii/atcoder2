#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;
int main(){
    int N, Q;
    cin >> N >> Q;
    int C;
    vector<set<int>> st(N);
    rep(i,N) {
        cin>>C;
        st[i].insert(C);
    }
    vector<int> ind(N);
    rep(i,N) {
        ind[i] = i;
    }
    while(Q--){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(ind[a] == -1) {
            // nothing
        } else if(ind[b] == -1) {
            ind[b] = ind[a];
            ind[a] = -1;
        } else {
            if(st[ind[a]].size() < st[ind[b]].size()){
                for(auto e: st[ind[a]]) {
                    st[ind[b]].insert(e);
                }
                ind[a] = -1;
            } else {
                for(auto e: st[ind[b]]) {
                    st[ind[a]].insert(e);
                }
                ind[b] = ind[a];
                ind[a] = -1;
            }
        }

        if (ind[b] == -1) {
            cout << 0 << endl;
        } else {
            cout << st[ind[b]].size() << endl;
        }
    }

    return 0;
}