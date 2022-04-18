/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:59:06 by yecsong           #+#    #+#             */
/*   Updated: 2022/04/18 18:32:45 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strchr(char	*arr, char c, size_t len);
int		ft_strlen(const char *s);
char	*split(char *storage, char *buff);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buff;
	char		*temp;

	buff = (char *)malloc(sizeof(char) * 30);
	if (!buff)
		return (NULL);
	while (ft_strchr(storage, '\n', 30));
	{
	}
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[ft_strlen(buff)] = '\0';
		if (ft_strchr(buff, '\n', BUFF_SIZE + 1))
		{
			return (split(storage, buff));
		}
		else
		{
			temp = ft_strjoin(storage, buff);
			if (storage)
				free(storage);
			storage = temp;
		}
	}
	return (NULL);
}

int	ft_strchr(char	*arr, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
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

char *split(char *storage, char *buff)
{
	char	*first;
	size_t	pos_new;

	pos_new = ft_strchr(buff, '\n', BUFF_SIZE);
	first = (char *)malloc(sizeof(char) * pos_new + 1);
	if (!first)
		return (NULL);
	ft_strlcpy(first, buff, pos_new + 1);
	ft_strlcpy(storage, buff + pos_new, BUFF_SIZE - pos_new + 1);
	return (first);
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
