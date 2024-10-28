#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    string S;
    cin >> N >> M >> S;
    int dtmp = 0, etmp = 0;
    int buyT = 0;
    for (int i=0; i<N; i++){
        if (S[i] == '0') {
            dtmp = 0;
            etmp = 0;
        } else if (S[i] == '1') {    
            dtmp++;        
        } else {
            etmp++;
        }
        buyT = max(buyT, max(0, dtmp - M) + etmp);
    }

    std::cout << buyT << endl;
    return 0;
}