/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:35:05 by radam             #+#    #+#             */
/*   Updated: 2017/03/14 14:58:34 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

t_list		*ft_lstnew(char **tetri, char c, int nb_lines)
{
	t_list	*list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	list->tetri = tetri;
	list->letter = c;
	list->nb_lines = nb_lines;
	list->nb_cols = ft_strlen(tetri[0]);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
