# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msagodir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/13 17:59:08 by msagodir          #+#    #+#              #
#    Updated: 2014/01/18 18:10:44 by msagodir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = wolf3d
PATH_INC = ./incs
PATH_OBJ = ./objs
PATH_SRC = ./srcs
LIBDIR = libft
SRC = 	main.c		\
		draw.c		\
		inits.c		\
		calc.c		\
		directions.c\
		map.c
OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all : lib $(NAME)

lib:
		@make -C $(LIBDIR)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) -L$(LIBDIR) -lft \
		-L/usr/X11/lib -lmlx -lXext -lX11 $(OBJ)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
		mkdir -p $(PATH_OBJ)
		$(CC) $(CFLAGS) -o $@ -c $^ -I $(PATH_INC) -I $(LIBDIR)/includes \
			-I /usr/X11/include

clean :
		$(MAKE) -C $(LIBDIR) $@
			rm -rf $(OBJ)

fclean :
		$(MAKE) -C $(LIBDIR) $@
		rm -rf $(OBJ)
		rm -rf $(NAME)

re : fclean all

.PHONY: re, clean, fclean
