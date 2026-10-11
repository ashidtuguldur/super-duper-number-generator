#include <stdbool.h>
#include <stdio.h>

bool check(unsigned long long int gend){
    int last = gend % 10;
    if (!(last == 1 || last == 0)) {
        return false;
    }
    if(last == gend){
        return true;
    }
    return check(gend / 10);
}

int main(void){
    unsigned long long int seed = 498;
    unsigned long long int multiplier = 1;
    unsigned long long int gend = 0;

    do {
        gend = seed * multiplier;
        multiplier++;
    }while (!check(gend));

    printf("%lld\n", gend);
}
