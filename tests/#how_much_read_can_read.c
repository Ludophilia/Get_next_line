#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

void	read_and_store(char *str, size_t size)
{
	int		fd;
	char	*buffer;

	fd = open(str, O_RDONLY);
	buffer = calloc(size + 1, 1);
	printf("Bytesread: %li\n", read(fd, buffer, size));
	printf("Buffer: '%s'\n\n", buffer);
	// lseek(fd, 0, SEEK_SET);
	free(buffer);
	close(fd);
}

int	main(void)
{
	read_and_store("testfile0.txt", 0);
	read_and_store("testfile0.txt", 1);
	read_and_store("testfile0.txt", 10);
	read_and_store("testfile0.txt", 16); // line size
	read_and_store("testfile0.txt", 42);
	read_and_store("testfile0.txt", 62);
	read_and_store("testfile0.txt", 63); // Size max
	// read_and_store("testfile0.txt", 64);
	// read_and_store("testfile0.txt", 999);
	// read_and_store("testfile0.txt", 1024);
	// read_and_store("testfile0.txt", 9999);
	// read_and_store("testfile0.txt", 20230);
	// read_and_store("testfile0.txt", 10000000);
	read_and_store("testfile0.txt", BUFFER_SIZE);
}