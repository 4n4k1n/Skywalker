
#include "list_utils.h"

void count_chars(void *s)
{
	char *str = (char *)s;
	sprintf(str, "%zu", strlen(str));
}

int single_test_lstiter(int test_number, t_list **initial, t_list ** expected)
{
	char *l_str = list_to_str(initial);
	set_signature_tn(test_number, "ft_lstiter(%s, [(s) => (s = strlen(s))])", l_str); free(l_str);
	ft_lstiter(*initial, count_chars);
	int res = same_list(expected, initial);

	null_null_check(ft_lstiter(*initial, count_chars), res);
	return res;
}

int test_lstiter()
{
   int res = single_test_lstiter(1, create_list(0), create_list(0));
   
   res = single_test_lstiter(2, 
       create_list(1, strdup("one")), 
       create_list(1, "3")) && res;
   
   res = single_test_lstiter(3,
       create_list(5, strdup("um"), strdup("dois"), strdup("tres"), strdup("quatro"), strdup("cinco")),
       create_list(5, "2", "4", "4", "6", "5")) && res;
       
   res = single_test_lstiter(4,
       create_list(3, strdup("hello"), strdup("world"), strdup("!")),
       create_list(3, "5", "5", "1")) && res;
       
   res = single_test_lstiter(5,
       create_list(4, strdup("a"), strdup("bb"), strdup("ccc"), strdup("dddd")),
       create_list(4, "1", "2", "3", "4")) && res;
       
   res = single_test_lstiter(6,
       create_list(2, strdup("test"), strdup("case")),
       create_list(2, "4", "4")) && res;
       
   res = single_test_lstiter(7,
       create_list(6, strdup("1"), strdup("22"), strdup("333"), strdup("4444"), strdup("55555"), strdup("666666")),
       create_list(6, "1", "2", "3", "4", "5", "6")) && res;
       
   res = single_test_lstiter(8,
       create_list(1, strdup("abcdefghijk")),
       create_list(1, "11")) && res;
       
   res = single_test_lstiter(9,
       create_list(3, strdup("x"), strdup("yy"), strdup("zzz")),
       create_list(3, "1", "2", "3")) && res;
       
   res = single_test_lstiter(10,
       create_list(4, strdup("first"), strdup("second"), strdup("third"), strdup("fourth")),
       create_list(4, "5", "6", "5", "6")) && res;

   return res;
}

int	main()
{
	handle_signals_with_time();
	test(lstiter);
}
