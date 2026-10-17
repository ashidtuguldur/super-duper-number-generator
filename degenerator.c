#include <stdio.h>

int find_factor_pairs(unsigned long long num, unsigned long long **pairs, int count){
    unsigned long long *out = *pairs;
    for(unsigned long long first_factor = 1; first_factor <= num / first_factor && count < 8; first_factor++){
        if(num % first_factor == 0){
            *(out + count) = first_factor;
            *(out + count + 8) = num / first_factor;
            count++;
        }
    }
    return count;
}

int main(void){
    unsigned long long pairs[2][8] = {0};
    unsigned long long *pair = *pairs;

    unsigned long long num = 1010110;

    int n = find_factor_pairs(num, &pair, 8);

    for (int i = 0; i < n; i++) {
        printf("%llu %llu\n", *(pair + i), *(pair + i + 8));
    }

    return 0;
}
