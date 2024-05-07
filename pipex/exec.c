/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:50:12 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/06 22:29:17 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(t_cmd *cmd, char **envp, int *process_id, int i)
{
	int	file;

	(*process_id) = fork();
	if ((*process_id) == -1)
		free_and_exit("error forking", cmd, 1);
	if ((*process_id) == 0)
	{
		file = do_dup(cmd, i);
		if (close(file) == -1)
			free_and_exit("Error closing fd in child", cmd, 1);
		close_pipe(cmd);
		cmd->valid_path = find_valid_path(cmd, cmd->command[i]);
		if (cmd->valid_path)
			execve(cmd->valid_path, cmd->command[i], envp);
		free(cmd->valid_path);
		free_and_exit("Command not found/execve fail", cmd, 0);
	}
	return (0);
}

int	do_dup(t_cmd *cmd, int i)
{
	int	file;

	if (i == 0)
	{
		file = open(cmd->infile_fd, O_RDONLY);
		if (file == -1)
			free_and_exit("can't open file 1", cmd, 1);
		if (dup2(file, 0) == -1 || dup2(cmd->pipe[1], 1) == -1)
		{
			close (file);
			free_and_exit("Error duplicating file descriptor", cmd, 1);
		}
	}
	if (i == 1)
	{
		file = open(cmd->outfile_fd, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (!file)
			free_and_exit("can't open file 2", cmd, 1);
		if (dup2(cmd->pipe[0], 0) == -1 || dup2(file, 1) == -1)
		{
			close (file);
			free_and_exit("Error duplicating file descriptor", cmd, 1);
		}
	}
	return (file);
}
