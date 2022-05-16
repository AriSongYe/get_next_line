# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 15:31:05 by yecsong           #+#    #+#              #
#    Updated: 2022/05/13 15:59:14 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./a.out

SRCS := get_next_line.c\
		get_next_line_utils.c\
		main.c\

SRCS_BONUS := get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		bonus_main.c

m : $(SRCS)
	$(CC) $(CFLAGS) BUFFER_SIZE=$(BUFF) $?

b : $(SRCS_BONUS)
	$(CC) $(CFLAGS) BUFFER_SIZE=$(BUFF) $?

CFLAGS := -Werror -Wextra -Wall -D

clean :
	rm -f *.o

fclean : clean 
	rm -f $(NAME)

PONNY: clean fclean b m
