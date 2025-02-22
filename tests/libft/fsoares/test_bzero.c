
#include "my_utils.h"

int single_test_bzero(int test_number, char *res, char *expected, int size)
{
	set_signature_tn(test_number, "ft_bzero(%p, %i)", res, size);
	reset(res, expected, MEM_SIZE);
	bzero(expected, size);
	ft_bzero(res, size);

	return (same_mem(expected, res, MEM_SIZE));
}

int test_bzero(void)
{
    char mem[MEM_SIZE];
    char mem_std[MEM_SIZE];
    int res = 1;

    res = single_test_bzero(1, mem, mem_std, 0) && res;
    res = single_test_bzero(2, mem, mem_std, 12) && res;
    res = single_test_bzero(3, mem, mem_std, 1) && res;
    res = single_test_bzero(4, mem, mem_std, MEM_SIZE) && res;
    res = single_test_bzero(5, mem, mem_std, MEM_SIZE - 1) && res;
    res = single_test_bzero(6, mem + 1, mem_std + 1, 4) && res;
    res = single_test_bzero(7, mem + 2, mem_std + 2, 8) && res;
    res = single_test_bzero(8, mem + 3, mem_std + 3, 7) && res;
    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = mem_std[i] = 0xFF;
    res = single_test_bzero(9, mem, mem_std, 16) && res;
    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = mem_std[i] = 0xAA;
    res = single_test_bzero(10, mem, mem_std, 16) && res;
    for (size_t size = 1; size <= 16; size++) {
        for (int i = 0; i < MEM_SIZE; i++)
            mem[i] = mem_std[i] = (char)i;
        res = single_test_bzero(10 + size, mem, mem_std, size) && res;
    }
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(bzero);
}
