/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:00:29 by yecsong           #+#    #+#             */
/*   Updated: 2022/05/13 15:22:08 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*store;
	struct s_list	*next;
}	t_list;

char	*read_line(int fd, char *store, int *end);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1, int size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strchr(const char *s, int *end);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
void	free_node(int fd, int is_free, t_list **list);
t_list	*get_node(int fd, t_list **list);

#endif
