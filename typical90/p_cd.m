function p_cd
st = 1;
ed = 10000;
a = 0;
for n = st : ed
    k = 0;
    if(n < 10)
        k=1;
    elseif(n < 100)
        k=2;
    elseif(n < 1000)
        k=3;
    elseif(n < 10000)
        k=4;
    else
        k=5;
    end
    a = a + n * k;    
end
disp(a);