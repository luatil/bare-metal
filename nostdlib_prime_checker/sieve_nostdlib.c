int power(int a, int b);
int string_to_integer(char *str);
// this function is implemented in is_prime.s
int is_prime(int n);
// This function is implemented in print.s
void print_asm(int length, char *string);

int main(int argc, char *argv[]) {
    if(argc > 1) {
        if(is_prime(string_to_integer(argv[1]))) 
            print_asm(2, "1\n");
        else 
            print_asm(2, "0\n");
    }
    return 0; 
}

// This function returns a^b
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
