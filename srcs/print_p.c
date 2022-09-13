/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:50:07 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/23 22:50:09 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_hex(unsigned long long int n)
{
	if (n > 15)
	{
		ft_putnbr_hex(n / 16);
		ft_putchar("0123456789abcdef"[n % 16]);
	}
	else
		ft_putchar("0123456789abcdef"[n]);
}

static size_t	ft_count_base(unsigned long long int n)
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

int	print_p(va_list ptr)
{
	unsigned long long int	addr;

	addr = (unsigned long long int)va_arg(ptr, void *);
	if (addr)
	{
		write(1, "0x", 2);
		ft_putnbr_hex(addr);
		return (ft_count_base(addr) + 2);
	}
	return (write(1, PTR_NULL, 5));
}
