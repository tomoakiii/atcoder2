//Nの平方根(切り捨て)を返す
ll Sqrt(ll N) {
    ll ok = 0, ng = 2*Pow(10,9), mid = (ng+ok)/2;
    while(ng - ok > 1) {
        if (mid*mid <= N) ok = mid;
        else ng = mid;
        mid = (ok+ng)/2;
    }
    return ok;
}