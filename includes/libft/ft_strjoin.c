/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:44:03 by moel-hib          #+#    #+#             */
/*   Updated: 2025/02/09 15:30:51 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*src;
	int		total_len;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2;
	src = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!src)
		return (NULL);
	ft_memcpy(src, s1, len_s1);
	ft_memcpy(src + len_s1, s2, len_s2);
	src[total_len] = '\0';
	return (src);
}
