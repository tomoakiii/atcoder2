#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string S;
    cin >> S;
    map<char, vector<int>> mp;
    for(int i=0; i<S.size(); i++){
        mp[S[i]].push_back(i);
    }
    if(mp['B'][0]%2 == mp['B'][1]%2){
        cout << "No" << endl;
        return 0;
    }
    if(mp['R'][0] < mp['K'][0] && mp['K'][0] < mp['R'][1]){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}