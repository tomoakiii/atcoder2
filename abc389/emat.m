function emat
ans = 0;
ans2 = 0;

n = [11, 7, 7, 4, 4, 4, 3, 3, 2, 2];
k = [1, 2, 2, 5, 6, 7, 9, 12, 15, 17];


for p = 1 : 10    
    disp(n(p)*n(p)*k(p));
    disp((1+n(p))*(1+n(p))*k(p));
    ans = ans + (n(p)*n(p)*k(p));    
    ans2 = ans2 + ((1+n(p))*(1+n(p))*k(p));    
end

disp(ans);
disp(ans2);