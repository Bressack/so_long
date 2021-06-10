/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:06:07 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:39:46 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <so_long.h>
// # include <unistd.h>
# include <color_shell.h>
# define NUM			"0123456789"
# define BUFF_SIZE_GNL	8192
typedef struct s_str
{
	char			*str;
	int				fd;
	struct s_str	*next;
}					t_str;
int			ft_strfind_ls_char(char *s, char *to_find);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *s1, const char *s2);
void		ft_strdel(char **as);
char		*ft_strdup(char *src);
int			ft_strfind(char *s, int c);
int			ft_strfind_c(char *s, int c);
char		*ft_strjoin(int nb_str, ...);
int			ft_strlen(const char *s);
void		eprint(char *msg);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			get_next_line(const int fd, char **line);
void		*try_malloc(size_t size);
void		ft_putnbr(int n);
#endif
