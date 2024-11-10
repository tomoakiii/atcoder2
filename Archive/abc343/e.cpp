#include <bits/stdc++.h>
using namespace std;

int v1,v2,v3;

int v(int x1, int y1, int z1, int x2, int y2, int z2){
    int xlen, ylen, zlen;
    xlen = max(0, min(x1+7-x2, x2+7-x1));
    ylen = max(0, min(y1+7-y2, y2+7-y1));
    zlen = max(0, min(z1+7-z2, z2+7-z1));
    return xlen * ylen * zlen;
}


bool calc(int x1, int y1, int z1, int x2, int y2, int z2){
    // c1 && c2 && c3
    int xlen  = max(0, min(7, min(x1+7, x2+7)) - max(0, max(x1, x2)));
    int ylen  = max(0, min(7, min(y1+7, y2+7)) - max(0, max(y1, y2)));
    int zlen  = max(0, min(7, min(z1+7, z2+7)) - max(0, max(z1, z2)));
    int vc123 = xlen * ylen * zlen;
    if (v3 != vc123) return false;

    // c1 && c2
    int vc12 = v(0, 0, 0, x1, y1, z1);
    // c2 && c3
    int vc23 = v(x1, y1, z1, x2, y2, z2);
    // c1 && c3
    int vc13 = v(0, 0, 0, x2, y2, z2);
    if (v2 != vc12 + vc23 + vc13 - vc123 - vc123 - vc123) return false;

    int vc1 = 343 - vc12 - vc13 + vc123;
    int vc2 = 343 - vc12 - vc23 + vc123;
    int vc3 = 343 - vc13 - vc23 + vc123;
    if (v1 != vc1 + vc2 + vc3) return false;
    
    cout << "Yes" << endl;
    int mx = 0;
    cout << mx << " " << mx << " " << mx << " " << x1+mx << " " << y1+mx << " " << z1+mx << " " << x2+mx << " " << y2+mx << " " << z2+mx << endl; 
    return true;
}


int main(){
    cin >> v1 >> v2 >> v3;
    for(int x1=0;x1<=7;x1++)for(int y1=0;y1<=7;y1++)for(int z1=0;z1<=7;z1++)
    for(int x2=0;x2<=7;x2++)for(int y2=-7;y2<=7;y2++)for(int z2=-7;z2<=7;z2++){
        if (calc(x1, y1, z1, x2, y2, z2)) return 0;
    }

    cout << "No" << endl;
    return 0;
}

