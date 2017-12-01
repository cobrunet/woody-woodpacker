#include "woody.h"

int		exit_failure(char *err_message)
{
	perror(err_message);
	return (1);
}

void	*get_ptr(char *file, off_t *st_size)
{
	struct stat	buf;
	int			fd;
	void		*ptr;

	if ((fd = open(file, O_RDWR)) < 0)
		return (NULL);
	if (fstat(fd, &buf) < 0)
		return (NULL);
	if ((ptr = mmap(0, buf.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE,
		fd, 0)) == MAP_FAILED)
		return (NULL);
	*st_size = buf.st_size;
	if (close(fd))
		return (NULL);
	return (ptr);
}

int		main(int ac, char **av)
{
	void	*ptr;
	off_t	st_size;
	int		i;

	i = ac;
	while (--i > 0)
	{
		if (!(ptr = get_ptr(av[i], &st_size)))
			return (exit_failure(av[i]));
		print_header(ptr);
		if (write_woody(ptr) < 0)
			return (exit_failure(""));
		if (munmap(ptr, st_size) < 0)
			return (exit_failure(""));
	}
	return (0);
}
