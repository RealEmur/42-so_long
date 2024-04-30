/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:09:03 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/07 18:46:01 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*chr_dst;
	char		*chr_src;

	if (!dst && !src)
		return (dst);
	chr_dst = (char *) dst;
	chr_src = (char *) src;
	i = 0;
	while (i < n)
	{
		chr_dst[i] = chr_src[i];
		i++;
	}
	return (dst);
}
