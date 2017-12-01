#include "woody.h"

void	print_header(void *ptr)
{
	Elf64_Ehdr	*ehdr;
	Elf64_Phdr	*phdr;
	int		i;
       
	ehdr = ptr;
	printf("ELF header\n");
	printf("e_type     : %hu\n", ehdr->e_type);
	printf("e_machine  : %hu\n", ehdr->e_machine);
	printf("e_version  : %u\n", ehdr->e_version);
	printf("e_entry    : %lu\n", ehdr->e_entry);
	printf("e_phoff    : %lu\n", ehdr->e_phoff);
	printf("e_shoff    : %lu\n", ehdr->e_shoff);
	printf("e_flags    : %u\n", ehdr->e_flags);
	printf("e_ehsize   : %hu\n", ehdr->e_ehsize);
	printf("e_phentsize: %hu\n", ehdr->e_phentsize);
	printf("e_phnum    : %hu\n", ehdr->e_phnum);
	printf("e_shentsize: %hu\n", ehdr->e_shentsize);
	printf("e_shnum    : %hu\n", ehdr->e_shnum);
	printf("e_shstrndx : %hu\n", ehdr->e_shstrndx);

	i = 0;
	phdr = ptr + sizeof(Elf64_Ehdr);
	while (++i <= ehdr->e_phnum)
	{
		printf("\nProgram header\n");
		printf("p_type  : %u\n", phdr->p_type);
		printf("p_offset: %lu\n", phdr->p_offset);
		printf("p_vaddr : %lu\n", phdr->p_vaddr);
		printf("p_paddr : %lu\n", phdr->p_paddr);
		printf("p_filesz: %lu\n", phdr->p_filesz);
		printf("p_memsz : %lu\n", phdr->p_memsz);
		printf("p_flags : %u\n", phdr->p_flags);
		printf("p_align : %lu\n", phdr->p_align);
		phdr = phdr + sizeof(Elf64_Phdr);
	}
}
