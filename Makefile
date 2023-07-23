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

MANDATORY_HEADER = mandatory/includes/
PATH_MANDATORY_SRC = mandatory/sources/
PATH_MANDATORY_OBJ = mandatory/objects/
MANDATORY_SRC = $(addprefix $(PATH_MANDATORY_SRC), ft_printf.c)
MANDATORY_OBJS = ${MANDATORY_SRC:$(PATH_MANDATORY_SRC)%.c=$(PATH_MANDATORY_OBJ)%.o}

BONUS_HEADER = bonus/includes/
PATH_BONUS_SRC = bonus/sources/
PATH_BONUS_OBJ = bonus/objects/
BONUS_SRC = $(addprefix $(PATH_BONUS_SRC), ft_printf_bonus.c ft_manage_params_bonus.c ft_write_params_bonus.c)
BONUS_OBJS = ${BONUS_SRC:$(PATH_BONUS_SRC)%.c=$(PATH_BONUS_OBJ)%.o}

LIBFT = libft/libft.a
LIBFT_HEADER = libft/includes/
MAKE_LIBFT = make -C libft

CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror -g3

.PHONY: all clean fclean re bonus libft

all: $(NAME)

$(PATH_MANDATORY_OBJ)%.o: $(PATH_MANDATORY_SRC)%.c
	mkdir -p $(PATH_MANDATORY_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(MANDATORY_HEADER)

$(NAME): $(LIBFT) $(MANDATORY_OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(MANDATORY_OBJS)

$(LIBFT):
	$(MAKE_LIBFT)

bonus: $(LIBFT) $(BONUS_OBJS) 
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)

$(PATH_BONUS_OBJ)%.o: $(PATH_BONUS_SRC)%.c
	mkdir -p $(PATH_BONUS_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(BONUS_HEADER)

clean:
	rm -rf $(PATH_MANDATORY_OBJ) $(PATH_BONUS_OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all
