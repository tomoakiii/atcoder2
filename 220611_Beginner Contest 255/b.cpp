#include <bits/stdc++.h>
using namespace std;
const double INF = 0x0F0F0F0F0F0F0F0F;


int main () {
    int N, K;
    cin >> N >> K;

    struct xy{
        double x;
        double y;
        //xy(double x, double y): x(x), y(y){}
    };
    set<int> st{};
    int k;
    for(int i=0; i<K; i++){
        cin >> k;
        st.insert(k-1);
    }
    vector<xy> cd(N);
    for (int i=0; i<N; i++){
        cin >> cd[i].x >> cd[i].y;
    }
    double mind;
    double ans = 0;
    for (int i=0; i<N; i++) {
        mind = INF;
        if (st.find(i) != st.end()) continue;
        for (auto it = st.begin(); it != st.end(); it++){
            int j = *it;
            double xd = cd[i].x - cd[j].x;
            double yd = cd[i].y - cd[j].y;
            mind = min(mind, sqrt(xd*xd + yd*yd));
        }
        ans = max(mind, ans);
    }
    cout << std::setprecision(24) << ans << endl;
    
    return 0;
}

