
#include "my_utils.h"

int single_test_itoa(int test_number, char *buffer, int n)
{
	set_signature_tn(test_number, "ft_itoa(%i)", n);
	sprintf(buffer, "%i", n);
	check_alloc_str_return(ft_itoa(n), buffer);
}

int test_itoa()
{
   char buffer[100];
   int res = 1;
   
   res = single_test_itoa(1, buffer, 0) && res;
   res = single_test_itoa(2, buffer, 1000034) && res;
   res = single_test_itoa(3, buffer, -10004) && res;
   res = single_test_itoa(4, buffer, INT_MAX) && res;
   res = single_test_itoa(5, buffer, INT_MIN) && res;
   res = single_test_itoa(6, buffer, 42) && res;
   res = single_test_itoa(7, buffer, -42) && res;
   res = single_test_itoa(8, buffer, 1) && res;
   res = single_test_itoa(9, buffer, -1) && res;
   res = single_test_itoa(10, buffer, 2147483647) && res;
   res = single_test_itoa(11, buffer, -2147483648) && res;
   res = single_test_itoa(12, buffer, 123456789) && res;
   res = single_test_itoa(13, buffer, -123456789) && res;
   res = single_test_itoa(14, buffer, 1000000000) && res;
   res = single_test_itoa(15, buffer, -1000000000) && res;
   res = single_test_itoa(16, buffer, 987654321) && res;
   res = single_test_itoa(17, buffer, -987654321) && res;
   res = single_test_itoa(18, buffer, 2000000000) && res;
   res = single_test_itoa(19, buffer, -2000000000) && res;
   res = single_test_itoa(20, buffer, 100) && res;
   res = single_test_itoa(21, buffer, -100) && res;
   res = single_test_itoa(22, buffer, 10000) && res;
   res = single_test_itoa(23, buffer, -10000) && res;
   res = single_test_itoa(24, buffer, 500000) && res;
   res = single_test_itoa(25, buffer, -500000) && res;
   for (int i = 0; i < REPETITIONS && res; i++) {
       int rd = (int)random() - RAND_MAX / 2;
       res = single_test_itoa(26 + i, buffer, rd) && res;
   }
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(itoa);
}
