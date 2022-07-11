/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:13:57 by raweber           #+#    #+#             */
/*   Updated: 2022/07/09 15:58:08 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_home_path(char **envp)
{
	char	*home_path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "HOME=", 5))
		i++;
	if (ft_strnstr(envp[i], "HOME=", 5))
		home_path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	else
		home_path = NULL;
	return (home_path);
}

void	update_env(t_cmd_struct *cmd_struct, char *new_pwd_path, char *old_pwd_path)
{
	int	i;

	i = 0;
	while (!ft_strnstr(cmd_struct->env_clone[i], "PWD=", 4))
		i++;
	if (ft_strnstr(cmd_struct->env_clone[i], "PWD=", 4))
	{
		free(cmd_struct->env_clone[i]);
		cmd_struct->env_clone[i] = ft_strjoin("PWD=", new_pwd_path);
	}
	else
		ms_error("No PWD in env!", cmd_struct);
	i = 0;
	while (!ft_strnstr(cmd_struct->env_clone[i], "OLDPWD=", 7))
		i++;
	if (ft_strnstr(cmd_struct->env_clone[i], "OLDPWD=", 7))
	{
		free(cmd_struct->env_clone[i]);
		cmd_struct->env_clone[i] = ft_strjoin("OLDPWD=", old_pwd_path);
	}
	else
		ms_error("No OLDPWD in env!", cmd_struct);
}

void	builtin_cd(t_cmd_struct *cmd_struct)
{
	char	*old_path_ptr;
	char	*new_path_ptr;
	char	*home_path;
	
	old_path_ptr = getcwd(NULL, 0);
	home_path = NULL;
	//ft_printf("before cd dir: %s\n", path_ptr);
	if (!cmd_struct->command_splitted[1])
	{
		// run cd without arguments
		home_path = get_home_path(cmd_struct->env_clone);
		//printf("home path: %s\n", home_path);
		if (chdir(home_path))
		{
			ft_printf("error in home path cd\n");
			return ; // >>> Error handling here!
		}
		free(home_path);
	}
	else if (chdir(cmd_struct->command_splitted[1]))
	{
		ft_printf("error in cd argument\n");
		return ; // >>> Error handling here!
	}
	new_path_ptr = getcwd(NULL, 0);
	//ft_printf("after cd dir: %s\n", new_path_ptr);
	update_env(cmd_struct, new_path_ptr, old_path_ptr); // check if this works properly!
	free(old_path_ptr);
	free(new_path_ptr);
}

// int main(int argc, char **argv, char **envp)
// {
// 	t_cmd_struct *cmd_struct;
// 	cmd_struct =  malloc(sizeof(t_cmd_struct));
// 	cmd_struct->command_splitted =  malloc(2 * sizeof(char *));
// 	cmd_struct->command_splitted[0] = "cd";
// 	cmd_struct->command_splitted[1] = "/etc"; // make sure this is NULL, not a empty string!
// 	cmd_struct->env_clone = copy_env(envp);
// 	builtin_cd(cmd_struct);
	
// 	//-----printf ENV ----//
// 	int i = 0;
// 	while (cmd_struct->env_clone[i])
// 		printf("%s\n", cmd_struct->env_clone[i++]);
	
// 	//------------------- //
	
// 	return (0);
// }