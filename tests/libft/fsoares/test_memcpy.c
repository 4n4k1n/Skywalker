
#include "my_utils.h"

int single_test_memcpy(int test_number, char *dest, char *dest_std, char *src, char *src_std, int n)
{
	reset(dest, dest_std, MEM_SIZE);
	reset(src, src_std, MEM_SIZE);

	rand_str(src , rand() % 55 + 1);
	memcpy(src_std, src, 100);

	char *res = ft_memcpy(dest, src, n);
	char *res_std = memcpy(dest_std, src_std, n);

	set_signature_tn(test_number, "ft_memcpy(dest, src: %s, n: %i)", escape_str(src), n);
	return (same_return(dest, res) && same_mem(res_std, res, MEM_SIZE));
}

int test_memcpy(void)
{
    char dest[MEM_SIZE];
    char dest_std[MEM_SIZE];
    char src[MEM_SIZE];
    char src_std[MEM_SIZE];
    int res = 1;

    res = single_test_memcpy(1, dest, dest_std, src, src_std, 0);
    
    for (int n = 0; n < REPETITIONS && res; n++)
        res = single_test_memcpy(2 + n, dest, dest_std, src, src_std, rand() % 70) && res;
    
    memset(src, 'A', MEM_SIZE);
    memset(src_std, 'A', MEM_SIZE);
    res = single_test_memcpy(50, dest, dest_std, src, src_std, MEM_SIZE) && res;
    
    memset(src, 0xFF, MEM_SIZE);
    memset(src_std, 0xFF, MEM_SIZE);
    res = single_test_memcpy(51, dest, dest_std, src, src_std, MEM_SIZE - 1) && res;
    
    for (int i = 0; i < MEM_SIZE; i++) {
        src[i] = i % 256;
        src_std[i] = i % 256;
    }
    res = single_test_memcpy(52, dest, dest_std, src, src_std, MEM_SIZE) && res;
    
    memset(src, 0, MEM_SIZE);
    memset(src_std, 0, MEM_SIZE);
    src[MEM_SIZE-1] = 0xFF;
    src_std[MEM_SIZE-1] = 0xFF;
    res = single_test_memcpy(53, dest, dest_std, src, src_std, MEM_SIZE) && res;
    
    for (size_t size = 1; size <= 32 && res; size *= 2) {
        memset(src, size, size);
        memset(src_std, size, size);
        res = single_test_memcpy(60 + size, dest, dest_std, src, src_std, size) && res;
    }
    
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(memcpy);
}
