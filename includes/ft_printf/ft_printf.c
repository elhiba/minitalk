/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:27:13 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/09 15:55:37 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	searching(va_list ap, char *input)
{
	int	count;

	count = 0;
	if (*(input + 1) == 'd')
		count += p_ft_putnbr(va_arg(ap, int));
	else if (*(input + 1) == 'i')
		count += p_ft_putnbr(va_arg(ap, int));
	else if (*(input + 1) == 'u')
		count += ft_unsigned_putnbr(va_arg(ap, unsigned int));
	else if (*(input + 1) == 's')
		count += p_ft_putstr(va_arg(ap, char *));
	else if (*(input + 1) == 'c')
		count += p_ft_putchar(va_arg(ap, int));
	else if (*(input + 1) == 'p')
		count += ft_address(va_arg(ap, void *));
	else if (*(input + 1) == 'x')
		count += ft_puthex(va_arg(ap, int), *(input + 1));
	else if (*(input + 1) == 'X')
		count += ft_puthex(va_arg(ap, int), *(input + 1));
	else if (*(input + 1) == '%')
		count += p_ft_putchar(*(input + 1));
	return (count);
}

int	ft_printf(const char *data, ...)
{
	va_list	ap;
	int		count;

	if (!data)
		return (-1);
	count = 0;
	va_start(ap, (char *)data);
	while (*data)
	{
		if (*data == '%')
		{
			count += searching(ap, (char *)data);
			data++;
		}
		else
			count += p_ft_putchar(*data);
		data++;
	}
	va_end(ap);
	return (count);
}
