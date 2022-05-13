/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:26:53 by yecsong           #+#    #+#             */
/*   Updated: 2022/05/13 15:27:52 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>


int main()
{
	int	fd1;
	int fd2;
	int fd3;
	if((fd = open("test.txt", O_RDONLY)) < 0)
	{
		printf("open error!!\n");
	}
	if((fd2 = open("test2.txt", O_RDONLY)) < 0)
	{
		printf("open error!!\n");
	}
	if((fd3 = open("123123123", O_RDONLY)) < 0)
	{
		printf("open error!!\n");
	}
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
}
