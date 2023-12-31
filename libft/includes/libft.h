/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:54:09 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/22 22:57:18 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// Libft
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// Get Next Line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char				*ft_get_next_line(int fd);

// Prinft
# ifndef NULL_STRING
#  define NULL_STRING "(null)"
# endif

# ifndef NULL_POINTER
#  define NULL_POINTER "(nil)"
# endif

# ifndef PRINTF_ERROR
#  define PRINTF_ERROR -1
# endif

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxXobf%"
# endif

# ifndef UPPER_HEXAS
#  define UPPER_HEXAS "0123456789ABCDEF"
# endif

# ifndef LOWER_HEXAS
#  define LOWER_HEXAS "0123456789abcdef"
# endif

# ifndef DECIMALS
#  define DECIMALS "0123456789"
# endif

# ifndef OCTALS
#  define OCTALS "01234567"
# endif

# ifndef BINARIES
#  define BINARIES "01"
# endif

size_t				ft_lputaddress_fd(size_t nbr, int fd);
size_t				ft_lputbin_fd(size_t nbr, int fd);
size_t				ft_lputdouble_fd(double nbr, int fd);
size_t				ft_lputhexa_fd(size_t nbr, int fd, char specifier);
size_t				ft_lputnbr_fd(long nbr, int fd);
size_t				ft_lputoctal_fd(size_t nbr, int fd);
size_t				ft_lputstr_fd(char *s, int fd);
char				*ft_itoa_base(long long nbr, size_t base_len,
						const char *base);
char				*ft_itoa_hex(unsigned long long nbr, size_t base_len,
						const char *base);
char				*ft_ptoa(size_t nbr);
char				*ft_ctoa(char c);
char				*ft_check_string(char *string);

#endif
