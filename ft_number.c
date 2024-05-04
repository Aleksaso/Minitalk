/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:46:20 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/04 12:46:23 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counter(unsigned long long n, int base)
{
	int	size;

	size = 1;
	if (n == 0)
		return (size);
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

int	ft_putnbr(int nb)
{
	int	x;

	x = ft_counter(nb, 10);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_char('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	ft_char (nb + '0');
	return (x);
}

int	ft_hexd(unsigned int n, char type)
{
	const char	*base;
	int			x;

	if (type == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	x = ft_counter(n, 16);
	while (n > 15)
	{
		ft_hexd(n / 16, type);
		n %= 16;
	}
	write(1, &base[n], 1);
	return (x);
}

int	ft_ptro(unsigned long long n)
{
	const char	*base;
	int			x;

	base = "0123456789abcdef";
	write(1, "0x", 2);
	x = ft_counter(n, 16) + 2;
	while (n > 15)
	{
		ft_ptro(n / 16);
		n %= 16;
	}
	write(1, &base[n], 1);
	return (x);
}

int	ft_nbru(unsigned int nb)
{
	int	res;

	res = ft_counter(nb, 10);
	if (nb > 9)
	{
		ft_nbru(nb / 10);
		nb %= 10;
	}
	ft_char (nb + '0');
	return (res);
}
