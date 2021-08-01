/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

size_t		ft_strlen(const	char *str);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strdup(const char *s1);
size_t		ft_write(int fd, char *str, size_t count);
size_t		ft_read(int fd, char *str, size_t count);

void		testers1(void)
{
	char	frase1[100];
	char	frase2[100];

	printf("_____________________TESTE FT_STRLEN__________________\n\n");
	printf("input: \"\"\n");
	printf("STRLEN    Retorno: %zu\n", strlen(""));
	printf("FT_STRLEN Retorno: %zu\n\n", ft_strlen(""));
	printf("input: \"a very very very very very very ");
	printf("very very very long string\"\n");
	printf("STRLEN    Retorno: %zu\n",
	strlen("a very very very very very very very very very long string"));
	printf("FT_STRLEN Retorno: %zu\n",
	ft_strlen("a very very very very very very very very very long string"));
	printf("_____________________TESTE FT_STRCPY__________________\n\n");
	printf("input: \"\"\n");
	printf("STRCPY    Retorno: %s\n", strcpy(frase1, ""));
	printf("FT_STRCPY Retorno: %s\n\n", ft_strcpy(frase2, ""));
	printf("input: \"a very very very very very very very long string\"\n");
	printf("STRCPY    Retorno: %s\n",
	strcpy(frase1, "a very very very very very very very long string"));
	printf("FT_STRCPY Retorno: %s\n",
	ft_strcpy(frase2, "a very very very very very very very long string"));
}

void		testers2(void)
{
	printf("_____________________TESTE FT_STRCMP_________________\n\n");
	printf("STRCMP       str1: \"\"  str2: \"\" Retorno: %d\n", strcmp("", ""));
	printf("FT_STRCMP    str1: \"\"  str2: \"\" Retorno: %d\n\n",
			ft_strcmp("", ""));
	printf("STRCMP       str1: \"a\"  str2: \"\" Retorno: %d\n",
	strcmp("a", ""));
	printf("FT_STRCMP    str1: \"a\"  str2: \"\" Retorno: %d\n\n",
			ft_strcmp("a", ""));
	printf("STRCMP       str1: \"\"  str2: \"a\" Retorno: %d\n",
	strcmp("", "a"));
	printf("FT_STRCMP    str1: \"\"  str2: \"a\" Retorno: %d\n\n",
			ft_strcmp("", "a"));
	printf("STRCMP       str1: \"abc\"  str2: \"abc\" Retorno: %d\n",
			strcmp("abc", "abc"));
	printf("FT_STRCMP    str1: \"abc\"  str2: \"abc\" Retorno: %d\n\n",
			ft_strcmp("abc", "abc"));
	printf("STRCMP       str1: \"abd\"  str2: \"abc\" Retorno: %d\n",
			strcmp("abd", "abc"));
	printf("FT_STRCMP    str1: \"abd\"  str2: \"abc\" Retorno: %d\n\n",
			ft_strcmp("abd", "abc"));
	printf("STRCMP       str1: \"aba\"  str2: \"abz\" Retorno: %d\n",
			strcmp("aba", "abz"));
	printf("FT_STRCMP    str1: \"aba\"  str2: \"abz\" Retorno: %d\n\n",
			ft_strcmp("aba", "abz"));
}

void		testers3(void)
{
	char	*ret;

	printf("_____________________TESTE FT_STRDUP_____________________\n\n");
	ret = ft_strdup("");
	printf("input: \"\"\n");
	printf("Retorno: %s\n\n", ret);
	free(ret);
	ret = ft_strdup("São Paulo");
	printf("input: \"São Paulo\"\n");
	printf("Retorno: %s\n\n", ret);
	free(ret);
	printf("input: \"a very very very very very very very long string\"\n");
	ret = ft_strdup("a very very very very very very very long string\n");
	printf("Retorno: %s\n\n", ret);
	free(ret);
}

void		testers4(void)
{
	int		num;
	int		fds;

	fds = open("write.txt", O_WRONLY);
	printf("_____________________TESTE FT_WRITE_____________________\n\n");
	(num = (ft_write(1, "Manaus\n", 7)));
	printf("input: \"Manaus\"\n");
	printf("Retorno: %d\n", num);
	printf("errno: %d\n\n", errno);
	printf("teste open file: write.txt\n");
	(num = (ft_write(fds, "Brasilia\n", 9)));
	printf("input: \"Brasilia\"\n");
	printf("Retorno: %d\n", num);
	printf("errno: %d\n\n", errno);
	printf("teste errno: fd=50\n");
	(num = (ft_write(50, "Maranhão\n", 9)));
	printf("input: \"Maranhão\"\n");
	printf("Retorno: %d\n", num);
	printf("errno: %d\n\n", errno);
	errno = 0;
}

int			main(void)
{
	int		fd;
	char	ptr[100];
	char	ptr2[100];
	char	ptr3[100];
	int		num;

	testers1();
	testers2();
	testers3();
	testers4();
	printf("_____________________TESTE FT_READ_____________________\n\n");
	(num = (ft_read(0, ptr, 100)));
	printf("Retorno Num: %d\n", num);
	printf("errno: %d\n\n", errno);
	fd = open("read.txt", O_RDONLY);
	(num = (ft_read(fd, ptr2, 100)));
	printf("open file: read.txt\n");
	printf("Retorno String: %sRetorno Num: %d\n", ptr2, num);
	printf("errno: %d\n\n", errno);
	(num = (ft_read(-1, ptr3, 100)));
	printf("teste erro: fd=-1\n");
	printf("Retorno Num: %d\n", num);
	printf("errno: %d\n\n", errno);
	return (0);
}
