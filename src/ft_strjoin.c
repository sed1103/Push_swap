/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:31:26 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:32:36 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		str = (char *)malloc((ft_strlen(s1)
					+ ft_strlen(s2) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[i - ft_strlen(s1)] != '\0')
		{
			str[i] = s2[i - ft_strlen(s1)];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
