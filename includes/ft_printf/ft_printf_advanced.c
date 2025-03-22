/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:22:10 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/09 15:55:58 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_counter(unsigned long long n)
{
	int	len;

	len = 0;
	while (0 < n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int c, char style)
{
	int		size;
	char	*result;
	char	*hex;

	if (c == 0)
		return (p_ft_putchar('0'));
	if (style == 'X')
		hex = UHEXA;
	else
		hex = LHEXA;
	size = len_counter((unsigned long long)c);
	result = malloc(size + 1);
	if (!result)
		return (0);
	result[size] = '\0';
	while (0 < size)
	{
		result[size - 1] = hex[(c) % 16];
		c /= 16;
		size--;
	}
	size = p_ft_putstr(result);
	free(result);
	return (size);
}

int	ft_nb_puthex(unsigned long long n)
{
	char	*result;
	int		len;

	len = len_counter(n);
	result = malloc(len + 1);
	if (!result)
		return (0);
	result[len] = '\0';
	while (0 < len)
	{
		result[len - 1] = LHEXA[n % 16];
		n /= 16;
		len--;
	}
	len = p_ft_putstr(result);
	free(result);
	return (len);
}

int	ft_address(void *ptr)
{
	unsigned long long	address;
	int					len;

	len = 0;
	address = (unsigned long long)ptr;
	if (address == 0)
		return (p_ft_putstr("(nil)"));
	len += p_ft_putstr("0x");
	len += ft_nb_puthex(address);
	return (len);
}
