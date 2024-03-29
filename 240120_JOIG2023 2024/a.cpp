#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int N;
    string S;
    cin >> N >> S;
    for(int i=0; i<N-2; i++){
        if (S[i] == 'o' && S[i+1] == 'o' && S[i+2] == 'o'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

