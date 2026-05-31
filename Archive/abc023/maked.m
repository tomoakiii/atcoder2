fp = fopen("d.txt", "w+");
M = 99999;
fprintf(fp, "%d\n", M);
for n=1:100000
    fprintf(fp, "1000000000 1000000000\n");
end
fclose all