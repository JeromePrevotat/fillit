/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:11:29 by jprevota          #+#    #+#             */
/*   Updated: 2017/03/14 14:56:43 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

t_playset	*ft_solve(t_playset *playset, t_list **tetri_list)
{
	playset = ft_init_playset(playset->smax);
	while (!(ft_try_solve(playset, *tetri_list)))
	{
		ft_free_playset(playset);
		playset = ft_init_playset(playset->smax + 1);
	}
	return (playset);
}

int			ft_find_place(t_playset *playset, t_list *tetri, int x, int y)
{
	if (ft_is_putable(playset, tetri, x, y) == 1)
	{
		ft_write_tetri(playset, tetri, x, y);
		return (1);
	}
	return (0);
}

int			ft_try_solve(t_playset *playset, t_list *tetri)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (tetri == NULL)
		return (1);
	while (y < playset->smax - tetri->nb_lines)
	{
		x = 0;
		while (x < playset->smax - tetri->nb_cols + 1)
		{
			if (ft_find_place(playset, tetri, x, y))
			{
				if (ft_try_solve(playset, tetri->next))
					return (1);
				else
					ft_del_tetri(playset, tetri, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			ft_is_putable(t_playset *playset, t_list *tetri, int x, int y)
{
	int	l;
	int	c;

	l = 0;
	while (l <= tetri->nb_lines)
	{
		c = 0;
		while (c < tetri->nb_cols)
		{
			if (((y + l) < playset->smax) && ((x + c) < playset->smax))
			{
				if (tetri->tetri[l][c] == '#'
					&& playset->board[y + l][x + c] != '.')
					return (0);
			}
			c++;
		}
		l++;
	}
	return (1);
}
