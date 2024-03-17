/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:20 by asyvash           #+#    #+#             */
/*   Updated: 2023/11/12 11:48:18 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;
	size_t	s_start;

	s_start = (size_t)start;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_start > s_len)
		s_start = s_len;
	if (len > s_len - s_start)
		len = s_len - s_start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[s_start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
