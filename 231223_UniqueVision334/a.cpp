#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A, M, L, R;
    cin >> A >> M >> L >> R;
    L-=A;
    R-=A;
    L += L%M;
    R -= R%M;
    cout << (R-L)/M+1 << endl;
    return 0;
}