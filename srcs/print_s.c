/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:26:55 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/20 20:26:56 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_s(va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write (1, str, ft_strlen(str)));
}
