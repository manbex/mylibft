/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:22:47 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/04 16:22:50 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!*little || !little)
		return ((char *)big);
	while (*big && len)
	{
		while (*(big + i) == little[i] && i < len && little[i])
			i++;
		if (little[i] == 0)
			return ((char *)big);
		i = 0;
		big++;
		len--;
	}
	return (0);
}
