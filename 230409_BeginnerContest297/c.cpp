#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int H, W;
    cin >> H >> W;
    string S;
    while(H--){
        cin >> S;
        bool isT=false;
        for(int i=0; i<W; i++){
            if (S[i]=='T'){
                if (isT){
                    S[i-1] = 'P';
                    S[i] = 'C';
                    isT = false;
                } else {
                    isT = true;
                }
            } else {
                isT = false;
            }
        }
        cout << S << endl;
    }
    return 0;
}