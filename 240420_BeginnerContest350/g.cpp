#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<ll> A(N-1);
    int sm = 0;
    for(int i=0; i<N-1; i++) {
        cin >> A[i];
        sm += A[i];
    }
    cout << -1 * sm << endl;
    
    return 0;
}