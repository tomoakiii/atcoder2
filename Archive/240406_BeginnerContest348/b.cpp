#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<ll> X(N);
    vector<ll> Y(N);
    for(int i=0; i<N; i++) {
        cin >> X[i] >> Y[i];        
    }

    vector<ll> mnDis(N, 0);
    vector<int> an(N, INFi);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {            
            ll dst = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]); 
            if (mnDis[i] < dst){
                mnDis[i] = dst;
                an[i] = j;
            } else if (mnDis[i] == dst) {
                an[i] = min(an[i], j);
            }
            if (mnDis[j] < dst){
                mnDis[j] = dst;
                an[j] = i;
            } else if (mnDis[j] == dst) {
                an[j] = min(an[j], i);
            }
        }        
    }
    
    for(int i=0; i<N; i++) {
        cout << an[i]+1 << endl;
    }
    
    return 0;
}