/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:33:52 by radam             #+#    #+#             */
/*   Updated: 2017/03/14 14:58:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	pdst = (char *)dest;
	psrc = (const char *)src;
	while (n--)
		*pdst++ = *psrc++;
	return (dest);
}
