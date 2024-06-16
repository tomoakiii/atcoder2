#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
int main()
{    
    int M;
    cin >> M;
    vector<int> D(M);
    int sd = 0;
    for (auto &d: D) {
        cin >> d;
        sd += d;
    }

    int tgt = (sd+1)/2;
    int cnt = 0;
    for(int k=0; k<M; k++){
        for (int i=0; i<D[k]; i++){
            cnt++;
            if (cnt == tgt) {
                cout << (k+1) << " " << (i+1) << endl;
                return 0;
            }
        }
    }
    return 0;
}