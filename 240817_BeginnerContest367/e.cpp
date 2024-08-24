#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;    
    vector<int> X(N, -1), A(N, 0);
    rep(i,N) {
        int z;
        cin>>z;
        z--;
        X[z] = i;
    }
    rep(i,N) cin>>A[i];

    
    vector<bool> visit(N, false);
    auto f = [&](auto f, int cur)->int{
        if (X[cur] == -1) return -1;
        if (visit[cur]) return cur;
        visit[cur] = true;
        f(f, X[cur]);
    };
    int lp;
    rep(i,N) if(X[i]!=-1) {
        lp = f(0, i);
        if (lp != -1) break;
    }
    

    vector<int> lpv;
    int cntl = 0;
    vector<bool> visit2(N, false);
    auto f2 = [&](auto f2, int cur, int stt)->void{
        lpv.push_back(cur);
        cntl++;
        visit2[cur] = true;
        if (X[cur] == stt) return;        
        f2(f2, X[cur], stt);
    };
    
    f2(f2, lp, lp);

    vector<int> out(N);
    rep(i, N) {
        if (visit2[i]) out[i] = lpv[K%lpv.size()];
        if (!visit2[i]) {
            vector<int> tlv;
            auto f3 = [&](auto f3, int cur)->void{
                tlv.push_back(cur);
                cntl++;
                visit2[cur] = true;
                if (X[cur] == -1) return;
                f3(f3, X[cur]);
            };
            f3(f3, i);
            rep(i,tlv.size()){
                if(i+K < tlv.size()) out[i] = tlv[i+k];
                else out[i] = tlv[tlv.size()-1];
            }
        }
    }

    rep(i, N) {        
        cout<<A[out[i]]<<" ";
    }
    
    cout << endl;
    return 0;
}