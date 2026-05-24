/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:39:08 by rfoo              #+#    #+#             */
/*   Updated: 2026/05/24 15:15:06 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **argv, char **envp)
{
	char	*in_file;
	char	**cmd1;
	char	*out_file;
	char	**cmd2;

	in_file = argv[1];
	cmd1 = ft_split(argv[2], ' ');
	out_file = argv[4];
	cmd2 = ft_split(argv[3], ' ');

	return (0);
}
