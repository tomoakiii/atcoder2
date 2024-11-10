#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N, Q;
    cin >> N >> Q;
    vector<bool> A(N, true);
    int t;
    for(int i=0; i<Q; i++){
        cin >> t;
        t--;
        A[t] = !A[t];
    }
    int sm=0;
    for(auto a:A) {
        if(a) sm++;
    }
    cout << sm << endl;
    return 0;
}