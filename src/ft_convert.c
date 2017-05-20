/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 00:38:37 by admin             #+#    #+#             */
/*   Updated: 2017/03/14 14:57:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static char	**ft_tetri_copy(char **tetri2d, char *tetri)
{
	int	i;
	int	c;
	int	l;

	i = 0;
	l = 0;
	while (l <= ft_get_lines(tetri))
	{
		c = 0;
		while (tetri[i] != '\n' && tetri[i] != '\0')
		{
			tetri2d[l][c] = tetri[i];
			c++;
			i++;
		}
		tetri2d[l][c] = '\0';
		i++;
		l++;
	}
	return (tetri2d);
}

char		**ft_convert_dualdim(char *tetri)
{
	char	**tetri2d;
	int		i;

	i = -1;
	if (!(tetri2d =
				(char **)malloc((ft_get_lines(tetri) + 1) * sizeof(char *))))
		return (NULL);
	while (i++ < ft_get_lines(tetri) + 1)
	{
		if (!(tetri2d[i] =
					(char *)malloc(ft_get_cols(tetri) * sizeof(char))))
			return (NULL);
	}
	tetri2d = ft_tetri_copy(tetri2d, tetri);
	return (tetri2d);
}

int			ft_get_lines(char *tetri)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '\n')
			l++;
		i++;
	}
	return (l - 1);
}

int			ft_get_cols(char *tetri)
{
	int	i;

	i = 0;
	while (tetri[i] != '\n')
		i++;
	return (i + 1);
}
