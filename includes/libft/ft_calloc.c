/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:45:03 by moel-hib          #+#    #+#             */
/*   Updated: 2024/11/11 11:44:14 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*caldup;

	caldup = malloc(nmemb * size);
	if (!caldup)
		return (NULL);
	ft_bzero(caldup, nmemb * size);
	return (caldup);
}
