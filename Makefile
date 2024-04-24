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

BONUS =	checker_bonus/checker_bonus.c \
		checker_bonus/checker_utils_bonus.c \
		checker_bonus/push_bonus.c \
		checker_bonus/reverse_rotate_bonus.c \
		checker_bonus/rotate_bonus.c \
		checker_bonus/swap_bonus.c \
		parsing/sort_param.c \
		parsing/parse.c \
		parsing/check_arg.c \
		parsing/give_place.c

LIBFT = ./libft/libft.a
OBJ = ${SRC:.c=.o}
OBJ_B = ${BONUS:.c=.o}

NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -f
HEADER = push_swap.h
HEADER_BONUS = checker_bonus/checker_bonus.h

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(HEADER)
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft
	$(CC) -o $(NAME) $(OBJ) libft/libft.a

all: $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B) $(HEADER) $(HEADER_BONUS)
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft
	$(CC) -o $(NAME_BONUS) $(OBJ_B) libft/libft.a

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_B)
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)


re: fclean all

.PHONY: all clean fclean re bonus
