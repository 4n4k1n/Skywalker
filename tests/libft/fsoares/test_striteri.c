
#include "my_utils.h"

int single_test_striteri(int test_number, char *str, void (*fn)(unsigned int, char *), char *func, char *expected)
{
	set_signature_tn(test_number, "ft_striteri(\"%s\", %s)", str, func);

	char buffer[20];
	strcpy(buffer, str);
	int result = 1;
	ft_striteri(buffer, fn);
	result = same_string(expected, buffer);
	result = check_leaks(NULL) && result;
	null_null_check(ft_striteri(buffer, fn), result);
	return result;
}

void add(unsigned int i, char *c) {
	*c = (char)(i + *c);
}

void to_char_zero(unsigned int i, char *c) {
	*c = i - i + '0';
}

void to_upper_at_even(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ft_toupper(*c);
}

void replace_spaces(unsigned int __attribute__((unused)) i, char *c)
{
    if (*c == ' ')
        *c = '_';
}

void alternate_case(unsigned int i, char *c)
{
    if (i % 2)
        *c = ft_tolower(*c);
    else
        *c = ft_toupper(*c);
}

int test_striteri()
{
    // Existing tests
    int res = single_test_striteri(1, "", add, "{(i, c) => i + c}", "");
    res = single_test_striteri(2, "abcd0 ", add, "{(i, c) => i + c}", "aceg4%") && res;
    res = single_test_striteri(3, "abcdfsdfs", to_char_zero, "{(i, c) => '0'}", "000000000") && res;
    res = single_test_striteri(4, "aaa", add, "{(i, c) => i + c}", "abc") && res;
    res = single_test_striteri(5, "000", to_char_zero, "{(i, c) => '0'}", "000") && res;
    res = single_test_striteri(6, "hello", to_upper_at_even, "{(i, c) => i % 2 == 0 ? toupper(c) : c}", "HeLlO") && res;
    res = single_test_striteri(7, "a b c", replace_spaces, "{(i, c) => c == ' ' ? '_' : c}", "a_b_c") && res;
    res = single_test_striteri(9, "zzzzz", add, "{(i, c) => i + c}", "z{|}~") && res;
    
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(striteri);
}
