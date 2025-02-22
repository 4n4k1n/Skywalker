
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

int test_strmapi()
{
   int res = single_test_strmapi(1, "", add, "{(i, c) => i + c}", "");
   res = single_test_strmapi(2, "abcd0 ", add, "{(i, c) => i + c}", "aceg4%") && res;
   res = single_test_strmapi(3, "abcdfsdfs", to_char_zero, "{(i, c) => '0'}", "000000000") && res;
   res = single_test_strmapi(4, "123", add, "{(i, c) => i + c}", "246") && res;
   res = single_test_strmapi(5, "   ", add, "{(i, c) => i + c}", "#%'") && res;
   res = single_test_strmapi(6, "aaa", add, "{(i, c) => i + c}", "abc") && res;
   res = single_test_strmapi(7, "000", to_char_zero, "{(i, c) => '0'}", "000") && res;
   res = single_test_strmapi(8, "xyz", add, "{(i, c) => i + c}", "y{|") && res;
   res = single_test_strmapi(9, "\n\n\n", add, "{(i, c) => i + c}", "\v\f\r") && res;
   res = single_test_strmapi(10, "test!", add, "{(i, c) => i + c}", "uftu&") && res;
   res = single_test_strmapi(11, "12345", to_char_zero, "{(i, c) => '0'}", "00000") && res;
   res = single_test_strmapi(12, "a1b2c", add, "{(i, c) => i + c}", "b3d5f") && res;
   res = single_test_strmapi(13, "\t\r\n", add, "{(i, c) => i + c}", "\v\016\r") && res;
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(strmapi);
}
