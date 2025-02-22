
#include "my_utils.h"

int single_test_strdup(int test_number, char *str, char *expected)
{
	set_signature_tn(test_number, "ft_strdup(%s)", escape_str(str));
	check_alloc_str_return(ft_strdup(str), expected);
}

int test_strdup()
{
    int res = 1;
    res = single_test_strdup(1, "", "") && res;
    res = single_test_strdup(2, "sadfvbf", "sadfvbf") && res;
    res = single_test_strdup(3, "fdfjkdf\n35346", "fdfjkdf\n35346") && res;
    res = single_test_strdup(4, "a", "a") && res;
    res = single_test_strdup(5, " ", " ") && res;
    res = single_test_strdup(6, "\t\n\r", "\t\n\r") && res;
    res = single_test_strdup(7, "Hello World!", "Hello World!") && res;
    res = single_test_strdup(8, "123456789", "123456789") && res;
    res = single_test_strdup(9, "!@#$%^&*()", "!@#$%^&*()") && res;
    res = single_test_strdup(10, "Mixed123!@#", "Mixed123!@#") && res;
    res = single_test_strdup(11, "Lorem\0ipsum", "Lorem\0ipsum") && res;
    res = single_test_strdup(12, "Tab\there", "Tab\there") && res;
    res = single_test_strdup(13, "Multiple\nNew\nLines", "Multiple\nNew\nLines") && res;
    res = single_test_strdup(14, "   Spaces   ", "   Spaces   ") && res;
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(strdup);
}
