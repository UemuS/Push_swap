# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yihssan <yihssan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:02:15 by yihssan           #+#    #+#              #
#    Updated: 2021/06/22 13:32:24 by yihssan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

IDIR = -I. -I./libft -I../libft -I.. -I.

LIB = -L./libft -lft

MSRC = pushmain.c

SUBSRCS = pushswap.c operations.c

SUBOBJS = $(SUBSRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(addprefix ./srcs/,$(SUBOBJS)) | ./libft/libft.a
	$(CC) $(FLAGS) $(IDIR) $(MSRC) -o $(NAME) $(addprefix ./srcs/,$(SUBOBJS)) $(LIB)

$(addprefix ./srcs/,$(SUBOBJS)):
	cd srcs && $(CC) $(FLAGS) $(IDIR) -c $(SUBSRCS)

./libft/libft.a: ./libft/libft.h
	cd libft && $(MAKE) bonus && $(MAKE)

bonus:

clean:
		/bin/rm -f *.o
		/bin/rm -f ./srcs/*.o
		cd libft && $(MAKE) clean

fclean: clean
		/bin/rm -f $(NAME)
		cd libft && $(MAKE) fclean

re: fclean all ./libft/libft.a
