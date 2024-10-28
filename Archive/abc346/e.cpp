#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int H, W, M;    
    cin >> H >> W >> M;    
    vector<int> T(M), A(M), X(M);
    for(int i=0; i<M; i++){
        cin >> T[i] >> A[i] >> X[i];
        A[i]--;
    }
    map<int, ll> col;
    vector<bool> lkW(W, false), lkH(H, false);
    int sumlw = 0, sumlh = 0;        
    for(int i=M-1; i>=0; i--){
        if (T[i] == 1){
            if (lkH[A[i]]) continue;
            lkH[A[i]] = true;
            sumlh++;
            if (W>sumlw) col[X[i]] += W - sumlw;
        } else {
            if (lkW[A[i]]) continue;
            lkW[A[i]] = true;
            sumlw++;
            if (H>sumlh) col[X[i]] += H - sumlh;
        }
    }
    for(int i=0; i<H; i++){
        if (lkH[i]) continue;
        if (W > sumlw) col[0] += W - sumlw;
    }
    cout << col.size() << endl;
    for(auto it=col.begin(); it!= col.end(); it++){
        cout << it->first << " " << it->second << endl;
    }


   return 0;
}