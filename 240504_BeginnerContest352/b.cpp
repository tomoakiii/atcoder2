#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    string S;
    cin >> S;
    string T;
    cin >> T;
    int cnt = 0;
    for(int i=0; i<S.size();i++) {
        while(cnt < T.size()){
            if(T[cnt] == S[i]) {
                cout << (cnt+1) << " ";
                cnt++;
                break;
            } else {
                cnt++;
            }

        }
    }    
    cout << endl;
    return 0;
}