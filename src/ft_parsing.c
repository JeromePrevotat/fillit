/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 00:08:21 by admin             #+#    #+#             */
/*   Updated: 2017/03/14 14:56:31 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		ft_parsing(int fd, t_list **tetri_list)
{
	char	c;

	c = 'A';
	ft_read_tetri(fd, tetri_list, c);
	return (1);
}

void	ft_read_tetri(int fd, t_list **tetri_list, char c)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	char	**tetri;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	tmp = ft_strdup(buff);
	if (ft_checklist_tetri(buff) == 0 || ret == 0)
		return (ft_error());
	tetri = ft_convert_dualdim(ft_reduc_tetri(buff));
	ft_save_tetri(tetri_list, tetri, c, ft_get_lines(ft_reduc_tetri(tmp)));
	c++;
	ft_read_nl(fd, tetri_list, c);
}

void	ft_read_nl(int fd, t_list **tetri_list, char c)
{
	char	*buff;
	int		ret;

	if (!(buff = (char *)malloc(2 * sizeof(char))))
		return ;
	ret = read(fd, buff, 1);
	buff[ret] = '\0';
	if (ret == 0)
		return ;
	if (ret == 1 && buff[0] == '\n' && buff[1] == '\0')
		ft_read_tetri(fd, tetri_list, c);
	if (buff[0] != '\n' || buff[1] != '\0')
		return (ft_error());
	return ;
}

int		ft_checklist_tetri(const char *tetri)
{
	if (ft_count_bricks(tetri) != 4)
		return (0);
	if (ft_count_lines(tetri) != 4)
		return (0);
	if (ft_count_char(tetri) != 16)
		return (0);
	if (ft_check_char(tetri) == 0)
		return (0);
	if (ft_check_contacts(tetri) == 0)
		return (0);
	return (1);
}

void	ft_save_tetri(t_list **tetri_list, char **tet2d, char c, int nb_l)
{
	ft_lstadd(tetri_list, ft_lstnew(tet2d, c, nb_l));
}
