#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    struct QAB{
        int Q;
        int A;
        int B;
    };
    vector<QAB> qab(N);
    for (int n=0; n<N; n++)cin >> qab[n].Q;
    for (int n=0; n<N; n++)cin >> qab[n].A;
    for (int n=0; n<N; n++)cin >> qab[n].B;
    int maxc = 0;
    for (int i=0; i<=1000000; i++){
        int tmpmin = 1000000;
        for (int n=0; n<N; n++){
            if (i * qab[n].A > qab[n].Q){
                cout << maxc << endl;
                return 0;
            }
            if (qab[n].B == 0) {
                
            } else {
                tmpmin = min(tmpmin, (qab[n].Q - i*qab[n].A)/qab[n].B );
            }
        }
        maxc = max(maxc, i+tmpmin);
    }
    cout << maxc << endl;
    return 0;
}

