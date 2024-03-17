/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:35:33 by asyvash           #+#    #+#             */
/*   Updated: 2023/11/14 14:48:33 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*str;
	size_t	i;

	dst = (char *)dest;
	str = (char *)src;
	if (str == dst)
		return (0);
	if (dst < str)
		return (ft_memcpy(dst, str, n));
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dst[i] = str[i];
		}
	}
	return (dst);
}
