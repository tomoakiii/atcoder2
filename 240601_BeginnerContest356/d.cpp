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
    ll N, M;
    cin >> N >> M;    
    mint cnt = 0;
    vector<int> dM(60), dN(60);
    int ind=0;
    while(M > 0) {
        dM[ind++] = M%2;
        M /= 2;
    }
    ind=0;
    while(N > 0) {
        dN[ind++] = N%2;
        N /= 2;
    }
    rep(i, 60){
        if (dM[i] == 0) continue;
        ll sm;
        for (int j = i+1; j < 60; j++) {        
            if (dN[j] == 0) continue;                        
            if (i==j) sm = 1;
            else sm = (1 << (j-1));
            cnt = cnt + sm;        
        }
        sm = 0;
        for (int j = 0; j < i; j++){
            if(dN[j] == 0) continue;
            sm += (1 << j);
        }
        cnt = cnt + sm;
    }
    cout << cnt.val() << endl;
    return 0;
}