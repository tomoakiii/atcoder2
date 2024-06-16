#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N, 0);
    vector FF(N, vector<bool>(100, false));
    vector F(N, vector<int>{});    
    
    for(int i=0; i<N;i++) {
        int C;
        cin >> P[i] >> C;
        for (int j=0; j<C; j++){
            ll f;
            cin >> f;
            f--;
            F[i].push_back(f);
            FF[i][f] = true;
        }
    }    
    for(int i=0; i<N;i++) for(int j=0; j<N; j++) {
        if(i==j) continue;
        if(F[i].size() > F[j].size()) continue;
        if (P[i] < P[j]) continue;
        bool flg = true;
        for (auto f: F[i]){
            if (!FF[j][f]) {
                flg = false;
            }
        }
        if (!flg) continue;
        if ( F[i].size() < F[j].size() || P[i] > P[j] ) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}