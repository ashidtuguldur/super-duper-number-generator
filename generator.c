#include <stdbool.h>
#include <stdio.h>

bool recursive_check(unsigned long long int gend){
    int last = gend % 10;
    if (!(last == 1 || last == 0)) {
        return false;
    }
    if(last == gend){
        return true;
    }
    return recursive_check(gend / 10);
}

bool iterative_check(unsigned long long int gend){
    int last;
    do {
        last = gend % 10;
        if (!(last == 1 || last == 0)) {
            return false;
        }
        gend = gend / 10;
    }while (last != gend);

    return true;
}

int main(void){
    unsigned long long int seed = 415;
    unsigned long long int multiplier = 1;
    unsigned long long int gend = 0;

    do {
        gend = seed * multiplier;
        multiplier++;
    }while (!iterative_check(gend));

    printf("%lld\n", gend);
    printf("%lld\n", --multiplier);
    return 0;
}
