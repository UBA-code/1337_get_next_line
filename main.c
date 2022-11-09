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

	// char *h = get_next_line(fd);
	// printf("%s", h);
	// // free(h);
	// while (1)
	// 	printf("h");

	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	printf("|%s|", get_next_line(fd));
	close(fd);
	return (0);
}