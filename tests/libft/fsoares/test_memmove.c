
#include "my_utils.h"

int single_test_memmove(int test_number, char *dest, char *dest_std, char *src, char *src_std, char *value, int n)
{
	reset(dest, dest_std, MEM_SIZE);
	reset(src, src_std, MEM_SIZE);
	strcpy(src, value);
	strcpy(src_std, value);

	set_signature_tn(test_number, "ft_memmove(%p, %p: \"%s\", %i)", dest, src, src, n);

	char *result = ft_memmove(dest, src, n);
	char *expected = memmove(dest_std, src_std, n);
	return (same_return(dest, result) && same_mem(expected, result, MEM_SIZE));
}

int test_memmove(void)
{
    char dest[MEM_SIZE + 10];
    char dest_std[MEM_SIZE + 10];
    int res = 1;

    res = single_test_memmove(1, dest, dest_std, dest + 2, dest_std + 2, "123456", 4) && res;
    res = single_test_memmove(2, dest + 2, dest_std + 2, dest, dest_std, "123456", 4) && res;
    res = single_test_memmove(3, dest, dest_std, dest, dest_std, "123456", 4) && res;
    res = single_test_memmove(4, dest + 2, dest_std + 2, dest, dest_std, "123456", 0) && res;
    
    memset(dest, 'A', MEM_SIZE);
    memset(dest_std, 'A', MEM_SIZE);
    res = single_test_memmove(5, dest + 5, dest_std + 5, dest, dest_std, dest, MEM_SIZE - 5) && res;
    
    memset(dest, 'B', MEM_SIZE);
    memset(dest_std, 'B', MEM_SIZE);
    res = single_test_memmove(6, dest, dest_std, dest + 5, dest_std + 5, dest + 5, MEM_SIZE - 5) && res;
    
    for (int i = 0; i < MEM_SIZE; i++) {
        dest[i] = i % 256;
        dest_std[i] = i % 256;
    }
    res = single_test_memmove(7, dest + 1, dest_std + 1, dest, dest_std, dest, MEM_SIZE - 1) && res;
    
    memset(dest, 0xFF, MEM_SIZE);
    memset(dest_std, 0xFF, MEM_SIZE);
    res = single_test_memmove(8, dest, dest_std, dest + MEM_SIZE/2, dest_std + MEM_SIZE/2, dest + MEM_SIZE/2, MEM_SIZE/2) && res;
    
    for (size_t offset = 1; offset < 8; offset++) {
        res = single_test_memmove(10 + offset, dest + offset, dest_std + offset, dest, dest_std, "OVERLAP", 7) && res;
    }
    
    char pattern[] = "0123456789";
    for (size_t i = 1; i < 10; i++) {
        res = single_test_memmove(20 + i, dest + i, dest_std + i, dest, dest_std, pattern, 10 - i) && res;
    }

    return res;
}

int	main()
{
	handle_signals_with_time();
	test(memmove);
}
