#include "woody.h"

void	write_ehdr(int fd, Elf64_Ehdr *ehdr)
{
//	ehdr->e_phnum += 1;
	write(fd, ehdr, sizeof(*ehdr));
}

void	write_phdr(int fd, Elf64_Ehdr *ehdr)
{
	Elf64_Phdr	*phdr;
	int		i;

	i = 0;
	phdr = (void*)ehdr + sizeof(Elf64_Ehdr);
	while (++i <= ehdr->e_phnum)
	{
		write(fd, phdr, sizeof(*phdr));
		phdr = phdr + sizeof(Elf64_Phdr);
	}
}

int		write_woody(void *ptr)
{
	int		fd;

	if ((fd = open(NAME, FLAGS, MOD)) < 0)
		return (fd);
	write_ehdr(fd, (Elf64_Ehdr*)ptr);
	write_phdr(fd, (Elf64_Ehdr*)ptr);
	close(fd);
	return (0);
}
