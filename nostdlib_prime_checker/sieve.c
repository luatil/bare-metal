#include <stdio.h>

char is_prime(size_t n);
void test_is_prime();
size_t stoi(char *str);
size_t isqrt(size_t);
void test_isqrt();
	
// This functions prints 1 if argv[1] is a prime number, nothing if no argument is given, and 0 otherwise
int main(int argc, char *argv[]) {
    if(argc > 1)
        printf("%d\n", is_prime(stoi(argv[1])));
	return 0;
}

void test_is_prime() {
    if(is_prime(2) != 1)   printf("Test number %d failed\n", 1);
    if(is_prime(3) != 1)   printf("Test number %d failed\n", 2);
    if(is_prime(4) != 0)   printf("Test number %d failed\n", 3);
    if(is_prime(73) != 1)  printf("Test number %d failed\n", 4);
    if(is_prime(0) != 0)   printf("Test number %d failed\n", 5);
    if(is_prime(1) != 0)   printf("Test number %d failed\n", 6);
    if(is_prime(100) != 0) printf("Test number %d failed\n", 7);
}

void test_isqrt() {
    if(isqrt(2) != 1)    printf("Test number %d failed\n", 1);
    if(isqrt(3) != 1)    printf("Test number %d failed\n", 2);
    if(isqrt(4) != 2)    printf("Test number %d failed\n", 3);
    if(isqrt(73) != 8)   printf("Test number %d failed\n", 4);
    if(isqrt(0) != 0)    printf("Test number %d failed\n", 5);
    if(isqrt(1) != 1)    printf("Test number %d failed\n", 6);
    if(isqrt(100) != 10) printf("Test number %d failed\n", 7);
    if(isqrt(15) != 3) printf("Test number %d failed\n", 8);
}

// Integer sqrt using newton's method
size_t isqrt(size_t n) {
    if(n==0) return 0;
    size_t xk1 = n, xk = n+1;
    while(xk > xk1) {
        xk = xk1;
        xk1 = (xk+n/xk)/2;
    }
    return xk;
}

char is_prime(size_t n) {
    if(n < 2) return 0;
    int stop = isqrt(n);
    for(size_t i = 3; i <= stop; i+=2) 
        if(!(n % i)) return 0;
    return (n&2 ? 1 : n==2);
}

size_t stoi(char *str) {
    size_t total = 0;
    for(size_t i = 0; str[i] != '\0'; i++) {
        total *= 10;
        total += (str[i] - '0'); 
    }
    return total;
}
