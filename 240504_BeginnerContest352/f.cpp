#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N;i++) {
        cin >> A[i];        
    }
    cout << A[0] << endl;
    return 0;
}