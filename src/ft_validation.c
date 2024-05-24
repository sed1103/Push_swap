/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:33:36 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:35:22 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	ft_countdigit(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		count++;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	if (count > 11)
		exit(!write(2, "Error\n", 6));
}

void	check_null(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		if (ft_strlen(str[i]) == 0)
			exit(!write(2, "Error\n", 6));
		while (ft_isspace(str[i][j]))
		{
			j++;
		}
		if (str[i][j] == '\0')
			exit(!write(2, "Error\n", 6));
		i++;
	}
}

void	ft_check_sign(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' || str[i][j] == '+')
				&& (str[i][j + 1] < '0' || str[i][j + 1] > '9'))
				exit(!write(2, "Error\n", 6));
			if ((str[i][j] >= '0' && str[i][j] <= '9')
				&& (str[i][j + 1] == '-' || str[i][j + 1] == '+'))
				exit(!write(2, "Error\n", 6));
			j++;
		}
		ft_countdigit(str[i++]);
	}
}

void	ft_validation(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	check_null(argv);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& (argv[i][j] != '-') && (argv[i][j] != '+')
				&& !ft_isspace(argv[i][j]))
				exit(!write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	ft_check_sign(argv);
}
