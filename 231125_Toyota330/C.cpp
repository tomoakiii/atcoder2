#include <bits/stdc++.h>
using namespace std;

int main(){

    long long D, tcnt=0, tmpp=0;
    cin >> D;
    vector<long long> arpow((long)sqrt((double)D)+2);
    do {
        tmpp = tcnt * tcnt;
        arpow[tcnt] = tmpp;
        tcnt++;
    } while(tmpp <= D);

    long indy = tcnt-1;
    long long anmin = D, tmpmin = D;
    for(long i=0 ; i < tcnt; i++){
        while(indy>=i){
            long long tmpmin2=abs(arpow[i] + arpow[indy] - D);
            anmin = std::min(anmin, tmpmin2);
            if (tmpmin2 > abs(arpow[i] + arpow[indy-1] - D))
            {
                indy--;
                continue;
            } else {
                break;
            }
        }
    }
    std::cout << anmin << endl;
    return 0;
}