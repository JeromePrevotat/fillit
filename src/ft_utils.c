/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:20:03 by jprevota          #+#    #+#             */
/*   Updated: 2017/03/16 13:20:07 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

t_playset	*ft_init_playset(int size)
{
	t_playset	*playset;
	int			i;
	int			j;

	if (!(playset = (t_playset *)malloc(sizeof(t_playset))))
		return (NULL);
	playset->smax = size;
	if (!(playset->board = (char **)malloc(size * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		playset->board[i] = ft_strnew(size);
		while (j < size)
		{
			playset->board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (playset);
}

void		ft_free_playset(t_playset *playset)
{
	ft_memdel((void **)&(playset->board));
	ft_memdel((void **)&playset);
}

void		ft_write_tetri(t_playset *playset, t_list *tetri, int x, int y)
{
	int	l;
	int	c;

	l = 0;
	while (l <= tetri->nb_lines)
	{
		c = 0;
		while (c <= tetri->nb_cols)
		{
			if (tetri->tetri[l][c] == '#')
				playset->board[y + l][x + c] = tetri->letter;
			c++;
		}
		l++;
	}
}

void		ft_del_tetri(t_playset *playset, t_list *tetri, int x, int y)
{
	int	l;
	int	c;

	l = 0;
	while (l <= tetri->nb_lines)
	{
		c = 0;
		while (c < tetri->nb_cols)
		{
			if (tetri->tetri[l][c] == '#')
				playset->board[y + l][x + c] = '.';
			c++;
		}
		l++;
	}
}

void		ft_free_ressources(t_playset *playset, t_list **tetri_list)
{
	ft_free_playset(playset);
	while ((*tetri_list)->prev != NULL)
		(*tetri_list) = (*tetri_list)->prev;
	while ((*tetri_list) != NULL)
	{
		ft_memdel((void **)&(*tetri_list)->tetri);
		(*tetri_list) = (*tetri_list)->next;
	}
	ft_memdel((void **)&(tetri_list));
}
