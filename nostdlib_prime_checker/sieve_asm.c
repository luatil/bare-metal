#include <stdio.h>

// Here is_prime is implemented in is_prime.s
int is_prime(int n);
void test_is_prime();
int power(int a, int b);
int string_to_integer(char *str);

// This functions prints 1 if argv[1] is a prime number, nothing if no argument is given, and 0 otherwise
int main(int argc, char *argv[]) {
	if(argc > 1)
		printf("%d\n", is_prime(string_to_integer(argv[1])));
    return 0;
}

void test_is_prime() {
    if(is_prime(2) != 1 ) printf("Test number %d failed, with result %d\n", 1, is_prime(2));
    if(is_prime(3) != 1 ) printf("Test number %d failed, with result %d\n", 2, is_prime(3));
    if(is_prime(4) != 0 ) printf("Test number %d failed, with result %d\n", 3, is_prime(4));
    if(is_prime(73) != 1 ) printf("Test number %d failed, with result %d\n", 4, is_prime(73));
    if(is_prime(0) != 0 ) printf("Test number %d failed, with result %d\n", 5, is_prime(0));
    if(is_prime(1) != 0 ) printf("Test number %d failed, with result %d\n", 6, is_prime(1));
    if(is_prime(100) != 0 ) printf("Test number %d failed, with result %d\n", 7, is_prime(100));
}

// this function retures a^b
int power(int a, int b) {
	if(b == 0)
		return 1;
	else if(b == 1)
		return a;
	else 
		return a * power(a, b - 1);
}

int string_to_integer(char *str) {
	int total = 0;
	char *init = str;
	int string_size = 0;
	while(*str++)
		string_size++;
	str = init;
	int i = 0;
	while(i < string_size) {
		total += (int)(str[string_size-i-1] - '0') * power(10, i);
		i++;
	}
	return total;
}
