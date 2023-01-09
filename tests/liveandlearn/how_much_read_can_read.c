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
	printf("size: %lu\n", size);
	printf("Bytesread: %li\n", read(fd, buffer, size));
	printf("Buffer: '%s'\n\n", buffer);
	// lseek(fd, 0, SEEK_SET);
	free(buffer);
	close(fd);
}

int	main(void)
{
	char	*path;

	path = "testfile_nl1.txt";
	read_and_store(path, 0);
	read_and_store(path, 1);
	read_and_store(path, 10);
	read_and_store(path, 16); // line size
	read_and_store(path, 42);
	read_and_store(path, 62);
	read_and_store(path, 63); // Size max
	// read_and_store(path, 64);
	// read_and_store(path, 999);
	// read_and_store(path, 1024);
	// read_and_store(path, 9999);
	// read_and_store(path, 20230);
	// read_and_store(path, 10000000);
	read_and_store(path, BUFFER_SIZE);
}