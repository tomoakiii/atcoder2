#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto &a: A) cin>>a;
    ll s, t;
    for(int i=0; i<N-1; i++){
        cin >> s >> t;
        A[i+1] += (A[i]/s) * t;
    }
    cout << A[N-1] << endl;
    return 0;
}

