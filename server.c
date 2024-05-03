/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:44:51 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/03 10:36:50 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

typedef struct
{
	int	c;
	int	i;
} Msg;

Msg	g_msg = {0, 0};

void	manejar_bit(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome Server!\n");
	ft_printf("Mi Server PID es: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, manejar_bit);
		signal(SIGUSR1, manejar_bit);
		while (1)
		{
			pause();
		}
	}
	return (0);
}
