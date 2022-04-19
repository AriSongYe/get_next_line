/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:59:06 by yecsong           #+#    #+#             */
/*   Updated: 2022/04/19 21:09:26 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strchr(char	*arr, char c, size_t len);
int		ft_strlen(const char *s);
char	*split(char *buff, int order);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd)
{
	static char	*store;
	char		*buff;
	char		*temp;

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	buff[BUFF_SIZE] = '\0';
	store = (char *)malloc(sizeof(char) * 1024);

	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (ft_strchr(buff, '\n', BUFF_SIZE + 1))
		{
			temp = ft_strjoin(store, split(buff, 0));
			store = split(buff, 1);
			free(buff);
			return (temp);
		}
		else
		{
			store = ft_strjoin(store, buff);
			free(buff);
		}
	}
	return (NULL);
}

char	*split(char *buff, int order)
{
	char	*arr;
	int		location;
	if (order == 0)
	{
		location = ft_strchr(buff, '\n', BUFF_SIZE + 1);
		arr = (char *)malloc(sizeof(char) * location + 1);
		ft_strlcpy(arr, buff, location + 1);
		return (arr);
	}
	else
	{
		location = ft_strchr(buff, '\n', BUFF_SIZE + 1);
		arr = (char *)malloc(sizeof(char) * BUFF_SIZE - location);
		ft_strlcpy(arr, buff + location, BUFF_SIZE - location);
		return (arr);
	}
}
int	ft_strchr(char	*arr, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && arr[i])
	{
		if (arr[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (src == NULL)
		return (0);
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) *(s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s2_len + s1_len + 1);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	else
	{
		while (src[i] != '\0' && i + dst_len < dstsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + src_len);
	}
}
