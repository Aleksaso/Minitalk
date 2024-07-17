/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:33:36 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/03 12:29:16 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stddef.h>

void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("\nWrong PID\n\n");
			return (1);
		}
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
	{
		ft_printf("\nWrong input\n\n");
	}
	return (0);
