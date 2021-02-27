# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 05:14:38 by nayache           #+#    #+#              #
#    Updated: 2021/02/27 08:52:47 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC_S = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

FLAGS = -Wall -Werror -Wextra

OBJS = 		$(SRC_S:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs -s $(NAME) $(OBJS)

%.o : %.s
			nasm -f elf64 $<

test:		$(NAME)
		clang -fno-builtin main.c $(OBJS) -o test
			
clean:	
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	clean fclean re
