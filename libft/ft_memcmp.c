/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:37:11 by asyvash           #+#    #+#             */
/*   Updated: 2023/11/02 12:03:26 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		delta;
	size_t	i;

	i = 0;
	while (i < n)
	{
		delta = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (delta)
			return (delta);
		i++;
	}
	return (0);
}
