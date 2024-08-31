/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:09:52 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 19:09:55 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		if (n == -2147483648)
		{
			write(STDOUT_FILENO, "2", 1);
			n = -147483648;
		}
		else
			n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(STDOUT_FILENO, &c, 1);
}

void	ft_plus_step(t_data *data)
{
	data->step++;
	write(STDOUT_FILENO, "PASSOS: [ ", 10);
	ft_putnbr(data->step);
	write(STDOUT_FILENO, " ]\n", 3);
}
