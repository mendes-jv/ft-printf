# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 22:17:12 by jovicto2          #+#    #+#              #
#    Updated: 2023/06/24 22:30:43 by jovicto2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MANDATORY_HEADER = mandatory/includes/ft_printf.h

PATH_MANDATORY_SRC = mandatory/sources/

PATH_MANDATORY_OBJ = mandatory/objects/

MANDATORY_SRC = $(addprefix $(PATH_MANDATORY_SRC), ft_printf.c)

LIBFT = libft/libft.a

MAKE_LIBFT = make -C libft 

AR = ar -rcs

FLAGS = -Wall -Wextra -Werror -g3

MANDATORY_OBJS = ${MANDATORY_SRC:$(PATH_MANDATORY_SRC)%.c=$(PATH_MANDATORY_OBJ)%.o}

all: $(NAME)

$(PATH_MANDATORY_OBJ)%.o: $(PATH_MANDATORY_SRC)%.c
	mkdir -p $(PATH_MANDATORY_OBJ)
	$(CC) $(FLAGS) -c $< -o $@ -I $(MANDATORY_HEADER) $(LIBFT) 

$(NAME): $(LIBFT) $(MANDATORY_OBJS)
	$(AR) $(NAME) $(MANDATORY_OBJS)

$(LIBFT):
	$(MAKE_LIBFT)

clean:
	rm -rf $(PATH_MANDATORY_OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
