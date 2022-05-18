/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:00:03 by yecsong           #+#    #+#             */
/*   Updated: 2022/05/18 14:19:28 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	if (0 > (fd1 = open("./test.txt", O_RDONLY)))
	{
		printf ("오류 발생\n");
		return (-1);
	}
	if (0 > (fd2 = open("./test2.txt", O_RDONLY)))
	{
		printf ("오류 발생\n");
		return (-1);
	}
	if (0 > (fd3 = open("./test3.txt", O_RDONLY)))
	{
		printf ("오류 발생\n");
		return (-1);
	}
	if (0 > (fd4 = open("./test4.txt", O_RDONLY)))
	{
		printf ("오류 발생\n");
		return (-1);
	}
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd4));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd4));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd4));
}
