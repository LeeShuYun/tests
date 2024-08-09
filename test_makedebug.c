#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
// #include <profileapi.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <time.h>
#include <string.h>

/**
 * @brief tests performance using clock() from  time.h;
 */
void test_perf_simple(void)
{
	clock_t start, end;
	clock_t start_orig, end_orig;
	double cpu_time_used, cpu_time_used_orig;

	start = clock();
	for(int i = 0; i < 10000; i++)
		ft_printf("%s\n", "testing123456789984300245");
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	start_orig = clock();
	for(int i = 0; i < 10000; i++)
		printf("%s\n", "testing123456789984300245");
	end_orig = clock();
	cpu_time_used_orig = ((double) (end_orig - start_orig)) / CLOCKS_PER_SEC;

	printf("My function took %f seconds to execute\n", cpu_time_used);
	printf("Original function took %f seconds to execute\n", cpu_time_used_orig);
}
void test_perf_win(void)
{
	// struct timeval t0, t1;
	// gettimeofday(&t0, NULL);
	// t0 = read_time();
	// t0 = QueryPerformanceCounter();

	// for(int i = 0; i < 1000000; i++)
	// 	ft_printptr(charptr);

	// gettimeofday(&t1, NULL);
	// t1 = read_time();
	// t1 = QueryPerformanceCounter();
	// printf("Did %u calls in %.9d seconds\n", i, t1 - t0);
	// t1.tv_sec - t0.tv_sec + 1E-6 * (t1.tv_usec - t0.tv_usec));


}
void test_printptr(void)
{
	char *charptr = "test";
	int testint = 100;
	int *intptr = &testint;
	unsigned int longint = UINT_MAX;
	unsigned int *longintptr = &longint;
	printf("Test pointer ============================================= \n");
	void *testcases[4] = {charptr, intptr, longintptr, NULL};
	for(int i = 0; i < 4; i++)
	{
		int len = ft_printptr(testcases[i]);
		printf("\n");
		int len_orig = printf("%p", testcases[i]);
		printf("\n");
		if (len == len_orig) {
			printf("%%p Test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", len_orig, len);
		}
	}
	printf("demo pointer=[%li]\n", (uintptr_t)"test");
}
void test_printunbr(void)
{
	printf("Test unsigned int ============================================= \n");
	int testcases[10] = {0, UINT_MAX, INT_MIN, -12};
	for(int i = 0; i < 4; i++)
	{
		printf("Testcase[%u]\n", testcases[i]);
		int len = ft_print_unsigned_nbr(testcases[i]);
		printf("\n");
		int len_orig = printf("%u", testcases[i]);
		printf("\n");
		if (len == len_orig) {
        	printf("%%i Test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", len_orig, len);
		}
	}
}

void test_printnbr(void)
{
	printf("Test int ============================================= \n");
	int testcases[10] = {0, INT_MAX, INT_MIN};
	for(int i = 0; i < 3; i++)
	{
		printf("Testcase[%i]\n", testcases[i]);
		int len = ft_printnbr(testcases[i]);
		printf("\n");
		int len_orig = printf("%i", testcases[i]);
		printf("\n");
		if (len == len_orig) {
        	printf("%%i Test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", len_orig, len);
		}
	}
}
void test_printhex(void)
{
	printf("Test hex ============================================= \n");
	for(int i = 0; i < 20; i++)
	{
		printf("Testcase[%i]=============== \n", i);
		int hexlen = ft_printhex(i, 'x');
		printf("\n");
		int hexlen_orig = printf("%x", i);
		printf("\n");
		if (hexlen == hexlen_orig) {
        	printf("Lower test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", hexlen_orig, hexlen);
		}
		int hextest_up = ft_printhex(i, 'X');
		printf("\n");
		int hextestup_orig = printf("%X", i);
		printf("\n");
		if (hextest_up == hextestup_orig) {
        	printf("Upper test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", hextestup_orig, hextest_up);
		}
	}

	int testcases[10] = {33333, UINT_MAX, -1, 313249263};
	for(int i = 0; i < 4; i++)
	{
		printf("Testcase[%i]=============== \n", testcases[i]);
		int hexlen = ft_printhex(testcases[i], 'x');
		printf("=mine\n");
		int hexlen_orig = printf("%x", testcases[i]);
		printf("=orig\n");
		if (hexlen == hexlen_orig) {
        	printf("Lower test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", hexlen_orig, hexlen);
		}
		int hextest_up = ft_printhex(testcases[i], 'X');
		printf("=mine\n");
		int hextestup_orig = printf("%X", testcases[i]);
		printf("=orig\n");
		if (hextest_up == hextestup_orig) {
        	printf("Upper test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", hextestup_orig, hextest_up);
		}
	}

}

void test_printchar(void)
{
	printf("Testing printchar =============================================\n");
	for (int i = 33; i < 127; i++)
	{
		int testchar = ft_printchar(i);
		int origchar = printf("%c", i);
		printf(" result=[%i]=[%i]\n", testchar, origchar);
		assert (testchar == origchar);
	}
	int testcases[10] = {'0' - 256, '0' + 256, '0', 0, ' '};
	for(int i = 0; i < 5; i++)
	{
		printf("Testcase[%i] \n", testcases[i]);
		int len = ft_printnbr(i);
		int len_orig = printf("%i", i);
		printf(" result=[%i]=[%i]\n", len, len_orig);
		if (len == len_orig) {
        	printf("%%i Test case passed!\n");
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", len_orig, len);
		}
	}
}

void test_printstr(void)
{
	printf("Test printstr ============================================= \n");
	char *teststr = "%%%~!@#$%^&*()_+qwertyuiop[]\\|}{asdfghjkl;'zxcvbnm,./?><:\n";
	printf("Original[%s] \n", teststr);
	ft_printf("Mine    [%s]\n", teststr);
	int len = ft_printstr(teststr);
	int len_orig = printf("%s", teststr);
	printf(" result=[%i]=[%i]\n", len, len_orig);
	if (len == len_orig) {
		printf("[%s]Test case passed!\n", teststr);
	} else {
		printf("Test case failed. Expected: %i, Actual: %i\n", len_orig, len);
	}

	char *testcases[6] = {"", " ", "\a\b\v\n\f\t\r", " testcase test ", "      ", NULL};

	for(int i = 0; i < 6; i++)
	{
		int len = ft_printstr(testcases[i]);
		printf("\n");
		int len_orig = printf("%s", testcases[i]);
		if (len == len_orig) {
			printf("\n[%s]Test case passed!\n", testcases[i]);
		} else {
			printf("Test case failed. Expected: %i, Actual: %i\n", len_orig, len);
		}
	}
}
void test_printf(void)
{
	printf("Testing main printf...\n");
	printf("/============================================================\n");
	printf("Testing printable char...\n");
	for (int i = 33; i < 127; i++)
	{
		int test = ft_printf("%c", i);
		int orig = printf("%c", i);
		printf(" result=[%i]=[%i]\n", test, orig);
		assert (test == orig);
	}

	printf("/============================================================\n");
	printf("Testing combo string\n");
	int combocount = ft_printf("character[%c]\nstring[%s]\ndecimal[%d]\ninteger[%i]\nlowerHex[%x]\nupperHex[%X]\npointer=[%p]\nunsigned int%u\n", 'a', " string ", INT_MAX, INT_MIN, INT_MAX, INT_MAX, NULL, UINT_MAX);
	int combocountorig = printf("character[%c]\nstring[%s]\ndecimal[%d]\ninteger[%i]\nlowerHex[%x]\nupperHex[%X]\npointer=[%p]\nunsigned int%u\n", 'a', " string ", INT_MAX, INT_MIN, INT_MAX, INT_MAX, NULL, UINT_MAX);
	printf("mycombo=[%i]origcombo=[%i]\n",combocount,combocountorig);
	assert (combocount == combocountorig);

	int i_combo_orig = printf("orig[%c%c%c %i%i%i]\n", 'a', 'b', 'c', 1, INT_MAX, INT_MIN);
	int i_combo = ft_printf("mine[%c%c%c %i%i%i]\n", 'a', 'b', 'c', 1, INT_MAX, INT_MIN);
	printf(" repeating combos mycombo=[%i]origcombo=[%i]\n",i_combo,i_combo_orig);

	printf("/============================================================\n");
	printf("Testing Character %%c\n");
    char letter = 'A';
    int count = ft_printf("A=[%c]\n", letter);
    int orig_count = printf("A=[%c]\n", letter);
	printf("count=[%d]orig=[%d]\n", count, orig_count);
	assert(count == orig_count);

	printf("/============================================================\n");
	printf("Testing string %%s\n");
	char * teststr = "hello world";
	count = ft_printf("hello world=[%s]\n", teststr);
	orig_count = printf("hello world=[%s]\n", teststr);
	assert(count == orig_count);

	printf("/============================================================\n");
	printf("Testing pointer %%p\n");
	count = ft_printf("[%p]=", teststr);
	orig_count = printf("[%p]\n", teststr);
	assert(count == orig_count);

	printf("/============================================================\n");
	printf("Testing decimal/integer %%d %%i\n");
    // // Basic signed decimal/integer printing %d base 10 and %i
    int num = INT_MAX;
    count = ft_printf("2147483647=[%d]\n", num);
    orig_count = printf("2147483647=[%d]\n", num);
	assert(count == orig_count);

	num = INT_MIN;
    count = ft_printf("-2147483648=[%d]\n", num);
    orig_count = printf("-2147483648=[%d]\n", num);
	assert(count == orig_count);

    num = 0;
    count = ft_printf("The answer is %i\n", num);
    orig_count = printf("The answer is %i\n", num);
	assert(count == orig_count);

	printf("/============================================================\n");
    // unsigned decimal number %u base 10
    unsigned int posnum = UINT_MAX;
    count = ft_printf("4294967295=[%u]\n", posnum);
    orig_count = printf("4294967295=[%u]\n", posnum);
	assert(count == orig_count);

    unsigned int unsigned_negnum = -42;
    count = ft_printf("unsigned-42=[%u]\n", unsigned_negnum);
    orig_count = printf("unsigned-42=[%u]\n", unsigned_negnum);
	assert(count == orig_count);

    // Hexadecimal lowercase
    int hex_num = 11259375;
    count = ft_printf("abcdef=[%x]\n", hex_num);
    orig_count = printf("abcdef=[%x]\n", hex_num);
	assert(count == orig_count);

    // Hexadecimal uppercase
    count = ft_printf("ABCDEF=[%X]\n", hex_num);
    orig_count = printf("ABCDEF=[%X]\n", hex_num);
	assert(count == orig_count);

	// %% percentage
    count = ft_printf("percentage=[%%]\n");
    orig_count = printf("percentage=[%%]\n");
	assert(count == orig_count);

	// Multiple arguments
    char name[] = "Alice";
    int age = 30;
    count = ft_printf("string=[%s] int=[%d]\n", name, age);
    orig_count = printf("string=[%s] int=[%d]\n", name, age);
	assert(count == orig_count);

	//print unsupported arguments (prints only %)
	int unsupported_len = ft_printf("unsupport=[%q]\n", 123);
	int unsupported_len_orig = printf("unsupport=[%q]\n", 123);
	printf("unsupported len [%i]=[%i]\n", unsupported_len, unsupported_len_orig);
	assert(unsupported_len == unsupported_len_orig);

	int wrong_len = ft_printf("test wrong format [%z adfasdf]\n", 123); //doesn't print z
	int wrong_len_orig = printf("test wrong format [%z adfasdf]\n", 123); //doesn't print z
	assert(wrong_len == wrong_len_orig);

	// integer overflow
	int overflow = ft_printf("%d\n", INT_MAX + 1); // this is caught by the compiler
	int overflow_orig = printf("%d\n", INT_MAX + 1);
	printf("overflow [%i]=[%i]\n", overflow, overflow_orig);
	assert(overflow == overflow_orig);

	//buffer overflow
	char long_str[10000];
	memset(long_str, 'A', 9999);
	long_str[9999] = '\0';
	int buf_len = ft_printf("%s\n", long_str);  // Printing a very long string.
	int buf_len_orig = printf("%s\n", long_str);  // Printing a very long string.
	assert(buf_len == buf_len_orig);

	//should print Hello only
	int hello_len = printf("Hello\n\0World");
	int hello_len_orig = ft_printf("Hello\n\0World");
	assert(hello_len == hello_len_orig);

	// nested format specifiers
	int nested_orig = printf("%%%d\n", 5);  // Should print "%5".
	int nested = ft_printf("%%%d\n", 5);  // Should print "%5".
	assert(nested == nested_orig);

	// ours does not handle, but nice to know
	// setlocale(LC_NUMERIC, "de_DE");
	// printf("%f", 1234.56);  // Should print with a comma as the decimal separator in German locale.

	printf("/============================================================\n");

}

void test_illegal()
{
	printf("/============================================================\n");

	//doing illegal stuff that shouldn't compile... this is for debug only
	printf("Testing combo string with NULLs ========== \n");
	int combocount = printf("character[%c]\nstring[%s]\ndecimal[%d]\ninteger[%i]\nlowerHex[%x]\nupperHex[%X]\npointer=[%p]\nunsigned int%u\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	int combocountorig = printf("character[%c]\nstring[%s]\ndecimal[%d]\ninteger[%i]\nlowerHex[%x]\nupperHex[%X]\npointer=[%p]\nunsigned int%u\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("mycombo=[%i]origcombo=[%i]\n",combocount,combocountorig);
	assert (combocount == combocountorig);

	printf("/============================================================\n");

}

/** prints the binary form of any integer input */
void printbits(unsigned long long x) {
    for (int i = sizeof(x) * 8 - 1; i >= 0; i--)
        putchar('0' + ((x >> i) & 1));
}

void test_printbits(void)
{
	printbits(42);
	// step 1: putchar('0' + ((42 >> i) & 1));
	// 1 is 00000001, 42 is 00101010
	// 42 >> i is 00010101
	// ((42 >> i) & 1) takes last bit AND 00000001 = 0
	// 0 + '0' = '0'
	// Prints 00000000000000000000000000101010 (on a 32-bit system)
	// Prints 0000000000000000000000000000000000000000000000000000000000101010 on 64 bit system

	putchar('\n');
	printbits(1);
	putchar('\n');
	printbits(11);
	// 1 is 00000001, 10 is 00101010
	putchar('\n');
}
/*
allowed: malloc, free, write, va_start, va_arg, va_copy, va_end
Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.
implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/
int main(int argc, char **argv) {

	(void) argc;
	(void) argv;
	char testcase;

	if (argv[1][0] != 0)
		testcase = argv[1][0];
	else
		testcase = '0';
	printf("testcase chosen [%c]\n", testcase);
	if (testcase == 'x')
		test_printhex();
	else if (testcase == 'i')
		test_printnbr();
	else if (testcase == 'p')
		test_printptr();
	else if (testcase == 'u')
		test_printunbr();
	else if (testcase == 'c')
		test_printchar();
	else if (testcase == 'a')
		test_printf();
	else if (testcase == 's')
		test_printstr();
	else if (testcase == '0')
	{
		test_printhex();
		test_printnbr();
		test_printptr();
		test_printunbr();
		test_printchar();
		test_printstr();
		test_printf();
		test_illegal();
		//demo
		int char_size = sizeof(char);
		int int_size = sizeof(int);
		int strptr_size = sizeof(char *);
		int voidptr_size = sizeof(void *);
		printf("char_size=[%i]int_size=[%i]strptr_size=[%i]voidptr_size=[%i]\n",
		char_size, int_size, strptr_size, voidptr_size);
	}
	else if (testcase == 'l')
		test_perf_simple();
	else if (testcase == 'n')
		test_printbits();
	// else if (testcase == 'g')
		// test_illegal();
	else
		printf("Pick a possible testcase: 0xipucas");
	return 0;
}
