#include "woody.h"

void	print_header(void *ptr)
{
	Elf64_Ehdr	*ehdr;
	Elf64_Phdr	*phdr;
	Elf64_Shdr	*shdr;
	int		i;

 	// PRINT ELF HEADER
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

	// PRINT PROGRAM HEADER
	i = 0;
	phdr = ptr + ehdr->e_phoff;
	while (++i <= ehdr->e_phnum)
	{
		if (i == 1) //For debug, delete it after
		{
			printf("\nProgram header\n");
			printf("p_type  : %u\n", phdr->p_type);
			printf("p_flags : %u\n", phdr->p_flags);
			printf("p_offset: %lu\n", phdr->p_offset);
			printf("p_vaddr : %lu\n", phdr->p_vaddr);
			printf("p_paddr : %lu\n", phdr->p_paddr);
			printf("p_filesz: %lu\n", phdr->p_filesz);
			printf("p_memsz : %lu\n", phdr->p_memsz);
			printf("p_align : %lu\n", phdr->p_align);
		}
		phdr = phdr + sizeof(Elf64_Phdr);
	}

	// PRINT SECTION HEADER
	i = 0;
	shdr = ptr + ehdr->e_shoff;
	while (++ i <= ehdr->e_shnum)
	{
		if (i == 1) //For debug, delete it after
		{
			printf("\nSection header\n");
			printf("sh_name     : %hu\n", shdr->sh_name);
			printf("sh_type     : %hu\n", shdr->sh_type);
			printf("sh_flags    : %lu\n", shdr->sh_flags);
			printf("sh_addr     : %lu\n", shdr->sh_addr);
			printf("sh_offset   : %lu\n", shdr->sh_offset);
			printf("sh_size     : %lu\n", shdr->sh_size);
			printf("sh_link     : %hu\n", shdr->sh_link);
			printf("sh_info     : %hu\n", shdr->sh_info);
			printf("sh_addralign: %lu\n", shdr->sh_addralign);
			printf("sh_entsize  : %lu\n", shdr->sh_entsize);
		}
		shdr = shdr + sizeof(Elf64_Shdr);
	}
}
