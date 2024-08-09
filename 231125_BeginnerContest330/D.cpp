#include <bits/stdc++.h>
using namespace std;

int main(){

    long long N;
    cin >> N;
    vector<string> S(N);
    vector<int> cntR(N,0);
    vector<int> cntC(N,0);
    int cind=0;
    for (string &s:S){
        cin >> s;
        for (char &c:s){
            if (c=='o'){
                cntR[cind]++;
            }
        }
        cind++;
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (S[j][i]=='o'){
                cntC[i]++;
            }
        }
    }

    long long aout=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (S[i][j]=='o' && cntR[i]>=2 && cntC[j]>=2){
                aout += (cntR[i]-1) * (cntC[j]-1);
            }
        }
    }

    std::cout << aout << endl;
    return 0;
}