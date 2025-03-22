/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hib <moel-hib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:55:35 by moel-hib          #+#    #+#             */
/*   Updated: 2025/03/22 15:11:23 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <signal.h>
# include <unistd.h>

# define ONE SIGUSR2
# define ZERO SIGUSR1

typedef struct s_signal
{
	int		client_pid;
	int		client_bits;
	int		server_bits;
	char	server_val;
}			t_signal;

/*
 * Handling errors messgaes for (NORMINETTE):
 *
 * COLORS AINSI CODE:
 * GREEN		\e[1;32m
 * GREEN_UND	\e[4;32m
 *
 * RED		\e[1;31m
 * RED_UND	\e[4;31m
 *
 * RESET	\e[0m
 */
# define IN_CL_ERR "\e[1;31mError:\t Usage: ./client <PID> <Message>!\e[0m\n"
# define SERR "\e[1;31mError:\t Failed to send data. Please try again.\e[0m\n"

# define PIDERR "\e[1;31mAre you serious? OFC WRONG PID!\e[0m\n"

//# define SERVB "\e[1;31mServer too Busy!\n"
# define CSUCC "\e[1;32mMessage has been successfully received!\e[0m\n"

/*
 * sig_checker helps to check signal if had succeeded!
 */
int			sig_checker(int kill);

/*
 * ping : Hey client! i receive the signal!
 * Pong : [client] let me cook!
 */
void		ping(int pid, char sig);
void		pong(int sig);

/*
 * Not a real analyse, just filtring other process from the active client!
 */
int			data_analyse(t_signal *vars, int infoPid);

/*
 * Verifying sus inputs
 */
int			input_checker(char **av);
#endif
