/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:15:59 by yecsong           #+#    #+#             */
/*   Updated: 2022/05/18 13:28:47 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *store, int *end);
char	*ft_strjoin(char *s1, char *s2);
void	free_node(int fd, int is_free, t_list **list);
t_list	*get_node(int fd, t_list **list);

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*node;
	char			*line;
	char			*temp;
	int				end;

	end = 0;
	node = get_node(fd, &list);
	if (!node)
		return (NULL);
	temp = read_line(fd, node->store, &end);
	if (!temp || end == 0)
	{
		free(temp);
		free_node(fd, 1, &list);
		return (NULL);
	}
	line = ft_strdup(temp, end);
	node->store = ft_strdup(temp + end, ft_strlen (temp + end));
	free(temp);
	free_node(1, line == NULL, &list);
	return (line);
}

t_list	*get_node(int fd, t_list **list)
{
	t_list	*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			break ;
		node = node->next;
	}
	if (!node)
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return (NULL);
		node->fd = fd;
		node->store = NULL;
		node->next = *list;
		*list = node;
	}
	return (node);
}

void	free_node(int fd, int is_free, t_list **list)
{
	t_list	*node;
	t_list	*last;

	if (!is_free)
		return ;
	if ((*list)->fd == fd)
	{
		last = (*list)->next;
		free(*list);
		*list = last;
		return ;
	}
	node = *list;
	while (node)
	{
		if (node->fd == fd)
			break ;
		last = node;
		node = node->next;
	}
	last->next = node->next;
	free(node);
}

char	*read_line(int fd, char *store, int *end)
{
	char	*buff;
	int		n;

	if (store && ft_strchr(store, end))
		return (store);
	if (store)
		*end = ft_strlen(store);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0 || n == -1)
			break ;
		buff[n] = '\0';
		store = ft_strjoin(store, buff);
		if (!store || ft_strchr(store, end))
			break ;
		*end += n;
	}
	free(buff);
	return (store);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) *(s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcpy(ptr + s1_len, s2, s2_len + 1);
	free(s1);
	return (ptr);
}
