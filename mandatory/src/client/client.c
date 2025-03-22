/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:51:09 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/21 09:48:35 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

static volatile sig_atomic_t	g_var;

/* *PONG 🏓*
 * 'r' One signal has been received! [ONE]
 * 's' Server is busy! [ZERO]
 */
void	pong(int sig)
{
	if (sig == ONE)
		g_var = 1;
	else
	{
		write(2, SERVB, ft_strlen(SERVB));
		exit(-1);
	}
}

int	send_data(int pid, char character)
{
	static t_signal	vars;

	vars.client_bits = 7;
	while (vars.client_bits >= 0)
	{
		if ((character >> vars.client_bits) & 0X01)
		{
			if (!sig_checker(kill(pid, ONE)))
				exit(-1);
		}
		else
		{
			if (!sig_checker(kill(pid, ZERO)))
				exit(-1);
		}
		while (!g_var)
			;
		g_var = 0;
		(vars.client_bits--);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	i = 0;
	if (ac != 3)
		exit(ft_printf(IN_CL_ERR));
	input_checker(av);
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		exit(1);
	sa.sa_handler = pong;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (!sig_checker(sigaction(ZERO, &sa, NULL)))
		exit(-1);
	if (!sig_checker(sigaction(ONE, &sa, NULL)))
		exit(-1);
	while (av[2][i])
		send_data(pid, av[2][i++]);
	return (0);
}
