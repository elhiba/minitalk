/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingPong_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:01:52 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/21 08:14:52 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

/* *PING 🏓*
 * 'r' One signal has been received! [ONE]
 * 't' Message received DONE [ZERO]
 */
void	ping(int pid, char sig)
{
	if (sig == 'r')
		if (!sig_checker(kill(pid, ONE)))
			exit(-1);
	if (sig == 't')
		if (!sig_checker(kill(pid, ZERO)))
			exit(-1);
}

/* *PONG 🏓*
 * 'r' One signal has been received! [ONE]
 * 's' Server is busy! [ZERO]
 */
// void	pong(int sig)
// {
// 	if (sig == ZERO)
// 	{
// 		write(2, SERVB, ft_strlen(SERVB));
// 		exit(-1);
// 	}
// }
// 01000101	000000000001
// 01000101
// 01000101
// bits -1
