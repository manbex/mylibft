/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:46:14 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/07 11:46:15 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		size;

	if (start > ft_strlen(s))
		size = 0;
	else
		size = ft_strlen(s + start);
	if (size > len)
		size = len;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
