/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 00:24:58 by admin             #+#    #+#             */
/*   Updated: 2017/03/14 01:13:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int	ft_count_bricks(const char *tetri)
{
	int	i;
	int	nb_bricks;

	i = 0;
	nb_bricks = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '#')
			nb_bricks++;
		i++;
	}
	return (nb_bricks);
}

int	ft_count_lines(const char *tetri)
{
	int	i;
	int	nb_lines;

	i = 0;
	nb_lines = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '\n' && (i == 4 || i == 9 || i == 14 || i == 19))
			nb_lines++;
		i++;
	}
	return (nb_lines);
}

int	ft_count_char(const char *tetri)
{
	int	i;
	int	nb_char;

	i = 0;
	nb_char = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != '\n' && tetri[i] != '\0')
			nb_char++;
		i++;
	}
	return (nb_char);
}

int	ft_check_char(const char *tetri)
{
	int	i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != '#' && tetri[i] != '.' && tetri[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_contacts(const char *tetri)
{
	int	i;
	int	nb_contacts;

	i = 0;
	nb_contacts = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '#')
		{
			if (i - 5 >= 0 && tetri[i - 5] == '#')
				nb_contacts++;
			if (i - 1 >= 0 && tetri[i - 1] == '#')
				nb_contacts++;
			if (i + 5 <= 20 && tetri[i + 5] == '#')
				nb_contacts++;
			if (i + 1 <= 20 && tetri[i + 1] == '#')
				nb_contacts++;
		}
		i++;
	}
	if (nb_contacts < 6)
		return (0);
	return (1);
}
