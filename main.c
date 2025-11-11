#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    unsigned long long N = 1000000ULL;
    unsigned long long counts[11] = {0}; // index 0->sum 2, ... , 10->sum 12

    // Precompute sums of ordered pairs (d1,d2) in row-major order.
    // idx = (d1-1)*6 + (d2-1), for d1,d2 in 1..6.
    static const unsigned char sum36[36] = {
        2,3,4,5,6,7, 3,4,5,6,7,8, 4,5,6,7,8,9,
        5,6,7,8,9,10, 6,7,8,9,10,11, 7,8,9,10,11,12
    };

    srand((unsigned)time(NULL));
    for (unsigned long long i=0;i<N;++i){
        int idx = rand()%36;              // pick one ordered pair uniformly
        int s = sum36[idx];               // map to its sum
        counts[s-2]++;                    // store at 0..10
    }

    puts("Sum Count");
    for (int k=0;k<11;++k)
        printf("%3d %llu\n", k+2, counts[k]);

    return 0;
}
