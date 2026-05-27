/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:39:08 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/28 00:21:23 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex *px)
{
	int		pipefd[2];
	pid_t	upstream_process;
	pid_t	downstream_process;
	
	if (pipe(pipefd) == -1)
		handle_perror_exit("Failed to create pipe.");
	upstream_process = fork();
	if (upstream_process == -1)
		handle_perror_exit("Failed to fork upstream process.");
}

