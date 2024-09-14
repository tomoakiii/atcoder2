#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> ar('z'-'a'+1, 0);
    int cnt = 0;
    char lastc = 0;
    for (int i=0; i<N; i++){        
        if (S[i] == lastc){
            cnt++;
        } else {
            cnt = 1;
        }
        lastc = S[i];
        ar[lastc-'a'] = max(ar[lastc-'a'], cnt);
    }

    int anso = 0;
    for(int i=0; i<='z'-'a'; i++){
        anso += ar[i];
    }
    cout << anso << endl;
    return 0;
}