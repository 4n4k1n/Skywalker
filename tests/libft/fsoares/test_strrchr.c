
#include "my_utils.h"

int single_test_strrchr(int test_number, char *str, int ch)
{
	set_signature_tn(test_number, "ft_strrchr(%p: \"%s\", %i: %s)", str, str, ch, escape_chr(ch));
	char *res = ft_strrchr(str, ch);
	char *res_std = strrchr(str, ch);

	return same_offset(str, res_std, str, res);
}

int test_strrchr(void)
{
   int res = 1;
   res = single_test_strrchr(1, "teste", 'e') && res;
   res = single_test_strrchr(2, "teste", '\0') && res;
   res = single_test_strrchr(3, "xteste", 'x') && res;
   res = single_test_strrchr(4, "teste", 'x') && res;
   res = single_test_strrchr(5, "teste", 1024 + 'e') && res;
   res = single_test_strrchr(6, "teste", 1024) && res;
   res = single_test_strrchr(7, "pepe y cparlos", 'c') && res;
   res = single_test_strrchr(8, "", 'a') && res;
   res = single_test_strrchr(9, "hello\n", '\n') && res;
   res = single_test_strrchr(10, "test\0hidden", '\0') && res;
   res = single_test_strrchr(11, "    ", ' ') && res;
   res = single_test_strrchr(12, "abcabc", 'b') && res;
   res = single_test_strrchr(13, "123321", '2') && res;
   res = single_test_strrchr(14, "!@#$@", '@') && res;
   res = single_test_strrchr(15, "aaa\0aaa", 'a') && res;
   res = single_test_strrchr(16, "\t\n\r", '\t') && res;
   res = single_test_strrchr(17, "multiple e's", 'e') && res;
   res = single_test_strrchr(18, "last char t", 't') && res;
   res = single_test_strrchr(19, "no match here", 'z') && res;
   res = single_test_strrchr(20, "special case", 1024 + 'l') && res;
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(strrchr);
}
