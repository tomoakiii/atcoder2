#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int a, b2;
    char b1;
    vector<pair<int, int>> relpos(Q+N, {0,0});
    for (int i=0; i<N; i++){
        relpos[i].first = N-i; // t0->x=N, t(N-1)->x=1
    }
    int cnt=N;
    while(Q-- > 0){
        cin >> a;
        if (a==2){
            cin >> b2;
            cout << relpos[cnt-b2].first << " " << relpos[cnt-b2].second << endl;
        } else {
            cin >> b1;
            relpos[cnt] = relpos[cnt-1];
            switch(b1){
                case 'R': relpos[cnt].first++; break;
                case 'L': relpos[cnt].first--; break;
                case 'U': relpos[cnt].second++; break;
                case 'D': relpos[cnt].second--; break;
            }
            cnt++;
        }
    }
    return 0;
}

