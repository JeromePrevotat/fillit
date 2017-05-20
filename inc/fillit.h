/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:32:17 by radam             #+#    #+#             */
/*   Updated: 2017/03/14 15:02:09 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_list
{
	char			**tetri;
	char			letter;
	int				nb_lines;
	int				nb_cols;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_playset
{
	char			**board;
	int				smax;
}					t_playset;

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst);
t_list				*ft_lstnew(char **tetri, char c, int nb_lines);
void				ft_lstdelone(t_list **alst);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putendl(const char *str);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_putstr(char *str);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *str);
void				ft_error(void);
int					ft_parsing(int fd, t_list **tetri_list);
int					ft_exec(int fd);
int					ft_count_bricks(const char *tetri);
int					ft_count_lines(const char *tetri);
int					ft_count_char(const char *tetri);
int					ft_check_char(const char *tetri);
int					ft_check_contacts(const char *tetri);
int					ft_checklist_tetri(const char *tetri);
void				ft_read_tetri(int fd, t_list **tetri_list, char c);
void				ft_read_nl(int fd, t_list **tetri_list, char c);
char				*ft_reduc_tetri(char *tetri);
char				**ft_convert_dualdim(char *tetri);
int					ft_get_lines(char *tetri);
int					ft_get_cols(char *tetri);
char				*ft_reduc_tetri(char *tetri);
void				ft_save_tetri(t_list **tetri_list,\
					char **tet2d, char c, int nb_l);
t_playset			*ft_init_playset(int size);
t_playset			*ft_solve(t_playset *playset, t_list **tetri_list);
int					ft_try_solve(t_playset *playset, t_list *tetri);
int					ft_find_place(t_playset *playset,\
					t_list *tetri, int x, int y);
int					ft_is_putable(t_playset *playset,\
					t_list *tetri, int x, int y);
void				ft_write_tetri(t_playset *playset, \
					t_list *tetri, int x, int y);
void				ft_del_tetri(t_playset *playset,\
					t_list *tetri, int x, int y);
void				ft_free_playset(t_playset *playset);
void				ft_free_ressources(t_playset *playset, t_list **tetri_list);

#endif
