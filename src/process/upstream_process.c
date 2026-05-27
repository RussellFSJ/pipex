/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upstream_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:42:40 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/28 00:11:45 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	upstream_process(char *in_file, char **cmd1, char **envp)
{
	int	fd;

	fd = open(in_file, O_RDONLY);
	if (fd < 0)
		handle_perror_exit("Failed to open file1.");
	if (dup2(fd, STDIN_FILENO) == -1)
		handle_perror_exit("Failed to redirect to STDIN.");
	close(fd);
	execve(cmd1[0], cmd1, envp);
	handle_perror_exit("Failed to execute cmd1.");
}
