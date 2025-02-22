
#include "my_utils.h"

int single_test_putendl(int test_number, char *str, int fd)
{
	set_signature_tn(test_number, "ft_putendl_fd(%s, fd: %i)", escape_str(str), fd);

	ft_putendl_fd(str, fd);
	return check_leaks(NULL);
}

int test_putendl_fd()
{
    int fd = open("fsoares", O_RDWR | O_CREAT);
    int res = single_test_putendl(1, "", fd);
    res = single_test_putendl(2, "abcdef", fd) && res;
    res = single_test_putendl(3, "1234", fd) && res;
    res = single_test_putendl(4, "567", fd) && res;
    res = single_test_putendl(5, "end!", fd) && res;
    
    lseek(fd, SEEK_SET, 0);
    char content[100] = {0};
    read(fd, content, 100);
    char *expected = "\nabcdef\n1234\n567\nend!\n";
    if(strcmp(content, expected) != 0)
        res = error("expected: %s, content of the file: %s\n", escape_str(expected), escape_str(content)) && res;
        
    set_signature_tn(6, "ft_putendl_fd(\"%s\", fd: %i)", "teste", fd);
    null_null_check(ft_putendl_fd("teste", fd), res);
    
    res = single_test_putendl(7, "     ", fd) && res;
    res = single_test_putendl(8, "\t\n\r\v\f", fd) && res;
    res = single_test_putendl(9, "Test with spaces  ", fd) && res;
    
    int fd2 = open("fsoares2", O_RDWR | O_CREAT);
    res = single_test_putendl(10, "File2", fd2) && res;
    res = single_test_putendl(11, "Test", fd2) && res;
    
    lseek(fd2, SEEK_SET, 0);
    char content2[20] = {0};
    read(fd2, content2, 20);
    if(strcmp(content2, "File2\nTest\n") != 0)
        res = error("expected: File2\\nTest\\n, content of second file: %s\n", escape_str(content2)) && res;
    
    char long_str[100];
    memset(long_str, 'x', 99);
    long_str[99] = '\0';
    res = single_test_putendl(12, long_str, fd) && res;
    
    remove("./fsoares");
    remove("./fsoares2");
    close(fd);
    close(fd2);
    return res;
}

int	main()
{
	handle_signals_with_time();
	test(putendl_fd);
}
