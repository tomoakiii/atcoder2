function emat
ans = 0;
ans2 = 0;


for p = 1 : 10    
    disp(n(p)*n(p)*k(p));
    disp((1+n(p))*(1+n(p))*k(p));
    ans = ans + (n(p)*n(p)*k(p));    
    ans2 = ans2 + ((1+n(p))*(1+n(p))*k(p));    
end

function emat_func(p, sm)
m = 1000;
rem = m - sm;
n = [11, 7, 7, 4, 4, 4, 3, 3, 2, 2];
k = [1, 2, 2, 5, 6, 7, 9, 12, 15, 17];

2 15 6 5 12 1  7 9 17 2
9 1  3 4  2 19 3 2  1 9

10 1000
2 15 6 5 12 1 7 9 17 2

10 1000

2 15 6 5 12 1 7 9 17 2
2 JPY * 9 = 162
15 JPY * 1 = 15
6 JPY * 3 = 54
5 JPY * 4 = 80
12 JPY * 2 = 48
1 JPY * 19 = 361
7 JPY * 3 = 63
9 JPY * 2 = 36
17 JPY * 1 = 17
2 JPY * 9 = 162
sm = 998