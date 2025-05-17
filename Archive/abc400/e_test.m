function e_test
n_a = 1E12;
cnt = 0;
while(mod(n_a,2) == 0)
    n_a = n_a / 2;
    cnt = cnt + 1;
end
cnt1 = 0;
while(mod(n_a,5) == 0)
    n_a = n_a / 5;
    cnt1 = cnt1 + 1;
end
disp(n_a);
disp(cnt);
disp(cnt1);