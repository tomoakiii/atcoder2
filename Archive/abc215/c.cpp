#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int K;
    cin >> K;
    sort(s.begin(), s.end());
    set<string> st;
    do {
		st.insert(s);
	} while (next_permutation(s.begin(), s.end()));
    auto it = st.begin();
    for (int i=0; i<(K-1); i++) it++;
    cout << *(it) << endl;
    return 0;
}

