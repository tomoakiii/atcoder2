#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<char> lib('z'-'a'+1);

    for(int i=0; i<N; i++){
        P2[P[i]-1] = i;
    }
    
    int a,b;
    while (Q--){
        cin>>a>>b;
        a--; b--;
        cout << ((P2[a] < P2[b])?a+1:b+1) << endl;
    }
    return 0;
}

