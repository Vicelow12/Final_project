/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:30:32 by ngaulthi          #+#    #+#             */
/*   Updated: 2023/11/22 17:07:29 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	result;
	long int	overunder_check;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		overunder_check = result;
		result = (result * 10) + (nptr[i++] - '0');
		if (overunder_check > result && sign > 0)
			return (-1);
		else if (overunder_check > result && sign < 0)
			return (0);
	}
	return ((int)(result * sign));
}
