#include <cstdio>
#include <cassert>
#include <cmath>
#include <random>
using ll = long long;

// n, q, ai_upper_limit, filename, seed
int main(int argc, char **argv) {
    assert(argc == 6 && "must provide n, q, ai_upper_limit, filename, seed");
    
    int n = atoi(argv[1]);
    int q = atoi(argv[2]);
    int ai_upper_limit = atoi(argv[3]);
    char* filename = argv[4];
    ll seed = atoll(argv[5]);
    
    FILE *file = fopen(filename, "w+");

    std::mt19937_64 rng(seed);

    fprintf(file, "%d %d\n", n, q);

    int* ar = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        ar[i] = (rng() % ai_upper_limit) + 1;
        fprintf(file, "%d", ar[i]);
        fprintf(file, i < n ? " " : "\n");
    }

    for (int i = 1; i <= q; i++) {
        int x = (rng() % n) + 1;
        int v = (rng() % ai_upper_limit) + 1;
        while (((v ^ ar[x]) & 1) == 0) v = (rng() % ai_upper_limit) + 1;
        ar[x] = v;
        fprintf(file, "%d %d\n", x, v);
    }

    delete[] ar;
    fclose(file);
}