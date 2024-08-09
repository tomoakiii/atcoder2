#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<char> g('z'-'a'+1);
    for (char c='a'; c<='z'; c++) g[c-'a']=c;

    char cc,cd;
    while (Q--){
        cin>>cc>>cd;
		for (char c='a'; c<='z'; c++){
			if (g[c-'a'] == cc){
				g[c-'a'] = cd;
			}
		}
    }
    for (int i=0; i<N; i++){
        S[i] = g[S[i]-'a'];
    }
    cout << S << endl;
    return 0;
}

