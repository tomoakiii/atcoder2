function sample
fp = fopen("e4.txt", "w+");
N = 6000;
M = 100000;
fprintf(fp, "%d\n", N);
r = round(rand(1,N) * M);
fprintf(fp, "%d ", r);
fprintf(fp, "\n");