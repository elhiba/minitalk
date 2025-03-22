/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:09:15 by moel-hib          #+#    #+#             */
/*   Updated: 2024/11/11 13:36:50 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)s;
	while (src[i])
	{
		if (src[i] == (char)c)
			return (src + i);
		i++;
	}
	if ((char)c == '\0')
		return (&src[i]);
	return (NULL);
}
