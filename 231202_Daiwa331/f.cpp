#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    char *S, *invS;
    cin >> N >> Q;
    S = new char[N];
    invS = new char[N];
    scanf("%s", S);
    for (int i=0; i<N; i++){
        invS[i] = S[N-i-1];
    }
    vector<string> sans(Q, "Yes");
    int qind = 0;
    for (int q=0; q<Q; q++){
        int type;
        cin >> type;
        if (type == 1){
            int x;
            char c;
            cin >> x >> c;
            S[x-1] = c;
            invS[N-x] = c;
        } else {
            int l, r;
            cin >> l >> r;
            if (0 == memcmp(&S[0]+l-1, &invS[0]+N-r, (r-l+2)/2)){
                sans[qind] = "Yes";
            } else {
                sans[qind] = "No"; 
            }
            qind++;
        }
    }

    for (int q = 0; q < qind; q++){
        cout << sans[q] << endl;
    }
    return 0;
}
