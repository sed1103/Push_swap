/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:28:04 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:28:05 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

long long	result(char *str, int i, char sign)
{
	long long	n;

	n = 0;
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
		{
			n = n * 10 + str[i] - '0';
			i++;
		}
		if (sign == '-')
			n = -1 * n;
		return (n);
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	int		i;
	char	sign;

	sign = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
	{
		sign = '+';
		i++;
	}
	else if (str[i] == '-')
	{
		sign = '-';
		i++;
	}
	return (result((char *)str, i, sign));
}
