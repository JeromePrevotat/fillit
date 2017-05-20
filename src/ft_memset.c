/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:25:52 by radam             #+#    #+#             */
/*   Updated: 2017/03/14 14:59:39 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pos_s;
	int				i;

	i = 0;
	pos_s = s;
	while (n != 0)
	{
		pos_s[i] = (unsigned char)c;
		n--;
		i++;
	}
	return (s);
}
