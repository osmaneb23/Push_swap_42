# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 06:37:35 by obouayed          #+#    #+#              #
#    Updated: 2024/06/08 06:37:35 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du projet et archive
NAME = checker
ARCHIVE = ../push_swap.a

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources et objets
SRC = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c	
OBJS = $(SRC:.c=.o)

# Commandes
RM = rm -f

# Règles principales
all: $(NAME)

$(NAME): $(OBJS) $(ARCHIVE)
	$(CC) $^ -o $(NAME)
	mv $(NAME) ..

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ARCHIVE):
	cd .. && make archive

# Nettoyage
clean:
	$(RM) $(OBJS)
	cd .. && rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)
	cd .. && rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re