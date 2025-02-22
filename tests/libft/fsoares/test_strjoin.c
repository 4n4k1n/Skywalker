
#include "my_utils.h"

int test_single_strjoin(int test_number, char *str1, char *str2, char *expected)
{
	set_signature_tn(test_number, "ft_strjoin(\"%s\", \"%s\")", str1, str2);
	check_alloc_str_return(ft_strjoin(str1, str2), expected);
}

int test_strjoin()
{
    int res = 1;
    res = test_single_strjoin(1, "", "", "") && res;
    res = test_single_strjoin(2, "abc", "", "abc") && res;
    res = test_single_strjoin(3, "", "abc", "abc") && res;
    res = test_single_strjoin(4, "abcd", "efghi", "abcdefghi") && res;
    res = test_single_strjoin(5, "Hello", " World", "Hello World") && res;
    res = test_single_strjoin(6, "12345", "67890", "1234567890") && res;
    res = test_single_strjoin(7, "Test\n", "Case", "Test\nCase") && res;
    res = test_single_strjoin(8, "\t", "\t", "\t\t") && res;
    res = test_single_strjoin(9, "   ", "   ", "      ") && res;
    res = test_single_strjoin(10, "a", "b", "ab") && res;
    res = test_single_strjoin(11, "!@#", "$%^", "!@#$%^") && res;
    res = test_single_strjoin(12, "End", "\0Start", "End\0Start") && res;
    res = test_single_strjoin(13, "Multiple\n", "Lines\n", "Multiple\nLines\n") && res;
    res = test_single_strjoin(14, "Tab\t", "Here", "Tab\tHere") && res;
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(strjoin);
}
