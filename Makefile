# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 15:31:05 by yecsong           #+#    #+#              #
#    Updated: 2022/05/13 15:39:20 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := get_next_line.o

SRCS := get_next_line.c\
		get_next_line_utils.c\
		main.c\

SRCS_BONUS := get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		bonus_main.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

m : (OBJS)
	$(CC) $(CFLAGS) $@ $?

b : (OBJS_BONUS)
	$(CC) $(CFLAGS) $@ $?

CFLAGS := -Werror -Wextra -Wall

clean :
	rm -f *.o

fclean : clean 
	rm -f $(NAME)
