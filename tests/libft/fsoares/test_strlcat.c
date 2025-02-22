
#include "my_utils.h"


int single_test_strlcat(int test_number, char *dest, char *dest_std, char *orig, char *src, int n)
{
	int result = 1;

	set_signature_tn(test_number, "ft_strlcat(\"%s\", \"%s\", %i)", orig, src, n);
	reset_with(dest, dest_std, orig, MEM_SIZE);

	int res = ft_strlcat(dest, src, n);
	int res_std = strlcat(dest_std, src, n);
	result = same_value(res_std, res);
	return same_mem(dest_std, dest, (n / 16 + 1) * 16) && result;
}

int test_strlcat(void)
{
   char dest[MEM_SIZE];
   char dest_std[MEM_SIZE];
   int res = 1;

   for (int i = 0; i < 8; i++)
       res = single_test_strlcat(1 + i, dest, dest_std, "pqrstuvwxyz", "abcd", i) && res;
   res = single_test_strlcat(9, dest, dest_std, "pqrstuvwxyz", "abcd", 20) && res;
   for (int i = 10; i < 18; i++)
       res = single_test_strlcat(i, dest, dest_std, "pqrs", "abcdefghi", i) && res;
   
   res = single_test_strlcat(18, dest, dest_std, "", "", 5) && res;
   res = single_test_strlcat(19, dest, dest_std, "hello", "", 10) && res;
   res = single_test_strlcat(20, dest, dest_std, "", "world", 10) && res;
   res = single_test_strlcat(21, dest, dest_std, "hello\n", "world", 15) && res;
   res = single_test_strlcat(22, dest, dest_std, "tab\t", "here", 12) && res;
   res = single_test_strlcat(23, dest, dest_std, "null\0", "char", 10) && res;
   res = single_test_strlcat(24, dest, dest_std, "test", "case", 1) && res;
   res = single_test_strlcat(25, dest, dest_std, "exactly", "sized", 11) && res;
   res = single_test_strlcat(26, dest, dest_std, "overflow", "test", 5) && res;
   res = single_test_strlcat(27, dest, dest_std, "thisisaverylongstring", "andmore", 30) && res;
   res = single_test_strlcat(28, dest, dest_std, "123456789", "987654321", 15) && res;
   res = single_test_strlcat(29, dest, dest_std, "Mix123", "!@#", 12) && res;
   res = single_test_strlcat(30, dest, dest_std, "   spaces   ", "tabs\t\t", 20) && res;

   return res;
}

int	main()
{
	handle_signals_with_time();
	test(strlcat);
}
