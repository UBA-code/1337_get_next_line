#include "get_next_line.h"

int main()
{
	size_t fd = open("./test.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);

	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	close(fd);
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	close(fd);
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	close(fd);
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	fd = open("./test.txt", O_RDONLY);
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));
	// printf("|%s|", get_next_line(fd));


	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}