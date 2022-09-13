/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:15:17 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/04 12:15:18 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen (src);
	if (size < i)
		j += size;
	else
		j += i;
	while (*src && i < (size - 1) && size)
	{
		dst[i] = *src++;
		i++;
	}
	if (size >= ft_strlen(dst))
		dst[i] = 0;
	return (j);
}
