/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:43:26 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/29 06:25:34 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

	t_pipex	*init_pipex(char **argv, char **envp)
	{
		t_pipex	*px;

		px = malloc(sizeof(t_pipex));
		if (!px)
			return (NULL);
		px->cmd1 = ft_split(argv[2], ' ');
		px->cmd2 = ft_split(argv[3], ' ');
		px->envp = envp;
		px->in_file = argv[1];
		px->out_file = argv[4];
		return (px);
	}
