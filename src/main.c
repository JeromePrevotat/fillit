/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:08:25 by jprevota          #+#    #+#             */
/*   Updated: 2017/03/14 14:57:11 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../inc/fillit.h"

void		ft_error(void)
{
	ft_putendl("error");
	exit(-1);
}

static void	ft_usage(void)
{
	ft_putendl("usage: ./fillit PathToMyFile");
}

int			ft_exec(int fd)
{
	t_list		*tetri_list;
	t_playset	*playset;
	int			i;

	tetri_list = NULL;
	if (ft_parsing(fd, &tetri_list) == 0)
		return (-1);
	while (tetri_list->prev != NULL)
		tetri_list = tetri_list->prev;
	if (!(playset = (t_playset *)malloc(1 * sizeof(t_playset))))
		return (-1);
	playset->smax = 2;
	playset = ft_solve(playset, &tetri_list);
	i = 0;
	while (i < playset->smax)
		ft_putendl(playset->board[i++]);
	return (1);
}

int			main(int argc, char **argv)
{
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		return (ft_exec(fd));
	}
	else
	{
		ft_usage();
		return (-1);
	}
	return (0);
}
