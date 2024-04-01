#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<ll> C(N), cL0(N,0), cR0(N,0), cL1(N, 0), cR1(N, 0);
    ll cl0=0, cl1=0, cr0=0, cr1=0;
    for(auto &c:C) cin >> c;
    int exp = 0;
    for (int i=0; i<N; i++){
        if (S[i]-'0' == exp){
            cL0[i] = C[i] + cl0;
            cL1[i] = cl1;            
        } else {
            cL0[i] = cl0;
            cL1[i] = C[i] + cl1;            
        }
        cl0 = cL0[i];
        cl1 = cL1[i];
        exp = ((exp==0)?1:0);        
    }
    exp = ((N%2 == 0)?1:0);    
    for (int i=N-1; i>=0; i--){        
        if (S[i]-'0' == exp){
            cR0[i] = C[i] + cr0;
            cR1[i] = cr1;            
        } else {
            cR0[i] = cr0;
            cR1[i] = C[i] + cr1;            
        }
        cr0 = cR0[i];
        cr1 = cR1[i];
        exp = ((exp==0)?1:0);        
    }
    ll sm=INF;
    for(int i=0; i<N-1; i++){
        sm = min(sm, cL0[i] + cR1[i+1]);
        sm = min(sm, cL1[i] + cR0[i+1]);
    }
    cout << sm << endl;
    return 0;
}