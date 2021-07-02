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

BNAME = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

IDIR = -I. -I./libft -I../libft -I.. -I.

LIB = -L./libft -lft

MSRC = pushmain.c

BSRC = checker_bonus.c

SUBSRCS = pushswap.c operations.c operations2.c pushswap2.c sorts.c radixsort.c

BONUSSUB = operations.c operations2.c get_next_line.c get_next_line_utils.c checker_tools.c checker_tools2.c

SUBOBJS = $(SUBSRCS:%.c=%.o)

SUBBOBJS = $(BONUSSUB:%.c=%.o)

all: $(NAME)

$(NAME): $(addprefix ./srcs/,$(SUBOBJS)) | ./libft/libft.a
	$(CC) $(FLAGS) $(IDIR) $(MSRC) -o $(NAME) $(addprefix ./srcs/,$(SUBOBJS)) $(LIB)

$(addprefix ./srcs/,$(SUBOBJS)):
	cd srcs && $(CC) $(FLAGS) $(IDIR) -c $(SUBSRCS)

./libft/libft.a: ./libft/libft.h
	cd libft && $(MAKE) bonus && $(MAKE)

bonus: $(addprefix ./srcs_bonus/,$(SUBBOBJS)) | ./libft/libft.a
	$(CC) $(FLAGS) $(IDIR) $(BSRC) -o $(BNAME) $(addprefix ./srcs_bonus/,$(SUBBOBJS)) $(LIB)

$(addprefix ./srcs_bonus/,$(SUBBOBJS)):
	cd srcs_bonus && $(CC) $(FLAGS) $(IDIR) -c $(BONUSSUB)

./libft/libft.a: ./libft/libft.h
	cd libft && $(MAKE) bonus && $(MAKE)

clean:
		/bin/rm -f *.o
		/bin/rm -f ./srcs/*.o ./srcs_bonus/*.o 
		cd libft && $(MAKE) clean

fclean: clean
		/bin/rm -f $(NAME) $(BNAME)
		cd libft && $(MAKE) fclean

re: fclean all $(BONUS) ./libft/libft.a
