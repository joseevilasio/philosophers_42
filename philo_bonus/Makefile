# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 10:58:33 by joneves-          #+#    #+#              #
#    Updated: 2025/01/14 21:19:49 by joneves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo_bonus

SRCS = main_bonus.c \
	ft_parser_bonus.c \
	ft_philo_utils_bonus.c \
	ft_actions_bonus.c \
	ft_actions_utils_bonus.c \
	ft_init_bonus.c \
	ft_free_bonus.c \
	ft_start_dinner_bonus.c \
	ft_monitoring_bonus.c 

OBJS = $(SRCS:.c=.o)

CC = cc
#CFLAGS = -Wall -Werror -Wextra -g
#CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

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

.PHONY: all clean fclean re
