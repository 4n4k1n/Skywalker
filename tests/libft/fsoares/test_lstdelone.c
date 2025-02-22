
#include "list_utils.h"


void free_str(void *str)
{
    free(str);
}

void free_str_ptr(void *str)
{
    free(*((void **)str));
}

int test_lstdelone()
{
    int res = 1;
    char *s, *elem_str;
    t_list *l, *keep;
    t_list **list;

    // Test 1: Basic deletion with direct string
    elem_str = node_to_str(lstnew("add"));
    set_signature_tn(1, "ft_lstdelone(%s, [(x) => free(x)])", elem_str);
    free(elem_str);
    reset_malloc_mock();
    s = malloc(6);
    strcpy(s, "teste");
    l = lstnew(s);
    ft_lstdelone(l, free_str);
    res = check_leaks(NULL);
    if (!res)
    {
        fseek(errors_file, -1, SEEK_CUR);
        fprintf(errors_file, "" BMAG "del" NC " should be used on " BLU "content" NC \
        ", and " BMAG "free" NC " on the " BLU "lst" NC "\n\n");
    }

    // Test 2: Deletion with pointer to string
    char *warn = (NC "Do not use " BMAG "del" NC " on the " BLU "lst" NC ". Use " BMAG "free" NC " instead");
    set_signature_tn(2, "ft_lstdelone({node: content->ptr->\"test\"}, [(x) => free(" RED "*" CYN "x)]): %s", warn);
    reset_malloc_mock();
    s = malloc(5);
    strcpy(s, "test");
    l = lstnew(&s);
    ft_lstdelone(l, free_str_ptr);
    res = check_leaks(NULL) && res;

    // Test 3: Ensure only target node is freed
    s = malloc(5);
    strcpy(s, "test");
    list = create_list(2, s, "second");
    keep = (*list)->next;
    char *lst_str = list_to_str(list);
    set_signature_tn(3, "ft_lstdelone(%s, [(x) => free(x)]): " NC "The second node should not be freed", lst_str);
    reset_malloc_mock();
    ft_lstdelone(*list, free_str);
    free(keep);
    res = check_leaks(NULL) && res;

    // Test 4: Delete node with empty string
    reset_malloc_mock();
    s = malloc(1);
    s[0] = '\0';
    l = lstnew(s);
    elem_str = node_to_str(l);
    set_signature_tn(4, "ft_lstdelone(%s, [(x) => free(x)])", elem_str);
    free(elem_str);
    ft_lstdelone(l, free_str);
    res = check_leaks(NULL) && res;

    // Test 5: Delete node with large string
    reset_malloc_mock();
    s = malloc(1000);
    memset(s, 'A', 999);
    s[999] = '\0';
    l = lstnew(s);
    elem_str = node_to_str(l);
    set_signature_tn(5, "ft_lstdelone(%s, [(x) => free(x)])", elem_str);
    free(elem_str);
    ft_lstdelone(l, free_str);
    res = check_leaks(NULL) && res;

    // Test 6: Delete middle node
    reset_malloc_mock();
    s = malloc(5);
    strcpy(s, "test");
    list = create_list(3, "first", s, "third");
    t_list *first = *list;
    t_list *third = (*list)->next->next;
    l = (*list)->next;
    elem_str = node_to_str(l);
    set_signature_tn(6, "ft_lstdelone(%s, [(x) => free(x)])", elem_str);
    free(elem_str);
    ft_lstdelone(l, free_str);
    free(first);
    free(third);
    res = check_leaks(NULL) && res;

    return res;
}

int	main()
{
	handle_signals_with_time();
	test(lstdelone);
}
