/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:47:13 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/25 13:47:14 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE 4096
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

int					get_next_line(const int fd, char **line);
t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree *root, \
					void *item, int (*cmpf)(void *, void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *memptr1, \
					const void *memptr2, size_t num);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *destptr, const char *srcptr);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *destptr, const char *srcptr, size_t num);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strncpy(char *destptr, const char *srcptr, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t leng);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_swap(int *x, int *y);
void				ft_arsort(int *s, int len);
void				ft_putarr(int *arr, int size);
void				ft_arrmin(int *arr, int size);
void				ft_arrmax(int *arr, int size);
double				ft_atof(char *s);
#endif
