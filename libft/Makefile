# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:06:56 by jovicto2          #+#    #+#              #
#    Updated: 2023/06/16 20:24:42 by jovicto2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_SRC = sources/

PATH_OBJ = objects/

SRC = $(addprefix $(PATH_SRC), ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
		ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c ft_get_next_line.c ft_lputstr_fd.c ft_lputaddress_fd.c ft_lputhexa_fd.c ft_lputoctal_fd.c \
		ft_lputdouble_fd.c ft_lputbin_fd.c ft_lputnbr_fd.c ft_itoa_base.c ft_ptoa.c ft_ctoa.c) 

HEADER = includes/

AR = ar -rcs

FLAGS = -Wall -Wextra -Werror -g3

OBJS = ${SRC:$(PATH_SRC)%.c=$(PATH_OBJ)%.o}

all: $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	mkdir -p $(PATH_OBJ)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER) 

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(PATH_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
