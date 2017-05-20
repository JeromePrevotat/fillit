/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 00:50:13 by admin             #+#    #+#             */
/*   Updated: 2017/03/14 14:58:05 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_find_useless_char(char *tetri)
{
	int	i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '.')
		{
			if ((tetri[i + 1] == '#'
				|| ((tetri[i - 1] == '#') && (i - 1 >= 0))
				|| (tetri[i + 2] == '#' && tetri[i + 1] != '\n')
				|| ((tetri[i - 2] == '#' && (i - 2) >= 0)
					&& (tetri[i - 1] != '\n')))
				&& ((tetri[i + 5] == '#' && i + 5 < (int)ft_strlen(tetri))
				|| (tetri[i - 5] == '#' && i - 5 >= 0)
				|| (tetri[i + 10] == '#' && i + 10 < (int)ft_strlen(tetri))
				|| (tetri[i - 10] == '#' && i - 10 >= 0)))
				i++;
			else
				tetri[i] = 'o';
		}
		if (tetri[i] != '.')
			i++;
	}
}

void	ft_find_useless_lines(char *tetri)
{
	int	i;
	int	empty_line;

	i = 0;
	while (tetri[i] != '\0')
	{
		empty_line = 1;
		while (tetri[i] != '\n')
		{
			if (tetri[i] != 'o')
				empty_line = 0;
			i++;
		}
		if (empty_line == 1)
			tetri[i] = 'o';
		i++;
	}
}

int		ft_count_nb_char(char *tetri)
{
	int	nb_char;
	int	i;

	i = 0;
	nb_char = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != 'o')
			nb_char++;
		i++;
	}
	return (nb_char);
}

char	*ft_save_reduc_tetri(char *tetri, char *rtetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != 'o')
		{
			rtetri[j] = tetri[i];
			j++;
		}
		i++;
	}
	rtetri[j] = '\0';
	return (rtetri);
}

char	*ft_reduc_tetri(char *buff)
{
	char	*tetri;
	int		nb_char;

	nb_char = 0;
	ft_find_useless_char(buff);
	ft_find_useless_lines(buff);
	nb_char = ft_count_nb_char(buff);
	tetri = (char *)malloc((nb_char + 1) * sizeof(char));
	if (!tetri)
		return (NULL);
	tetri = ft_save_reduc_tetri(buff, tetri);
	return (tetri);
}
