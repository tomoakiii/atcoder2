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
    vector A(M, vector<ll>{});
    vector<ll> C(M), K(M);    
    for(int i=0; i<M;i++) {
        cin >> K[i] >> C[i];
        A[i].resize(K[i]);
        for(int j=0; j<K[i]; j++){
            cin >> A[i][j];
            A[i][j]--;          
        }        
    }
    
    vector<int> ord(M);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return C[i] < C[j]; });
    ll sm = 0;    
    dsu UF(N);
    for(int i=0; i<M; i++){
        ll p = ord[i];
        ll rep = A[p][0];                  
        for (int j=1; j<K[p]; j++){
            ll q = A[p][j];                        
            if (!UF.same(rep, q)){
              UF.merge(rep, q);
              sm += C[p];
            }            
        }
    }    
    if (UF.groups().size() == 1) cout << sm << endl;
    else cout << -1 << endl;
    return 0;
}