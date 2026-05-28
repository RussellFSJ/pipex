/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:39:08 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/29 06:14:28 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex *px)
{
	int		pipefd[2];
	pid_t	upstream_process_id;
	pid_t	downstream_process_id;

	if (pipe(pipefd) == -1)
		handle_perror_exit("Failed to create pipe.");
	upstream_process_id = fork();
	if (upstream_process_id == -1)
		handle_perror_exit("Failed to fork upstream process.");
	if (upstream_process_id == 0)
		upstream_process(pipefd, px);
	downstream_process_id = fork();
	if (downstream_process_id == -1)
		handle_perror_exit("Failed to fork downstream process.");
	if (downstream_process_id == 0)
		downstream_process(pipefd, px);
	close_pipefd(pipefd);
	waitpid(upstream_process_id, NULL, 0);
	waitpid(downstream_process_id, NULL, 0);
}
