/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:46:20 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/03 11:53:42 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counter(unsigned long long n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		n *= -1;
	if (n > 15)
	{
		while (n != 0)
		{
			size++;
			n /= 16;
		}
	}
	else
		size++;
	return (size);
}

int	ft_counter1(int nb)
{
	int	cnt;

	cnt = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		cnt++;
	}
	if (nb == 0)
		cnt++;
	while (nb != 0)
	{
		nb = nb / 10;
		cnt++;
	}
	return (cnt);
}

int	ft_putnbr(int nb)
{
	int	x;

	x = ft_counter1(nb);
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
	char	*base;
	long	num;

	num = n;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_hexd(num / 16, type);
		num %= 16;
	}
	write(1, &base[num], 1);
	return (ft_counter(n));
}

void	recursiva(unsigned long long nbr, char *base)
{
	if (nbr > 15)
	{
		recursiva(nbr / 16, base);
		nbr %= 16;
	}
	write(1, &base[nbr], 1);
}

int	ft_ptro(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "0x", 2);
	recursiva(n, base);
	return (ft_counter(n) + 2);
}

int	ft_str(char *str)

{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i = ft_str("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int	ft_counter2(unsigned int nb)
{
	int	cnt;

	cnt = 0;
	if (nb == 0)
		cnt++;
	while (nb != 0)
	{
		nb = nb / 10;
		cnt++;
	}
	return (cnt);
}

int	ft_nbru(unsigned int nb)
{
	int	res;

	res = ft_counter2(nb);
	if (nb > 9)
	{
		ft_nbru(nb / 10);
		nb %= 10;
	}
	ft_char (nb + '0');
	return (res);
}
