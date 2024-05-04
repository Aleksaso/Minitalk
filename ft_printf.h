/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva-o <asilva-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:13:57 by asilva-o          #+#    #+#             */
/*   Updated: 2024/05/04 12:14:59 by asilva-o         ###   ########.fr       */
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
int		ft_putnbr(int nb);
int		ft_hexd(unsigned int n, char type);
int		ft_ptro(unsigned long long n);
int		ft_str(char *str);
int		ft_counter(unsigned long long n, int base);
int		ft_nbru(unsigned int nb);

#endif
