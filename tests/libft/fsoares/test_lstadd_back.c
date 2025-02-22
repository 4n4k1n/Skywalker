
#include "list_utils.h"

int single_test_lstadd_back(int test_number, t_list **list, t_list *new, t_list **expected)
{
	char *list_str = list_to_str(list);
	char *node_str = node_to_str(new);
	set_signature_tn(test_number, "ft_lstadd_back(%s, %s)", list_str, node_str);
	free(list_str); free(node_str);

	ft_lstadd_back(list, new);
	int result = same_list(expected, list);
	null_null_check(ft_lstadd_back(list, new), result);
	return result;
}

int test_lstadd_back()
{
   int res = single_test_lstadd_back(1,
       create_list(0),
       lstnew("last"),
       create_list(1, "last"));
   res = single_test_lstadd_back(2,
       create_list(1, "first"),
       lstnew("last"), 
       create_list(2, "first", "last")) && res;
   res = single_test_lstadd_back(3,
       create_list(5, "one", "two", "three", "four", "five"),
       lstnew("last"),
       create_list(6, "one", "two", "three", "four", "five", "last")) && res;
   res = single_test_lstadd_back(4,
       create_list(2, "hello", "world"),
       lstnew("!"),
       create_list(3, "hello", "world", "!")) && res;
   res = single_test_lstadd_back(5,
       create_list(3, "a", "b", "c"),
       lstnew("d"),
       create_list(4, "a", "b", "c", "d")) && res;
   res = single_test_lstadd_back(6,
       create_list(4, "test1", "test2", "test3", "test4"),
       lstnew("test5"),
       create_list(5, "test1", "test2", "test3", "test4", "test5")) && res;
   res = single_test_lstadd_back(7,
       create_list(1, "start"),
       lstnew("end"),
       create_list(2, "start", "end")) && res;
   res = single_test_lstadd_back(8,
       create_list(3, "1", "2", "3"),
       lstnew("4"),
       create_list(4, "1", "2", "3", "4")) && res;
   res = single_test_lstadd_back(9,
       create_list(2, "first", "second"),
       lstnew("third"),
       create_list(3, "first", "second", "third")) && res;
   res = single_test_lstadd_back(10,
       create_list(4, "a", "b", "c", "d"),
       lstnew("e"),
       create_list(5, "a", "b", "c", "d", "e")) && res;
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(lstadd_back);
}
