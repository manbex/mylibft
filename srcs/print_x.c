/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:22:31 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/23 22:22:32 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_x(unsigned int n)
{
	long unsigned int		nb;

	nb = n;
	if (nb > 15)
	{
		ft_putnbr_x(nb / 16);
		ft_putchar("0123456789abcdef"[nb % 16]);
	}
	else
		ft_putchar("0123456789abcdef"[nb]);
}

static void	ft_putnbr_xx(unsigned int n)
{
	long unsigned int		nb;

	nb = n;
	if (nb > 15)
	{
		ft_putnbr_xx(nb / 16);
		ft_putchar("0123456789ABCDEF"[nb % 16]);
	}
	else
		ft_putchar("0123456789ABCDEF"[nb]);
}

static size_t	ft_count_base(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

int	print_x(va_list ptr, char c)
{
	unsigned int	n;

	n = va_arg(ptr, unsigned int);
	if (c == 'x')
		ft_putnbr_x(n);
	else
		ft_putnbr_xx(n);
	return (ft_count_base(n));
}
