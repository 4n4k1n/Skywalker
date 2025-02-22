
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

int test_striteri()
{
    int res = single_test_striteri(1, "", add, "{(i, c) => i + c}", "");
    res = single_test_striteri(2, "abcd0 ", add, "{(i, c) => i + c}", "aceg4%") && res;
    res = single_test_striteri(3, "abcdfsdfs", to_char_zero, "{(i, c) => '0'}", "000000000") && res;
    res = single_test_striteri(4, "123", add, "{(i, c) => i + c}", "246") && res;
    res = single_test_striteri(5, "   ", add, "{(i, c) => i + c}", "#%'") && res;
    res = single_test_striteri(6, "aaa", add, "{(i, c) => i + c}", "abc") && res;
    res = single_test_striteri(7, "000", to_char_zero, "{(i, c) => '0'}", "000") && res;
    res = single_test_striteri(8, "xyz", add, "{(i, c) => i + c}", "y{|") && res;
    res = single_test_striteri(9, "\n\n\n", add, "{(i, c) => i + c}", "\v\f\r") && res;
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(striteri);
}
