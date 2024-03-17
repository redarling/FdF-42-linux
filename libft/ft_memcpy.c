/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:35:25 by asyvash           #+#    #+#             */
/*   Updated: 2023/11/14 14:50:07 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*res;
	char	*str;
	size_t	i;

	i = 0;
	res = (char *)dest;
	str = (char *)src;
	if (res == str)
		return (0);
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
