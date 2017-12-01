#include "woody.h"

void	write_ehdr(int fd, Elf64_Ehdr *ehdr)
{
	ehdr->e_phnum += 1;
	write(fd, ehdr, sizeof(*ehdr));
}

int		write_woody(void *ptr)
{
	int		fd;

	if ((fd = open(NAME, FLAGS, MOD)) < 0)
		return (fd);
	write_ehdr(fd, (Elf64_Ehdr*)ptr);
	close(fd);
	return (0);
}
