
#include "my_utils.h"

int test_single_substr(int test_number, char *str, unsigned int start, size_t size, char *expected)
{
	set_signature_tn(test_number, "ft_substr(\"%s\", %u, %zu)", str, start, size);
	check_alloc_str_return(ft_substr(str, start, size), expected);
}

int test_substr()
{
   int res = 1;
   res = test_single_substr(1, "", 0, 0, "") && res;
   res = test_single_substr(2, "", 0, 1, "") && res;
   res = test_single_substr(3, "", 1, 1, "") && res;
   res = test_single_substr(4, "hola", -1, 0, "") && res;
   res = test_single_substr(5, "hola", 0, -1, "hola") && res;
   res = test_single_substr(6, "hola", -1, -1, "") && res;
   res = test_single_substr(7, "hola", 0, 0, "") && res;
   res = test_single_substr(8, "hola", 0, 1, "h") && res;
   res = test_single_substr(9, "hola", 0, 3, "hol") && res;
   res = test_single_substr(10, "hola", 0, 4, "hola") && res;
   res = test_single_substr(11, "hola", 0, 5, "hola") && res;
   res = test_single_substr(12, "hola", 2, 0, "") && res;
   res = test_single_substr(13, "hola", 2, 1, "l") && res;
   res = test_single_substr(14, "hola", 2, 2, "la") && res;
   res = test_single_substr(15, "hola", 2, 3, "la") && res;
   res = test_single_substr(16, "hola", 2, 30, "la") && res;
   res = test_single_substr(17, "hola", 3, 0, "") && res;
   res = test_single_substr(18, "hola", 3, 1, "a") && res;
   res = test_single_substr(19, "hola", 3, 2, "a") && res;
   res = test_single_substr(20, "hola", 4, 0, "") && res;
   res = test_single_substr(21, "hola", 4, 1, "") && res;
   res = test_single_substr(22, "hola", 4, 20, "") && res;
   res = test_single_substr(23, "hola", 5, 2, "") && res;
   res = test_single_substr(24, "hello world", 6, 5, "world") && res;
   res = test_single_substr(25, "test\0test", 4, 1, "\0") && res;
   res = test_single_substr(26, "hello\n", 5, 1, "\n") && res;
   res = test_single_substr(27, "   spaces   ", 3, 6, "spaces") && res;
   res = test_single_substr(28, "12345", 1, 3, "234") && res;
   res = test_single_substr(29, "!@#$%", 2, 2, "#$") && res;
   res = test_single_substr(30, "testing", 10, 2, "") && res;
   res = test_single_substr(31, "boundary", 7, 1, "y") && res;
   res = test_single_substr(32, "overlap", 4, 10, "lap") && res;
   res = test_single_substr(33, "special", 0, 7, "special") && res;
   return res;
}

int main()
{
	handle_signals_with_time();
	test(substr);
}
