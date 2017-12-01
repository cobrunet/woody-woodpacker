#ifndef WOODY_H
# define WOODY_H

# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <elf.h>

# define NAME		"woody"
# define MOD		0755
# define FLAGS		(O_WRONLY | O_CREAT)

/* woody.c */
void	*get_ptr(char *file, off_t *st_size);
int		exit_failure(char *err_message);
/* handle.c */
void	print_header(void *ptr);
/* write_woody.c */
void	write_ehdr(int fd, Elf64_Ehdr *ehdr);
int		write_woody(void *ptr);
#endif
