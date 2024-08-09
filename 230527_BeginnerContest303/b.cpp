#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    set<pair<int,int>> st;    
    int a;
    rep(i,M) {
        int last = -1;
        rep(j,N) {
            cin >> a;
            int b=a, c=last;
            last = a;
            if (c == -1) continue;            
            if (c<b) swap(b,c);
            st.insert({b,c});
        }
    }
    
    
    cout << (N*(N-1)/2 - (int)st.size()) << endl;
    return 0;
}