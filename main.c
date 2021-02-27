/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nayache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 05:57:23 by nayache           #+#    #+#             */
/*   Updated: 2021/02/27 08:53:38 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

extern  ssize_t	ft_write(int fd, const void *buf, size_t count);
extern	size_t	ft_read(int fd, void *buf, size_t count);
extern	size_t	ft_strlen(const char *s);
extern	char	*ft_strcpy(char *dest, const char *src);
extern	int		ft_strcmp(const char *s1, const char *s2);
extern	char	*ft_strdup(const char *s);

void	test_strlen(void)
{	
	printf("real: %ld\n", strlen("bonjour"));	
	printf("mine: %ld\n", ft_strlen("bonjour"));
	printf("real: %ld\n", strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	printf("mine: %ld\n", ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	printf("real: %ld\n", strlen("lala\0lolo"));	
	printf("mine: %ld\n", ft_strlen("lala\0lolo"));
	printf("real: %ld\n", strlen(""));	
	printf("mine: %ld\n", ft_strlen(""));
}

void	test_strcpy(void)
{
	char *str;
	char *str2;

	str = malloc(100);
	str2 = malloc(100);
	printf("real: %s\n", strcpy(str, "bonjour"));
	printf("mine: %s\n", ft_strcpy(str2, "bonjour"));
	printf("real: %s\n", strcpy(str, "hi"));
	printf("mine: %s\n", ft_strcpy(str2, "hi"));
	printf("real: %s\n", strcpy(str, "salut\0cava"));
	printf("mine: %s\n", ft_strcpy(str2, "salut\0cava"));
	printf("real: %s\n", strcpy(str, ""));
	printf("mine: %s\n", ft_strcpy(str2, ""));
	free(str);
	free(str2);
}

void	test_strcmp(void)
{
	printf("real: %d\n", strcmp("bonjour", "bonjour"));
	printf("mine: %d\n", ft_strcmp("bonjour", "bonjour"));
	printf("real: %d\n", strcmp("hi", "hi"));
	printf("mine: %d\n", ft_strcmp("hi", "hi"));
	printf("real: %d\n", strcmp("bonjour", "hi"));
	printf("mine: %d\n", ft_strcmp("bonjour", "hi"));
	printf("real: %d\n", strcmp("hi", "bonjour"));
	printf("mine: %d\n", ft_strcmp("hi", "bonjour"));
	printf("real: %d\n", strcmp("", ""));
	printf("mine: %d\n", ft_strcmp("", ""));
	printf("real: %d\n", strcmp("bonjour", ""));
	printf("mine: %d\n", ft_strcmp("bonjour", ""));
	printf("real: %d\n", strcmp("", "bonjour"));
	printf("mine: %d\n", ft_strcmp("", "bonjour"));
}

void	test_strdup(void)
{
	char *s1;
	char *s2;
	printf("real: %s\n", strdup("bonjour"));
	printf("mine: %s\n", ft_strdup("bonjour"));
	printf("real: %s\n", strdup("hi"));
	printf("real: %s\n", ft_strdup("hi"));
	s1 = strdup("ma chaine s");
	s2 = ft_strdup("ma chaine s");
	printf("real: %s\n", s1);
	printf("mine: %s\n", s2);
	printf("real: %s\n", strdup(""));
	printf("mine: %s\n", ft_strdup(""));
	free(s1);
	free(s2);
}

void	test_write(void)
{
	int ret;
	int ret2;

	ret = ft_write(1, "salut\n", 6);
	printf("my return :   [%u] | my errno : [%d]\n", ret, errno);
	ret2 = write(1, "salut\n", 6);
	printf("return :      [%u] | errno :    [%d]\n", ret2, errno);
	ret = ft_write(1, "bonjour\n", 2);
	printf("\nmy return :   [%u] | my errno : [%d]\n", ret, errno);
	ret2 = write(1, "bonjour\n", 2);
	printf("\nreturn :      [%u] | errno :    [%d]\n", ret2, errno);
	ret = ft_write(1, "salut", 0);
	printf("\nmy return :   [%u] | my errno : [%d]\n", ret, errno);
	ret2 = write(1, "salut", 0);
	printf("\nreturn :      [%u] | errno :    [%d]\n", ret2, errno);
	ret = ft_write(42, "salut\n", 6);
	printf("\nmy return :   [%u] | my errno : [%d]\n", ret, errno);
	perror(strerror(errno));
	errno = 0;
	ret2 = write(42, "salut\n", 6);
	printf("\nreturn :      [%u] | errno :    [%d]\n", ret2, errno);
	perror(strerror(errno));
}

void	test_read(void)
{
	char	buf[551];
	char	buf2[551];
	int		ret;
	int		ret2;
	int		fd;

	fd = open("ft_strlen.s", O_RDONLY);
	ret = ft_read(fd, buf, 550);
	buf[ret] = '\0';
	printf("mine : ret = %d | buf : \n%s\n", ret, buf);
	close(fd);
	fd = open("ft_strlen.s", O_RDONLY);
	ret2 = read(fd, buf2, 550);
	buf2[ret2] = '\0';
	printf("real : ret = %d | buf : \n%s\n", ret2, buf2);
	close(fd);
	ret = ft_read(40, buf, 550);
	printf("mine : ret = %d | errno = %d\n", ret, errno);
	perror(strerror(errno));
	errno = 0;
	ret2 = read(40, buf, 550);
	printf("real : ret = %d | errno = %d\n", ret, errno);
	perror(strerror(errno));
}

int		main(void)
{
	printf("\n\n========== strlen test :\n\n");
	test_strlen();
	printf("\n\n========== strcpy test :\n\n");
	test_strcpy();
	printf("\n\n========== strcmp test :\n\n");
	test_strcmp();
	printf("\n\n========== strdup test :\n\n");
	test_strdup();
	printf("\n\n========== write test :\n\n");
	test_write();
	printf("\n\n========== read test :\n\n");
	test_read();
	return (0);
}
