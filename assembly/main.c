#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int 	ft_strlen(char *str);
int 			ft_tolower(int c);
void			*ft_memcpy(void *dest, void *src, unsigned int size);
char 			*ft_strchr(char *str, char c);
void			ft_bzero(void *ptr, unsigned int nbr);
void			ft_memset(void *ptr, int value, unsigned int nbr);
int				ft_strcmp(char *s, char *s2);
long 			ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_strdup(char *str);
char			*ft_strstr(char *string, char *substring);
void			*ft_memalloc(size_t size);
void			ft_print_memory(void *addr, size_t size);
char 			*ft_strcat(char *dest, char *src);


int		sys_write(int fd, char *str, int len);
int		sys_read(int fd, char *buf, int len);
int 	sys_open(char *path, int flags);
int		sys_close(int fd);

void	print_memory2(void *addr, int size)
{
	asm(".intel_syntax noprefix;push rbp;mov r9, rdi;mov r10, rsi;print:xor r8, r8;printhex:movzx r11, BYTE ptr[r9 + r8];\
mov r12, r11;shr r11, 4;and r12, 0xF;and r11, 0xF;cmp r11, 10;jae alpha_1;add r11, 48;jmp printhexchar_1;\
alpha_1:add r11, 87;printhexchar_1:push r11;mov rax, 33554436;mov rdi, 1;mov rsi, rsp;mov rdx, 1;\
SYSCALL;pop r11;cmp r12, 10;jae alpha_2;add r12, 48;jmp printhexchar_2;alpha_2:add r12, 87;\
printhexchar_2:push r12;mov rax, 33554436;mov rdi, 1;mov rsi, rsp;mov rdx, 1;SYSCALL;pop r12;\
inc r8;test r8, 1;jnz loopback;push 32;mov rax, 33554436;mov rdi, 1;mov rsi, rsp;mov rdx, 1;\
SYSCALL;pop rdi;loopback:cmp r8, 16;jl printhex;push 32;mov rax, 33554436;mov rdi, 1;mov rsi, rsp;\
mov rdx, 1;SYSCALL;pop rdi;xor r8, r8;charloop:movsx r11, BYTE ptr[r9 + r8];mov rdi, 46;cmp r11, 32;\
jl printchar;cmp r11, 127;jg printchar;movsx rdi, BYTE ptr[r9 + r8];printchar:push rdi;mov rax, 33554436;\
mov rdi, 1;mov rsi, rsp;mov rdx, 1;SYSCALL;pop rdi;inc r8;cmp r8, 16;jne charloop;newline:push 10;\
mov rax, 33554436;mov rdi, 1;mov rsi, rsp;mov rdx, 1;SYSCALL;pop rdi;cmp r10, 16;jl end;sub r10, 16;\
add r9, 16;jmp print;end:pop rbp;");
}

void 	pb(int data)
{
	for(int i = 0; i < 16; i++)
	{
		ft_putchar(".#"[data & 1]);
		data >>=1;
		if (i % 4 == 3)
			ft_putchar('\n');
	}
}

int 	shift_2d(int data, int x, int y)
{
	data = (x >= 0) ? ((data >> x) & (0xF >> x)) | ((data >> x) \
	& 0xF0 & (0xF0 >> x)) | ((data >> x) & 0xF00 & (0xF00 >> x)) \
	| ((data >> x) & 0xF000) : ((data << -x) & 0xF) | ((data << -x) \
	& 0xF0 & (0xF0 << -x)) | ((data << -x) & 0xF00 & (0xF00 << -x)) \
	| ((data << -x) & (0xF000 << -x));
	data = ((y >= 0) ? (data >> (y << 2)) : (data << (-y << 2)));
	return (data);
}

void 	shift2(void)
{
	asm(".intel_syntax; 	\
			mov rax, rax; 	\
		");
}

int	ft_read_file(char *str);

static void	print_hex_char(unsigned char c)
{
	const char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

static void	print_hex_line(unsigned char *curr, unsigned char *end)
{
	unsigned int i;

	i = 0;
	while (i < 16)
	{
		if (curr + i < end)
			print_hex_char(curr[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void		*ft_print_memory2(void *addr, unsigned int size)
{
	unsigned char	*curr;
	unsigned char	*end;
	unsigned int	i;

	curr = (unsigned char*)addr;
	end = curr + size;
	while (curr < end)
	{
		print_hex_line(curr, end);
		i = 0;
		while (i < 16 && curr + i < end)
		{
			if (curr[i] < 32 || curr[i] > 127)
				ft_putchar('.');
			else
				ft_putchar(curr[i]);
			i++;
		}
		ft_putchar('\n');
		curr += 16;
	}
	return (addr);
}

int main(int ac, char **av)
{
	/*int data = 0xF000;
	int x = 0, y = 3;

	pb(data);
	ft_putchar('\n');
	pb(shift_2d(data, x, y));
	ft_putchar('\n');
	data = ((int (*)(int, int, int))&shift2)(data, x, y);
	pb(data);*/
	int mallocsize;

	char *s = ft_memalloc(600);
	ft_memset(s + 1, 0xFF, 500);
		ft_strcat(s, ".intel_syntax; MOV RAX, 0x2000004; SYSCALL;");
	for(int i = 0; i < 10000000; i++)
	{
		s[16] = 0;
		ft_strcat(s, ".intel_syntax; MOV RAX, 0x2000004; SYSCALL;");
	}
	ft_print_memory(s, 360);
	//print_memory2(s, 200);
	//printf("%p\n", "This is a test string");
	//printf("%s\n", ft_strstr("This is a test string", "test"));
	/*int fd;
	char buf[256];
	int ret;
			

	fd = sys_open("main.c", O_RDWR);
	while ((ret = sys_read(fd, buf, 256)))
		sys_write(1, buf, ret);
	sys_close(fd);
	//printf("%ld\n", ft_atoi("   -21474836499999999"));
	char *s = "This is a test string.asdsads42.";
	char *s2 = malloc(128);
	s2[0] = 0;
	ft_memcpy(s2, s, ft_strlen(s) + 1);
	printf("%s\n", s2);*/
	/*for(int i = 0; i < 200000000; i++)
		ft_strcmp("THIS IS a !test STRING", "THIS IS a !test STRING");
	char *str = strdup("THIS IS a !test STRING");
	ft_memset(str + 5, 'a', 5);
	printf("[%d]\n", str[0]);
	printf("[%d]\n", str[1]);
	printf("%s\n", str);
	char *str2 = ft_strchr(str, '!');
	printf("%s\n", str2);
	char *str3 = ft_strchr(str, 'x');
	printf("%s\n", str3);*/
	/*char *str = strdup("THIS IS a test STRING");

	for (int i = 0; str[i]; i++)
		str[i] = ft_tolower(str[i]);
	printf("%s\n",  str);


	char *str;

	if (ac == 1)
		str = "This is a test string";
	else
		str = av[1];
	printf("Len is (%u), true len is (%lu)\n", ft_strlen(str), strlen(str));

	printf("--Benchmark--\n");
	for(unsigned long long i = 0; i < 100000000; i++)
		ft_strlen(str);*/
	return (0);
}