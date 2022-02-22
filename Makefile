# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 18:43:24 by abadidi           #+#    #+#              #
#    Updated: 2022/02/22 21:59:41 by abadidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

SRCS = ft_check.c ft_sort_bis.c ft_utils_bis.c ft_operations.c ft_sort_quater.c \
		ft_operations_bis.c ft_sort_tiers.c ft_print.c ft_tools.c ft_sort.c ft_utils.c

SRC2 = checker_checker.c   checks_checker.c  operations_checker.c  operations_bis_checker.c utils_checker.c ft_utils.c 

FLAGS = -Wall -Wextra -Werror -c

OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRC2:.c=.o)

INC = push_swap.h

CC = gcc

all: $(NAME)
bonus: $(NAME2)

$(NAME): $(SRCS) $(INC)
	@$(CC) $(FLAGS) $(SRCS)
	@$(CC) $(OBJS) -o $(NAME)

$(NAME2): $(SRC2) $(INC)
	@$(CC) $(FLAGS) $(SRC2)
	@$(CC) $(OBJS2) -o $(NAME2)

clean:
	rm -rf $(OBJS) $(OBJS2)

fclean: clean
	rm -rf $(NAME)  $(NAME2)

re: fclean all 