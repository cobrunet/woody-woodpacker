#ifndef WOODY_H
# define WOODY_H

# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>

void	*get_ptr(char *file, off_t *st_size);

#endif
