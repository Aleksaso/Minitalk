/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:13:57 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/03 11:28:34 by asilva-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_char(char c);
int		ft_simbol(void);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_counter1(int nb);
int		ft_putnbr(int nb);
int		ft_hexd(unsigned int n, char type);
void	recursiva(unsigned long long nbr, char *base);
int		ft_ptro(unsigned long long n);
int		ft_str(char *str);
int		ft_counter2(unsigned int nb);
int		ft_nbru(unsigned int nb);

#endif
