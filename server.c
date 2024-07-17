/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:44:51 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/04 13:28:43 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	manage_bit(int signal)
{
	static char	c;
	static char	i;

	if (signal == SIGUSR2)
		c = (c | (1 << i));
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome Server!\n");
	ft_printf("My Server PID : %d\n", getpid());
	signal(SIGUSR2, manage_bit);
	signal(SIGUSR1, manage_bit);
	while (1)
		pause();
	return (0);
}
