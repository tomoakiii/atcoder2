#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll mx = 0, mxind = 0, sm=0;
    for(int i=0; i<N;i++) {
        cin >> A[i] >> B[i];
        sm+=A[i];
        if (B[i]-A[i] > mx){
            mxind = i;
            mx = B[i]-A[i];
        }
    }

    cout << sm+mx << endl;
    return 0;
}