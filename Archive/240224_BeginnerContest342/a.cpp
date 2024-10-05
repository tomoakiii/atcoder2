#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    string S;
    cin >> S;
    vector<pair<int, int>> p('z'-'a'+1, {0,0});

    for(int n=0; n<S.size(); n++){
        char c = S[n];
        p[c-'a'].first++;
        p[c-'a'].second = n;
    }
    for(int n=0; n<p.size(); n++){
        if (p[n].first == 1){
            cout << p[n].second+1 << endl;
            return 0;
        }
    }
    return -1;
}

