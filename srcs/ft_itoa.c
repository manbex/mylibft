/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:35:34 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/05 19:35:35 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev(char *str, int size)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = size - 1;
	size--;
	while (i <= size / 2)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

size_t	ft_count(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_convert(char *str, int n)
{
	int			i;
	long int	nb;

	nb = n;
	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		i++;
	}
	if (n < 0)
		nb *= -1;
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;

	str = malloc((ft_count(n) + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_convert(str, n);
	str = ft_rev(str, ft_strlen(str));
	return (str);
}
