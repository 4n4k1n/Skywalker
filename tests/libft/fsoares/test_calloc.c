
#include "my_utils.h"

int test_single_calloc(int test_number, size_t count, size_t size)
{
	set_signature_tn(test_number, "ft_calloc(%zu, %zu)", count, size);

	reset_malloc_mock();
	void *res_calloc = ft_calloc(count, size);
	void *res_std = calloc(count, size);

	int result = check_mem_size(res_calloc, count * size);
	result = same_mem(res_std, res_calloc, count * size) && result;
	result = check_leaks(res_calloc) && result;

	null_check(ft_calloc(count, size), result);
	return result;
}

int test_calloc()
{
    int res = 1;

    res = test_single_calloc(1, 0, 10) && res;
    res = test_single_calloc(2, 10, 0) && res;
    res = test_single_calloc(3, 10, sizeof(long)) && res;
    res = test_single_calloc(4, 5, sizeof(char)) && res;
    res = test_single_calloc(5, 5, sizeof(int)) && res;
    res = test_single_calloc(6, 5, sizeof(double)) && res;
    res = test_single_calloc(7, 5, sizeof(short)) && res;
    res = test_single_calloc(8, 1000, 1) && res;
    res = test_single_calloc(9, 10000, 1) && res;
    res = test_single_calloc(10, 1, 1000) && res;
    res = test_single_calloc(11, 1, 10000) && res;
    res = test_single_calloc(12, 1, SIZE_MAX) && res;
    res = test_single_calloc(13, SIZE_MAX, 1) && res;
    res = test_single_calloc(14, SIZE_MAX/2, 2) && res;
    res = test_single_calloc(15, 3, 7) && res;
    res = test_single_calloc(16, 7, 3) && res;
    res = test_single_calloc(17, 16, 16) && res;
    res = test_single_calloc(18, 32, 32) && res;
    res = test_single_calloc(19, 64, 64) && res;
    res = test_single_calloc(20, 13, 17) && res;
    res = test_single_calloc(21, 23, 29) && res;
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(calloc);
}
