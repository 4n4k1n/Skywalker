
#include "list_utils.h"

int single_test_lstsize(int test_number, t_list **list, int expected)
{
	char *list_str = list_to_str(list);
	set_signature_tn(test_number, "ft_lstsize(%s)", list_str);
	free(list_str);

	int result = same_value(expected, ft_lstsize(*list));
	null_null_check(ft_lstsize(*list), result);
	return result;
}

int test_lstsize()
{
   int res = single_test_lstsize(1, create_list(0), 0);
   
   res = single_test_lstsize(2, create_list(1, "one"), 1) && res;
   
   res = single_test_lstsize(3,
       create_list(5, "one", "two", "three", "four", "five"),
       5) && res;
       
   res = single_test_lstsize(4, create_list(2, "hello", "world"), 2) && res;
   
   res = single_test_lstsize(5, create_list(3, "a", "b", "c"), 3) && res;
   
   res = single_test_lstsize(6, 
       create_list(6, "1", "2", "3", "4", "5", "6"), 
       6) && res;
       
   res = single_test_lstsize(7,
       create_list(10, "a", "b", "c", "d", "e", "f", "g", "h", "i", "j"),
       10) && res;
       
   res = single_test_lstsize(8,
       create_list(4, "test1", "test2", "test3", "test4"),
       4) && res;
       
   res = single_test_lstsize(9,
       create_list(7, "mon", "tue", "wed", "thu", "fri", "sat", "sun"),
       7) && res;
       
   res = single_test_lstsize(10,
       create_list(8, "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th"),
       8) && res;

   return res;
}

int	main()
{
	handle_signals_with_time();
	test(lstsize);
}
