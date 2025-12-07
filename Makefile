# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 00:00:00 by mzapora          #+#    #+#              #
#    Updated: 2025/12/06 23:50:00 by mzapora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== VARIABLES ===== #
NAME			=	philo
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -pthread
CFLAGS_DEBUG	=	-Wall -Wextra -Werror -pthread -g3 -O0

# ===== SOURCES & OBJECTS ===== #
SRCS			=	main.c \
					parsing.c \
					utils.c

OBJS			=	$(SRCS:.c=.o)

# ===== RULES ===== #
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "✓ $(NAME) compiled successfully!"

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "✓ Object files removed!"

fclean: clean
	rm -f $(NAME)
	@echo "✓ Executable removed!"

re: fclean all

debug: CFLAGS = $(CFLAGS_DEBUG)
debug: re

.PHONY: all clean fclean re debug
