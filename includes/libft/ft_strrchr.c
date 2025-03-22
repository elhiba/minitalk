/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:03:29 by moel-hib          #+#    #+#             */
/*   Updated: 2024/11/11 13:47:51 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)s;
	while (src[i])
		i++;
	while (0 <= i)
	{
		if ((unsigned char)src[i] == (unsigned char)c)
			return (src + i);
		i--;
	}
	if (c == '\0')
		return (src + i);
	return (NULL);
}
