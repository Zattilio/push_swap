# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:24:20 by jlanza            #+#    #+#              #
#    Updated: 2024/04/24 16:37:53 by jlanza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		parsing/sort_param.c \
		parsing/parse.c \
		parsing/check_arg.c \
		parsing/give_place.c \
		ft_pile/ft_s.c \
		ft_pile/ft_p.c \
		ft_pile/ft_r.c \
		ft_pile/ft_rr.c \
		sort/sort_pile.c \
		sort/sort_cost.c \
		sort/calcul_rx.c \
		sort/calcul_node_cost.c \
		sort/sort_size_2_3.c \
		sort/sort_size_4_5.c \
		sort/insert_pile.c \
		sort/smaller_on_top.c \
		sort/divide_a.c

BONUS =	checker_src/checker.c \
		checker_src/checker_utils.c \
		checker_src/push.c \
		checker_src/reverse_rotate.c \
		checker_src/rotate.c \
		checker_src/swap.c \
		parsing/sort_param.c \
		parsing/parse.c \
		parsing/check_arg.c \
		parsing/give_place.c

LIBFT = ./libft/libft.a
OBJ = ${SRC:.c=.o}
OBJ_B = ${BONUS:.c=.o}

NAME = push_swap
CHECKER = checker
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
HEADER = push_swap.h
HEADER = checker_src/checker.h

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME) $(CHECKER)

$(NAME): $(OBJ) $(HEADER)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(OBJ) libft/libft.a

$(CHECKER): $(OBJ_B) $(HEADER) $(HEADER)
	$(MAKE) -C ./libft
	$(CC) -o $(CHECKER) $(OBJ_B) libft/libft.a
	chmod +x ./test.sh

clean:
	$(RM) $(OBJ) $(OBJ_B)
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME) $(CHECKER)


re: fclean all

.PHONY: all clean fclean re checker
