/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:34:23 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/03 15:28:20 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		error_flag(char c)
{
	ft_putstr("/ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\n");
	ft_putstr("usage: ./ft_ls [-1lRarts] [file ...]\n");
	exit(0);
}

static void		flags(char c, t_env *env)
{
	char const	*flags = "-1lRarts";
	int			test;

	test = 0;
	while (*flags != '\0' && test != 1)
	{
		if (c == *flags)
		{
			env->flag[(int)c] = 1;
			test = 1;
		}
		flags++;
	}
	if (test == 0)
		error_flag(c);
}

void			get_flags_args(int ac, char **av, t_env *env)
{
	int		i;
	int		j;
	int		test;

	test = 0;
	i = 1;
	ft_bzero(env->flag, sizeof(256));
	while (i < ac && av[i][0] == '-'
			&& ft_strlen(av[i]) > 1 && env->flag['-'] == 0)
	{
		j = 1;
		if (av[i][0] == '-' && av[i][1] == '-' && ft_strlen(av[i]) > 2)
			error_flag('-');
		while (av[i][j] != '\0' && env->flag['-'] == 0)
		{
			if (av[i][j] == '-' && j > 1)
				error_flag('-');
			flags(av[i][j], env);
			j++;
		}
		i++;
	}
	env->nbr_args = ac - i;
}
