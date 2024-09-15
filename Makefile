# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 20:32:19 by obouayed          #+#    #+#              #
#    Updated: 2024/06/08 21:15:55 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du projet et archive
NAME = push_swap
ARCHIVE = push_swap.a

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs

# Fichiers sources et objets
SRC = costs.c error.c initialisation.c main.c operations.c operations2.c operations3.c rotates.c sort.c targets.c utils_index.c utils_nodes.c utils.c split.c split_utils.c free.c
SRC_NO_MAIN = costs.c error.c initialisation.c operations.c operations2.c operations3.c rotates.c sort.c targets.c utils_index.c utils_nodes.c utils.c split.c split_utils.c free.c

SRC_DIR = src

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
OBJS_NO_MAIN = $(addprefix $(SRC_DIR)/, $(SRC_NO_MAIN:.c=.o))

# Commandes
RM = rm -f

# Règles principales
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

archive: $(OBJS_NO_MAIN)
	$(LIB) $(ARCHIVE) $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus:
	cd checker_bonus && make
	
# Nettoyage
clean:
	$(RM) $(OBJS) $(ARCHIVE)
	cd $(SRC_DIR) && $(RM) *.o*
	cd checker_bonus && make clean

fclean: clean
	$(RM) $(NAME)
	cd checker_bonus && make fclean

re: fclean all

.PHONY: all clean fclean re
