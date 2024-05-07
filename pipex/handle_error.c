/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:56:09 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/06 21:50:43 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(void **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
		}
		i++;
	}
	free(tab);
}

// void	free_triple(char ***big_array)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	if (big_array == NULL)
// 		return ;
// 	while (big_array[j])
// 	{
// 		i = 0;
// 		while (big_array[j][i])
// 		{
// 			free(big_array[j][i]);
// 			i++;
// 		}
// 		free(big_array[j]);
// 		j++;
// 	}
// 	free (big_array);
// }

void	free_and_exit(char *err_msg, t_cmd *cmd, int i)
{
	if (cmd->possible_paths)
		free_array((void **)cmd->possible_paths);
	if (cmd->command)
	{
		free_array((void **)cmd->command[0]);
		free_array((void **)cmd->command[1]);
		free(cmd->command);
	}
	if (i == 1)
		close_pipe(cmd);
	perror(err_msg);
	exit(errno);
}

void	free_all(t_cmd *cmd, int i)
{
	if (cmd->possible_paths)
		free_array((void **)cmd->possible_paths);
	if (cmd->command)
	{
		free_array((void **)cmd->command[0]);
		free_array((void **)cmd->command[1]);
		free(cmd->command);
	}
	if (i == 1)
		close_pipe(cmd);
	exit(errno);
}

void	close_pipe(t_cmd *cmd)
{
	if (close(cmd->pipe[0]) == -1)
	{
		close(cmd->pipe[1]);
		free_and_exit("Error closing fd in child", cmd, 0);
	}
	if (close(cmd->pipe[1]) == -1)
		free_and_exit("Error closing fd in child", cmd, 0);
}
