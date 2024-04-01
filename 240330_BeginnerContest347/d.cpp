#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int N = 60;

int main(){
    ll a, b, C;
    cin >> a >> b >> C;
    vector<int> Z(N, 0);
    int cnt = 0;
    vector<int> posW, posB;
    while(C>0){
        Z[cnt] = (C%2);
        C/=2;        
        cnt++;
    }
    for (int i=0; i<Z.size(); i++){
        if (Z[i] == 1) posB.push_back(i);
        else posW.push_back(i);
    }
    vector<int> X, Y;    
    int cw;
    for (cw = 0; cw <= a; cw++){        
        vector<int> X(N, 0), Y(N, 0);
        int cntW = 0;
        for(int i=0; i<posW.size(); i++){
            if (cntW < cw){
                X[posW[i]] = 1;
                cntW++;
            } else {
                break;
            }
        }
        if (cntW < cw) continue;
        for(int i=0; i<posB.size(); i++){
            if (cntW < a){
                X[posB[i]] = 1;
                cntW++;
            } else {
                break;
            }
        }
        if (cntW < a) continue;
        int cb = 0;
        for (int i=0; i<N; i++){
            Y[i] = Z[i] ^ X[i];
            if (Y[i] == 1) cb++;
        }
        if (cb == b) {
            ll out1=0, out2=0;
            ll p2=1;
            for (int i=0; i<N; i++){
                out1 += X[i] * p2;
                out2 += Y[i] * p2;
                p2*=2;
            }
            cout << out1 << " " << out2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}