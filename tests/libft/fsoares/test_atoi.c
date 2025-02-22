
#include "my_utils.h"

int single_test_atoi(int test_number, char *str)
{
	set_signature_tn(test_number, "atoi(%s)", escape_str(str));
	return same_value(atoi(str), ft_atoi(str));
}

int test_atoi(void)
{
    char buffer[200];
    int res = 1;
	
    res = single_test_atoi(1, " \t\v\n\r\f123") && res;
    res = single_test_atoi(2, "0") && res;
    res = single_test_atoi(3, "-1000043") && res;
    res = single_test_atoi(4, "+0000000000000000000000000000000000000000000000000000123") && res;
    res = single_test_atoi(5, " 123") && res;
    res = single_test_atoi(6, "--123") && res;
    res = single_test_atoi(7, "-+123") && res;
    res = single_test_atoi(8, "+-123") && res;
    res = single_test_atoi(9, "++123") && res;
    res = single_test_atoi(10, "- 123") && res;
    res = single_test_atoi(11, "+ 123") && res;
    res = single_test_atoi(12, "+\n123") && res;
    res = single_test_atoi(13, "1209") && res;
    res = single_test_atoi(14, "12/3") && res;
    res = single_test_atoi(15, "12;3") && res;
    sprintf(buffer, "%i", INT_MAX);
    res = single_test_atoi(16, buffer) && res;
    sprintf(buffer, "%i", INT_MIN);
    res = single_test_atoi(17, buffer) && res;
    res = single_test_atoi(300, "") && res;
    res = single_test_atoi(301, "   ") && res;
    res = single_test_atoi(302, "-000123") && res;
    res = single_test_atoi(303, "+000123") && res;
    res = single_test_atoi(304, "123   ") && res;
    res = single_test_atoi(305, "-123   ") && res;
    res = single_test_atoi(306, "  123abc") && res;
    res = single_test_atoi(307, "  -123abc") && res;
    // sprintf(buffer, "%li", (long)INT_MAX + 1);
    res = single_test_atoi(308, buffer) && res;
    // sprintf(buffer, "%li", (long)INT_MIN - 1);
    res = single_test_atoi(309, buffer) && res;
    res = single_test_atoi(310, "000") && res;
    res = single_test_atoi(311, "-000") && res;
    res = single_test_atoi(312, "a123") && res;
    res = single_test_atoi(313, "@123") && res;
    res = single_test_atoi(314, "123.456") && res;
    res = single_test_atoi(315, "-123.456") && res;
    res = single_test_atoi(316, "0x123") && res;
    res = single_test_atoi(317, "-   123") && res;
    res = single_test_atoi(318, "+   123") && res;
    for (int i = 0; i <= 0xFF; i++) {
        sprintf(buffer, "%c %i", i, i + 1);
        res = single_test_atoi(18 + i, buffer) && res;
    }
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(atoi);
}
