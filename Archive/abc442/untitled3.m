function test
fp = fopen("f.txt", "w+");
fprintf(fp, "5000\n");
R = rand(5000);
R = R>0.5;
for n=1:5000
    for n2=1:5000
        if (R(n,n2))
            fprintf(fp, '.');
        else
            fprintf(fp, '#');
        end
    end
    fprintf(fp, "\n");
end