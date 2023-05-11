#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <elf.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - code determines if a file is an ELF file in this code
 * @e_ident: pointer to an array in the code containing ELF
 * magic numbers
 * author: Brian .G
 * Description: If file not an ELF file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int mi;

	for (mi = 0; mi < 4; mi++)
	{
	if (e_ident[mi] != 127 &&
		e_ident[mi] != 'E' &&
	e_ident[mi] != 'L' &&
	e_ident[mi] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Is Not an ELF file\n");
		exit(98);
	}
	}
}

/**
 * print_magic - prints the magic number of an ELFheader in code below
 * @e_ident: pointer to an array which has the ELF MAGIC
 * numbers in code below
 * author: Brian .G
 * Description: magic numbers are separated by spaces in code below
 */
void print_magic(unsigned char *e_ident)
{
	int mi;

	printf(" Magic: ");
	for (mi = 0; mi < EI_NIDENT; mi++)
	{
		printf("%02x", e_ident[mi]);
		if (mi == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - this prints the class of an ELF header in the code below
 * @e_ident: pointer to an array which has the ELFclass in the code below
 * author: Brian .G
 */
void print_class(unsigned char *e_ident)
{
printf("class: ");
switch (e_ident[EI_CLASS])
{
	case ELFCLASSNONE:
		printf("invalid\n");
		break;
		case ELFCLASS32:
		printf("ELF32\n");
		break;
		case ELFCLASS64:
		printf("ELF64\n");
		break;
		default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_data - this func prints the data of an ELF header in the code below
 * @e_ident: pointer to an array which has the ELF class
 */
void print_data(unsigned char *e_ident)
{
	printf("Data: ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("invalid\n");
			break;
			case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
			case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
			default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints version of an ELF header in code below
 * @e_ident: pointer to ann array which has the ELF version in the code
 */
void print_version(unsigned char *e_ident)
{
	printf("Version:%d",
	e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * print_osabi - func prints OS/ABI of an ELF header in code below
 * @e_ident: this is a pointer coontaining the ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI:  ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
			case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
			case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
			case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
			case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
			default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}


/**
* print_abi - thIS function prints the ABI version of an ELF header.
* @e_ident: pointer containing the ELF ABI version IN THIS CODE
*author: Brian .G
*/
void print_abi(unsigned char *e_ident)
{
printf("  ABI Version: %d\n",
e_ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of an ELF header in this code
* @e_type: the ELF type.
* @e_ident: pointer array containing the ELF class in the code
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;
printf("  Type: ");
switch (e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}


/**
* print_entry - that function prints the entry point of an ELF
* header in the code below
* @e_entry: The address of the ELF entry point in the code below
* @e_ident: A pointer containing the ELF class.
*author: Brian .G
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("Entry point address: ");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}
/**
* close_elf - this function closes an ELF file in this code
* @elf: The file descriptor of the ELF file in the code below
*
* Description: If the file cannot be closed - exit code 98.
*Author:Brian .G
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", elf);
exit(98);
}
}
/**
* main - this func displays the information contained in the
* ELF header at the start of an ELF file in this code
* @argc: The number of arguments supplied to the program in this code
* @argv: pointers to the arguments in this code
* Return: 0 on success.
* Description: If not an ELF file or
* the function fails - exit code 98.
*author: Brian . G
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *elf_header;
int el, f;
el = open(argv[1], O_RDONLY);
if (el == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
elf_header = malloc(sizeof(Elf64_Ehdr));
if (elf_header == NULL)
{
close_elf(el);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
f = read(el, elf_header, sizeof(Elf64_Ehdr));
if (f == -1)
{
free(elf_header);
close_elf(el);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
check_elf(elf_header->e_ident);
printf("ELF Header:\n");
print_magic(elf_header->e_ident);
print_class(elf_header->e_ident);
print_data(elf_header->e_ident);
print_version(elf_header->e_ident);
print_osabi(elf_header->e_ident);
print_abi(elf_header->e_ident);
print_type(elf_header->e_type, elf_header->e_ident);
print_entry(elf_header->e_entry, elf_header->e_ident);
free(elf_header);
close_elf(el);
return (0);
}


