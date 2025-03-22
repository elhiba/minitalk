/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:11:53 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/09 15:58:22 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	p_ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	p_ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	p_ft_putstr(char *s)
{
	int	len;

	if (!s)
		return (p_ft_putstr("(null)"));
	write(1, s, p_ft_strlen(s));
	len = p_ft_strlen(s);
	return (len);
}

int	p_ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += p_ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		len += p_ft_putnbr((n / 10));
	}
	len += p_ft_putchar('0' + (n % 10));
	return (len);
}

int	ft_unsigned_putnbr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_unsigned_putnbr((n / 10));
	}
	len += p_ft_putchar('0' + (n % 10));
	return (len);
}
