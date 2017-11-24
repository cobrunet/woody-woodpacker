#include "woody.h"

void	print_header(void *ptr)
{
	//struct Elf64_Ehdr	*hdr;

	//hdr = ptr;
	printf("ELF header\n");
	printf("e_type     : %hu\n", ((Elf64_Ehdr*)ptr)->e_type);
	printf("e_machine  : %hu\n", ((Elf64_Ehdr*)ptr)->e_machine);
	printf("e_version  : %u\n", ((Elf64_Ehdr*)ptr)->e_version);
	printf("e_entry    : %lu\n", ((Elf64_Ehdr*)ptr)->e_entry);
	printf("e_phoff    : %lu\n", ((Elf64_Ehdr*)ptr)->e_phoff);
	printf("e_shoff    : %lu\n", ((Elf64_Ehdr*)ptr)->e_shoff);
	printf("e_flags    : %u\n", ((Elf64_Ehdr*)ptr)->e_flags);
	printf("e_ehsize   : %hu\n", ((Elf64_Ehdr*)ptr)->e_ehsize);
	printf("e_phentsize: %hu\n", ((Elf64_Ehdr*)ptr)->e_phentsize);
	printf("e_phnum    : %hu\n", ((Elf64_Ehdr*)ptr)->e_phnum);
	printf("e_shentsize: %hu\n", ((Elf64_Ehdr*)ptr)->e_shentsize);
	printf("e_shnum    : %hu\n", ((Elf64_Ehdr*)ptr)->e_shnum);
	printf("e_shstrndx : %hu\n", ((Elf64_Ehdr*)ptr)->e_shstrndx);

	printf("\nProgram header\n");
	printf("p_type  : %u\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_type);
	printf("p_offset: %lu\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_offset);
	printf("p_vaddr : %lu\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_vaddr);
	printf("p_paddr : %lu\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_paddr);
	printf("p_filesz: %lu\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_filesz);
	printf("p_memsz : %lu\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_memsz);
	printf("p_flags : %u\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_flags);
	printf("p_align : %lu\n", ((Elf64_Phdr*)ptr + sizeof(Elf64_Ehdr))->p_align);
}
