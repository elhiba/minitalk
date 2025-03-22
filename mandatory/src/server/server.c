/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:51:12 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/22 15:09:05 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	receive_data(int sig, siginfo_t *info, void __attribute__((unused))
		*context)
{
	static t_signal	vars = {.server_bits = 7};

	if (vars.client_pid != info->si_pid)
		if (!data_analyse(&vars, info->si_pid))
			return ;
	if (vars.server_bits >= 0)
	{
		vars.server_val <<= 1;
		if (sig == ONE)
			vars.server_val |= 0X01;
		(vars.server_bits)--;
	}
	if (vars.server_bits < 0)
	{
		write(1, &vars.server_val, 1);
		vars.server_bits = 7;
		vars.server_val = 0;
	}
	ping(vars.client_pid, 'r');
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("The server PID:\t%i\n", getpid());
	sa.sa_sigaction = receive_data;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (!sig_checker(sigaction(SIGUSR1, &sa, NULL)))
		exit(-1);
	if (!sig_checker(sigaction(SIGUSR2, &sa, NULL)))
		exit(-1);
	while (1)
		pause();
	return (0);
}
