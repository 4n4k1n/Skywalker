
#include "list_utils.h"

int single_test_lstlast(int test_number, t_list **list, t_list *expected)
{
	char *list_str = list_to_str(list);
	set_signature_tn(test_number, "ft_lstlast(%s)", list_str);
	free(list_str);

	int result = same_list_elem(expected, ft_lstlast(*list));
	null_null_check(ft_lstlast(*list), result);
	return result;
}

int test_lstlast()
{
   int res = single_test_lstlast(1, create_list(0), NULL);
   
   res = single_test_lstlast(2, create_list(1, "one"), lstnew("one")) && res;
   
   res = single_test_lstlast(3,
       create_list(5, "one", "two", "three", "four", "five"),
       lstnew("five")) && res;
       
   res = single_test_lstlast(4,
       create_list(2, "hello", "world"),
       lstnew("world")) && res;
       
   res = single_test_lstlast(5,
       create_list(3, "a", "b", "c"),
       lstnew("c")) && res;
       
   res = single_test_lstlast(6,
       create_list(4, "first", "second", "third", "last"),
       lstnew("last")) && res;
       
   res = single_test_lstlast(7,
       create_list(6, "1", "2", "3", "4", "5", "6"),
       lstnew("6")) && res;
       
   res = single_test_lstlast(8,
       create_list(1, "single"),
       lstnew("single")) && res;
       
   res = single_test_lstlast(9,
       create_list(7, "mon", "tue", "wed", "thu", "fri", "sat", "sun"),
       lstnew("sun")) && res;
       
   res = single_test_lstlast(10,
       create_list(4, "spring", "summer", "fall", "winter"),
       lstnew("winter")) && res;

   return res;
}

int	main()
{
	handle_signals_with_time();
	test(lstlast);
}
