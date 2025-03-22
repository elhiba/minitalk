/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:36:20 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/21 09:40:55 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

int	data_analyse(t_signal *vars, int infoPid)
{
	if (vars->client_pid == 0)
		vars->client_pid = infoPid;
	else
	{
		if (kill(vars->client_pid, 0) != -1)
		{
			ping(infoPid, 's');
			return (0);
		}
		else
		{
			vars->server_bits = 7;
			vars->server_val = 0;
			vars->client_pid = infoPid;
		}
	}
	return (1);
}

int	input_checker(char **av)
{
	int	s;

	s = 0;
	while (av[1])
	{
		if (!ft_isdigit(av[1][s]))
		{
			if (av[1][s] == '\0')
				break ;
			write(1, PIDERR, ft_strlen(PIDERR));
			exit(-1);
		}
		s++;
	}
	return (1);
}

int	sig_checker(int kill)
{
	if (kill == -1)
	{
		write(2, SERR, ft_strlen(SERR));
		return (0);
	}
	return (1);
}
