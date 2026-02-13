/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:13:39 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/03 17:17:31 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

//Memory Functions 6
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);

//String Functions 7
char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);

//Check Functions 5
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

//Transform Functions 4
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

//Malloc Functions 8
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

//Write Functions 4
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char *s, int fd);

//Struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//List Functions 9
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

//Printf
typedef struct s_var
{
	int				minus;
	int				zero;
	int				width;
	int				point;
	int				precision;
	int				hastag;
	int				space;
	int				plus;
	int				type;
	char			sign;
}	t_var;

//GNL
char	*get_next_line(int fd);

//--------------//Base Functions//-----------------//
int				ft_printf(const char *str, ...);
t_var			ft_parse_format(const char **str);
int				ft_print_format(t_var fmt, va_list ap);
//--------------//STR GENERATORS//-----------------//
char			*ft_write_pointer(unsigned long ptr);
char			*ft_writenbr_base(long nbr, t_var *fmt);
char			*ft_apply_sign(char *raw, t_var fmt);
char			*ft_writechar(char c);
char			*ft_strdup_fix(const char *s);
//------------------//UTILS//---------------------//
void			*ft_memset(void *str, int c, size_t n);
int				ft_putstr_print(char *s, int fd);
int				ft_putchar_print(char c, int fd);
void			*ft_memcpy(void *dest, const void *src, size_t n);
#endif
