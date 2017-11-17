#ifndef WOODY_H
# define WOODY_H

# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <elf.h>

void	*get_ptr(char *file, off_t *st_size);
int		exit_failure(char *err_message);

#endif
