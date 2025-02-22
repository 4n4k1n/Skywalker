
#include "my_utils.h"

int single_test_strchr(int test_number, char *str, int ch)
{
	set_signature_tn(test_number, "ft_strchr(%p: \"%s\", %i: %s)", str, str, ch, escape_chr(ch));
	char *res = ft_strchr(str, ch);
	char *res_std = strchr(str, ch);

	return same_offset(str, res_std, str, res);
}

int test_strchr(void)
{
    int res = 1;
    res = single_test_strchr(1, "teste", 't') && res;
    res = single_test_strchr(2, "teste", 'e') && res;
    res = single_test_strchr(3, "teste", '\0') && res;
    res = single_test_strchr(4, "teste", 'a') && res;
    res = single_test_strchr(5, "teste", 'e' + 256) && res;
    res = single_test_strchr(6, "teste", 1024) && res;
    
    res = single_test_strchr(7, "", '\0') && res;
    res = single_test_strchr(8, "hello world", ' ') && res;
    res = single_test_strchr(9, "hello world", 'w') && res;
    res = single_test_strchr(10, "aaa", 'a') && res;
    
    res = single_test_strchr(11, "test\0hidden", '\0') && res;
    res = single_test_strchr(12, "test\n\t\r", '\n') && res;
    res = single_test_strchr(13, "test\n\t\r", '\t') && res;
    res = single_test_strchr(14, "test\n\t\r", '\r') && res;
    
    res = single_test_strchr(15, "abcdef", 'f') && res;
    res = single_test_strchr(16, "abcdef", 'x') && res;
    
    res = single_test_strchr(17, "12345", '1') && res;
    res = single_test_strchr(18, "12345", '5') && res;
    
    char special[4];
    special[0] = -1;
    special[1] = -2;
    special[2] = -3;
    special[3] = 0;
    res = single_test_strchr(19, special, -1) && res;
    res = single_test_strchr(20, special, -2) && res;
    
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(strchr);
}
