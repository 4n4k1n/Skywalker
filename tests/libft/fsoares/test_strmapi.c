
#include "my_utils.h"

int single_test_strmapi(int test_number, char *str, char (*fn)(unsigned int, char), char *func, char *expected)
{
	set_signature_tn(test_number, "ft_strmapi(\"%s\", %s)", str, func);
	check_alloc_str_return(ft_strmapi(str, fn), expected);
}

char add(unsigned int i, char c) {
	return (char)(i + c);
}

char to_char_zero(unsigned int i, char c) {
	c = (char)i;
	return '0' + c - c;
}

char to_upper_at_even(unsigned int i, char c)
{
    return (i % 2 == 0) ? ft_toupper(c) : c;
}

char add_to_vowels(unsigned int i, char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return c + i;
    return c;
}

char increment_numbers(unsigned int __attribute__((unused)) i, char c)
{
    if (c >= '0' && c <= '9')
        return ((c - '0' + 1) % 10) + '0';
    return c;
}

char replace_spaces(unsigned int __attribute__((unused)) i, char c)
{
    return (c == ' ') ? '_' : c;
}

char alternate_case(unsigned int i, char c)
{
    return (i % 2) ? ft_toupper(c) : ft_tolower(c);
}

int test_strmapi()
{
    int res = single_test_strmapi(1, "", add, "{(i, c) => i + c}", "");
    res = single_test_strmapi(2, "abcd0 ", add, "{(i, c) => i + c}", "aceg4%") && res;
    res = single_test_strmapi(3, "abcdfsdfs", to_char_zero, "{(i, c) => '0'}", "000000000") && res;
    
    res = single_test_strmapi(4, "hello", to_upper_at_even, "{(i, c) => i % 2 == 0 ? toupper(c) : c}", "HeLlO") && res;
    res = single_test_strmapi(7, "12345", increment_numbers, "{(i, c) => isdigit(c) ? c + 1 : c}", "23456") && res;
    res = single_test_strmapi(8, "testing", alternate_case, "{(i, c) => i % 2 ? toupper(c) : tolower(c)}", "tEsTiNg") && res;
    res = single_test_strmapi(9, "a b c", replace_spaces, "{(i, c) => c == ' ' ? '_' : c}", "a_b_c") && res;
    
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(strmapi);
}
