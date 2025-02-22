
#include "list_utils.h"

void free_str_ptr(void *str)
{
	free(*((void **)str));
}

char *node_ptr_to_str(t_list *node)
{
	char *res = malloc(1000);
	if (node == NULL)
		sprintf(res, "(null)");
	else {
		sprintf(res, "{node: ptr-> %s}", escape_str((char *)node->content));
	}
	return res;
}


int test_single_lstclear(int test_number, t_list **list)
{
	t_list *to_func = NULL;
	char *args[10];
	int i = 0;

	char *s = list_to_str_fn(list, node_ptr_to_str);
	set_signature_tn(test_number, "ft_lstclear(%s, [(x) => free(" RED "*" CYN "x)])", s); free(s);

	while (*list != NULL)
	{
		args[i] = my_strdup((*list)->content);
		lstadd_back(&to_func, lstnew(args + i));
		*list = (*list)->next;
		i++;
	}

	ft_lstclear(&to_func, free_str_ptr);
	int res = check_leaks(NULL);
	if (to_func != NULL)
		return error("The value stored in the lst should be NULL after the clear.\n");
	return res;
}

int test_lstclear()
{
   int res = test_single_lstclear(1, create_list(0));
   res = test_single_lstclear(2, create_list(1, "hello!")) && res;
   res = test_single_lstclear(3,
       create_list(5, "um", "dois", "tres", "quatro", "cinco")) && res;
   res = test_single_lstclear(4, create_list(2, "test1", "test2")) && res;
   res = test_single_lstclear(5, create_list(3, "a", "b", "c")) && res;
   res = test_single_lstclear(6, 
       create_list(4, "one", "two", "three", "four")) && res;
   res = test_single_lstclear(7,
       create_list(6, "1", "2", "3", "4", "5", "6")) && res;
   res = test_single_lstclear(8,
       create_list(7, "a", "b", "c", "d", "e", "f", "g")) && res;
   res = test_single_lstclear(9,
       create_list(8, "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth")) && res;
   res = test_single_lstclear(10,
       create_list(10, "1", "2", "3", "4", "5", "6", "7", "8", "9", "10")) && res;
   return res;
}

int	main()
{
	handle_signals_with_time();
	test(lstclear);
}
