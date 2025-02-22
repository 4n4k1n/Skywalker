
#include "my_utils.h"

int single_test_memchr(int test_number, char *str, int ch, size_t n)
{
	set_signature_tn(test_number, "ft_memchr(%p, %i(%x): %s, %zu)", str, ch, ch % 0x100, escape_chr(ch), n);
	char *res = ft_memchr(str, ch, n);
	char *res_std = memchr(str, ch, n);

	int result = same_offset(str, res_std, str, res);
	if (!result) {
		fprintf(errors_file, YEL "Memory content:\n" NC);
		print_mem_full(str, 0x30);
		fprintf(errors_file, "\n");
	}
	return result;
}

int test_memchr() {
    int res = 1;
    char str[MEM_SIZE];
    
    res = single_test_memchr(1, rand_bytes(str, 0x31), 123, 0) && res;
    
    for (int i = 0; i < REPETITIONS && res; i++) {
        res = single_test_memchr(2 + i, rand_bytes(str, 0x31), rand() % 0x400, rand() % 0x30) && res;
    }

    str[0] = '\0';
    res = single_test_memchr(101, str, 1, '\0') && res;

    memset(str, 'A', MEM_SIZE - 1);
    str[MEM_SIZE - 1] = '\0';
    res = single_test_memchr(102, str, MEM_SIZE, 'A') && res;

    memset(str, 'B', MEM_SIZE);
    res = single_test_memchr(103, str, MEM_SIZE, 'Z') && res;

    str[MEM_SIZE - 1] = 'X';
    res = single_test_memchr(104, str, MEM_SIZE, 'X') && res;

    memset(str, 1, MEM_SIZE);
    str[0] = 2;
    res = single_test_memchr(105, str, MEM_SIZE, 2) && res;

    memset(str, 0xFF, MEM_SIZE);
    res = single_test_memchr(106, str, MEM_SIZE, 0xFF) && res;

    for (int i = 0; i < MEM_SIZE; i++) {
        str[i] = i % 256;
    }
    res = single_test_memchr(107, str, MEM_SIZE, 0x7F) && res;

    for (size_t size = 1; size <= 32 && res; size *= 2) {
        res = single_test_memchr(108 + size, rand_bytes(str, size), size, str[size-1]) && res;
    }

    char pattern[] = {0x00, 0xFF, 0x7F, 0x80};
    for (size_t i = 0; i < sizeof(pattern) && res; i++) {
        memset(str, pattern[i], MEM_SIZE);
        res = single_test_memchr(120 + i, str, MEM_SIZE, pattern[i]) && res;
    }

    return res;
}

int	main()
{
	handle_signals_with_time();
	test(memchr);
}
