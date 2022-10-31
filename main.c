#include "get_next_line.h"

size_t main()
{
	size_t fd = open("./test.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	prsize_tf("%s", get_next_line(fd));
	prsize_tf("%s", get_next_line(fd));
	prsize_tf("%s", get_next_line(fd));
	prsize_tf("%s", get_next_line(fd));
	prsize_tf("%s", get_next_line(fd));
	prsize_tf("%s", get_next_line(fd));
	prsize_tf("%s", get_next_line(fd));
	close(fd);
	return (0);
}