#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A, M, L, R;
    cin >> A >> M >> L >> R;
    L-=A;
    R-=A;
    if (L>0 && L%M != 0){
        L -= L%M;
        L += M;
    } else if (L<0 && L%M != 0) {
        L *= -1;
        L -= L%M;
        L *= -1;
    }
    if (R>0 && R%M != 0){
        R -= R%M;
    } else if (R<0 && R%M != 0) {
        R *= -1;
        R -= L%M;
        R += M;
        R *= -1;
    }
    if (L>R){
        cout << 0 << endl;
    } else {
        cout << (R-L)/M+1 << endl;
    }
    return 0;
}