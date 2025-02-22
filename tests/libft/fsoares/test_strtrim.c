
#include "my_utils.h"

int single_test_strtrim(int test_number, char *str, char *set, char *expected)
{
	set_signature_tn(test_number, "ft_strtrim(\"%s\", \"%s\")", str, set);
	check_alloc_str_return(ft_strtrim(str, set), expected);
}

int test_strtrim()
{
   int res = single_test_strtrim(1, "", "", "");
   res = single_test_strtrim(2, "abcd", "", "abcd") && res;
   res = single_test_strtrim(3, "", "cdef", "") && res;
   res = single_test_strtrim(4, " . abcd", " ", ". abcd") && res;
   res = single_test_strtrim(5, "ab cd f ", " ", "ab cd f") && res;
   res = single_test_strtrim(6, "xxxz test with x and z and x . zx xx z", "z x", "test with x and z and x .") && res;
   res = single_test_strtrim(7, " abxfg ", "x", " abxfg ") && res;
   res = single_test_strtrim(8, ".teste, bla ,.,.", ",.", "teste, bla ") && res;
   res = single_test_strtrim(9, "\t\n Hello \t\n", "\t\n", "Hello") && res;
   res = single_test_strtrim(10, "***hello***", "*", "hello") && res;
   res = single_test_strtrim(11, "   multiple    spaces   ", " ", "multiple    spaces") && res;
   res = single_test_strtrim(12, "12test321", "123", "test") && res;
   res = single_test_strtrim(13, "#@!text!@#", "!@#", "text") && res;
   res = single_test_strtrim(14, "  \t  mixed trim  \n  ", " \t\n", "mixed trim") && res;
   res = single_test_strtrim(15, "aabbcctext", "abc", "text") && res;
   res = single_test_strtrim(16, "...test...", ".", "test") && res;
   res = single_test_strtrim(17, "    ", " ", "") && res;
   res = single_test_strtrim(18, "\n\t\r\n", "\n\t\r", "") && res;
   res = single_test_strtrim(19, "##no trim###", "#", "no trim") && res;
   res = single_test_strtrim(20, "--text--", "-", "text") && res;
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(strtrim);
}
