#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

typedef uint32_t vaddr_t;
typedef struct {
	char name[256];
	vaddr_t start;
	vaddr_t end;
}elf_func_symbol;

elf_func_symbol func_symbol[128];


#define GET_BYTE(dest, base, size)  uint32_t dest = 0;for (int i = base + size - 1; i >= base; --i){\
		dest = dest * 256 + elf[i];\
	}

int main(){
	//load and store to buf
	char *elf_file  = "recursion-riscv32-nemu.elf";
	FILE *fp = fopen(elf_file, "rb");
	if(fp == NULL){
		printf("open failure\n");
		return 1;
	}
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	printf("The size of %s is %ld Byte.\n", elf_file, file_size);
	fseek(fp, 0, SEEK_SET);
	uint8_t *elf = malloc(file_size * sizeof(uint8_t));
	size_t ret = fread(elf, 1, file_size, fp);
	fclose(fp);
	if (ret != file_size){
		fprintf(stdout, "fread() failed: %zu\n", ret);
		exit(EXIT_FAILURE);
	}

	
	//parse
	GET_BYTE(shoff, 32, 4);
	GET_BYTE(shentsize, 46, 2);
	GET_BYTE(shnum, 48, 2);
	GET_BYTE(shstrndx, 50, 2);

	//printf("shoff = %#8x\n", shoff);
	//printf("shentsize = %#8x\n", shentsize);
	//printf("shnum = %#8x\n", shnum);
	//printf("shstrndx = %#8x\n", shstrndx);
	
	uint32_t sh9 = shoff + shstrndx * shentsize;
	GET_BYTE(shstroff, sh9 + 16, 4);

	//printf("shstroff = %#8x\n", shstroff);
	

	char *sh_name;
	int sh_symndx = -1;
	int sh_strndx = -1;
	uint32_t base_off = 0;
	//遍历section headers,找到strtab location and symtab
	for (int i = 0; i < shnum; ++ i){
		base_off = shoff + i * shentsize;
		GET_BYTE(sh_nameoff, base_off, 4);
		sh_nameoff += shstroff;
		sh_name = (char *)&elf[sh_nameoff];
		if (0 == strcmp(sh_name, ".symtab")){
			sh_symndx = i;
		}else if (0 == strcmp(sh_name, ".strtab")){
			sh_strndx = i;
		}
	}
	//printf("The num of symtab is %d\n", sh_symndx);
	//printf("The num of strtab is %d\n", sh_strndx);
	
	//get the offset of the symtab, strtab
	base_off = shoff + sh_symndx * shentsize;
	GET_BYTE(symtab_off, base_off + 16, 4);
	GET_BYTE(size_symtab, base_off + 20, 4);
	int len_symtab = size_symtab / 16;
	base_off = shoff + sh_strndx * shentsize;
	GET_BYTE(strtab_off, base_off + 16, 4);

	//printf("symtab_off = %#x\n", symtab_off);
	//printf("strtab_off = %#x\n", strtab_off);

	//append the function element
	//traverse the symtab
	char *sym_name;
	printf("len_symtab = %d\n", len_symtab);
	int symbol_index = 0;
	for (int i = 0; i < len_symtab; ++ i){
		base_off = symtab_off + 16 * i;
		GET_BYTE(sym_type, base_off + 12, 1);
		sym_type = sym_type & 0xf;
		if (sym_type == 2){
			GET_BYTE(sym_name_off, base_off, 4);
			sym_name_off += strtab_off;
			sym_name = (char *)&elf[sym_name_off];
			strcpy(func_symbol[symbol_index].name ,sym_name);

			GET_BYTE(func_start, base_off + 4, 4);
			func_symbol[symbol_index].start = func_start;

			GET_BYTE(func_end, base_off + 8, 4);
			func_end += func_start;
			func_symbol[symbol_index ++].end = func_end;
		}
	}
	for (int i = 0; i < symbol_index; i ++){
		printf("func: %-10s   %#8x --> %#8x\n", func_symbol[i].name, func_symbol[i].start, func_symbol[i].end);  
	}
	return 0;
}
