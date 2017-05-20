/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:40:24 by radam             #+#    #+#             */
/*   Updated: 2017/03/14 14:58:15 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_lstadd(t_list **alst, t_list *lst_new)
{
	if ((*alst) == NULL && lst_new)
		(*alst) = lst_new;
	else if ((*alst) != NULL && lst_new)
	{
		while ((*alst)->next != NULL)
			(*alst) = (*alst)->next;
		(*alst)->next = lst_new;
		lst_new->prev = (*alst);
		lst_new->next = NULL;
	}
}
