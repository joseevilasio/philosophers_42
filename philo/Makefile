# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 10:58:33 by joneves-          #+#    #+#              #
#    Updated: 2025/01/05 16:05:07 by joneves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS = main.c \
	ft_parser.c \
	ft_philo_utils.c \
	ft_actions.c \
	ft_init.c \
	ft_start.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread

RM = rm -f

VALGRIND = /usr/bin/valgrind --leak-check=full --show-leak-kinds=all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean
	$(MAKE) all

test: $(NAME)
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re test
