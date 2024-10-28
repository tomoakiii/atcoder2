#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;



int main(){
    int N, K;
    cin >> N >> K;
    int a;    
    for (int i=0; i<N; i++){
        cin >> a;
        if (a % K == 0) {
            cout << a/K << " ";
        }
    }
    cout << endl;
    
    return 0;
}