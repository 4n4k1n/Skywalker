
#include "my_utils.h"

int single_test_strlcpy(int test_number, char *dest, char *dest_std, char *src, int n)
{
	int result = 1;
	reset(dest, dest_std, MEM_SIZE);

	set_signature_tn(test_number, "ft_strlcpy(dest, \"%s\", %i)", src, n);

	int res = ft_strlcpy(dest, src, n);
	int res_std = strlcpy(dest_std, src, n);
	result = same_value(res_std, res);
	return same_mem(dest_std, dest, MEM_SIZE) && result;
}

int test_strlcpy(void)
{
   char dest[MEM_SIZE];
   char dest_std[MEM_SIZE];
   int res = 1;
   res = single_test_strlcpy(1, dest, dest_std, "aaa", 0) && res;
   res = single_test_strlcpy(2, dest, dest_std, "aaa", 2) && res;
   res = single_test_strlcpy(3, dest, dest_std, "aaa", 3) && res;
   res = single_test_strlcpy(4, dest, dest_std, "aaa", 4) && res;
   res = single_test_strlcpy(5, dest, dest_std, "aasdjj;s;sa", 100) && res;
   res = single_test_strlcpy(6, dest, dest_std, "", 5) && res;
   res = single_test_strlcpy(7, dest, dest_std, "hello\n", 7) && res;
   res = single_test_strlcpy(8, dest, dest_std, "test\0case", 10) && res;
   res = single_test_strlcpy(9, dest, dest_std, "abc", 1) && res;
   res = single_test_strlcpy(10, dest, dest_std, "   spaces   ", 12) && res;
   res = single_test_strlcpy(11, dest, dest_std, "\t\n\r", 4) && res;
   res = single_test_strlcpy(12, dest, dest_std, "123456789", 5) && res;
   res = single_test_strlcpy(13, dest, dest_std, "!@#$%^&*()", 11) && res;
   res = single_test_strlcpy(14, dest, dest_std, "exact", 5) && res;
   res = single_test_strlcpy(15, dest, dest_std, "thisisaverylongstring", 15) && res;
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(strlcpy);
}
