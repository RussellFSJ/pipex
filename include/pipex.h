/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:37:01 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/28 00:04:47 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft.h"
# include <fcntl.h>

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	*in_file;
	char	*out_file;
}	t_pipex;

void	upstream_process(char *in_file, char **cmd1, char **envp);
void	downstream_process(char *out_file, char **cmd2, char **envp);
t_pipex	*init_pipex(char	**argv, char **envp);
void	handle_perror_exit(char **err_msg);
int		pipex(t_pipex *px);

#endif