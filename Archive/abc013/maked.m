fp = fopen("d.txt", "w+");
N = 100000;
M = 200000;
D = 1e9; 
fprintf(fp, "%d %d %d\n", N, M, D);
fprintf(fp, "%d ", randperm(N));
fprintf(fp, "\n");
fclose all