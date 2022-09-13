/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:32:40 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/17 21:32:41 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_call(char c, va_list ptr)
{
	if (c == 'c')
		return (print_c(ptr));
	if (c == 's')
		return (print_s(ptr));
	if (c == 'p')
		return (print_p(ptr));
	if (c == 'd' || c == 'i')
		return (print_id(ptr));
	if (c == 'u')
		return (print_u(ptr));
	if (c == 'x' || c == 'X')
		return (print_x(ptr, c));
	if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_check(char c)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (c == "cspdiuxX%"[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		size;
	int		tmp;

	va_start(ptr, str);
	size = 0;
	tmp = 0;
	if (!str)
		return (-1);
	while (*((char *)str))
	{
		if (*((char *)str) == '%' && *((char *)str + 1))
		{
			tmp = ft_call(*((char *)str + 1), ptr);
			if (tmp < 0)
				return (-1);
			size += tmp;
			(char *)str++;
		}
		else
			size += write(1, &(*((char *)str)), 1);
		str++;
	}
	va_end(ptr);
	return (size);
}
