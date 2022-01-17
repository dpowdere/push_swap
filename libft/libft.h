/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:14:56 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/17 20:40:22 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>

/*
** Standard library or syscalls
** ============================
*/
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);

int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_wctomb(char *s, wchar_t wc);

double		ft_strtod(const char *nptr, char **endptr);
float		ft_strtof(const char *nptr, char **endptr);

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_wcslen(const wchar_t *s);
size_t		ft_wcstombs(char *dst, const wchar_t *src, size_t n);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

ssize_t		ft_write(int fd, const void *buf, size_t count);

/*
** Additional functions
** ====================
*/
int			ft_get_next_line(int fd, char **line);
int			ft_is_big_endian(void);
int			ft_str_index(const char *s, int c);
int			ft_str_endswith(const char *s, const char *suffix);
int			ft_str_startswith(const char *s, const char *prefix);
int			ft_strtoi(const char *nptr, char **endptr, int base);

char		*ft_itoa(int n);
char		*ft_ji_base(intmax_t n, int base, int use_upper_case);
char		*ft_ju_base(uintmax_t n, int base, int use_upper_case);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*
** `ft_split` allocates memory several times -- once per each splitted segment
** of the initial string and once for the array of pointers to strings.
**
** `ft_split_const` allocates a single contiguous array of memory blocks and
** populates them both with an array of pointers to splitted C-strings and
** with the strings themselves. So when deallocation is needed, you only have
** to deallocate the whole range at once without hassle of deallocating the
** individual strings.
*/
char		**ft_split(char const *s, char c);
char *const	*ft_split_const(char const *s, char const *separator_chars);

void		ft_free_null(void **p);

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(const char *s, int fd);

/*
** Print functions inspired by Rust, yet without string formating:
** https://doc.rust-lang.org/rust-by-example/hello/print.html
*/
void		ft_eprint(const char *s);
void		ft_eprintln(const char *s);
void		ft_print(const char *s);
void		ft_println(const char *s);

size_t		ft_ptrarr_len(void *const *arr);
size_t		ft_wcstombs_len(const wchar_t *s);
int			ft_wctomb_len(wchar_t wc);

/*
** Functions to work with linked lists
** ===================================
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int			ft_lstsize(t_list *lst);

t_list		*ft_lstconv(t_list *lst, void *(*f)(void *));
t_list		*ft_lstconv_xd(t_list *lst, void *(*f)(void *, void *),
				void *extra_data);
t_list		*ft_lstdetach(t_list **lst, t_list *detachable_link);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstpopconv(t_list **lst, void *(*f)(void *));
t_list		*ft_lstpopconv_xd(t_list **lst, void *(*f)(void *, void *),
				void *extra_data);

void		*ft_lstpop(t_list **lst);
void		*ft_lstpopreduce(t_list **lst,
				void *initial, void *(*f)(void *, void *));
void		*ft_lstreduce(t_list *lst,
				void *initial, void *(*f)(void *, void *));

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstinsert(t_list **current, t_list *new_next);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstiter_ix(t_list *lst, void (*f)(void *, int ix, int is_last));
void		ft_lstpipeline(t_list **lst, t_list *(*pipeline)(t_list *));
void		ft_lstpipeline_xd(t_list **lst,
				t_list *(*pipeline)(t_list *, void *), void *extra_data);
void		ft_lststream(t_list **lst, t_list *(*stream_process)(t_list **));
void		ft_lststream_xd(t_list **lst,
				t_list *(*stream_process)(t_list **, void *), void *extra_data);

/*
** Functions to work with doubly-linked lists
** ==========================================
*/
typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}			t_dlist;

int			dl_size(t_dlist *lst);
t_dlist		*dl_last(t_dlist *lst);
t_dlist		*dl_new(void *content);
void		*dl_pop(t_dlist **lst);
void		dl_add_back(t_dlist **lst, t_dlist *new);
void		dl_add_front(t_dlist **lst, t_dlist *new);
void		dl_clear(t_dlist **lst, void (*del)(void *));
void		dl_erase(t_dlist **lst, void (*del)(void *));
void		dl_insert(t_dlist **current, t_dlist *new_next);

/*
** Stack
** =====
*/
typedef struct s_stack
{
	t_dlist	*top;
	t_dlist *bottom;
	size_t	size;
}		t_stack;

t_stack	*ft_stack_new(void);
void	ft_stack_clear(t_stack *stack, void (*f)(void *));
void	ft_stack_destroy(t_stack **stack, void (*f)(void *));
void	ft_stack_init(t_stack *stack);
void	*ft_stack_pop(t_stack *stack);
void	ft_stack_push(t_stack *stack, void *data);
void	ft_stack_rotate(t_stack *stack);
void	ft_stack_reverse_rotate(t_stack *stack);

#endif
