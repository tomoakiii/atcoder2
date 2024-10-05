#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    char maxc;
    int maxn = 0;
    for (int i=0; i<S.size(); i++){
        int n = upper_bound(S.begin(), S.end(), S[i])-lower_bound(S.begin(), S.end(), S[i]);
        if (maxn < n){
            maxn = n;
            maxc = S[i];
        }
    }
    cout << maxc << endl;
    return 0;
}

