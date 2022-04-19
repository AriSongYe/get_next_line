/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:26:53 by yecsong           #+#    #+#             */
/*   Updated: 2022/04/19 19:56:14 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>


int main()
{
	int	fd;
	if((fd = open("test.txt", O_RDONLY)) < 0)
	{
		printf("open error!!\n");
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
