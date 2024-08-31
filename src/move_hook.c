/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:05:23 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 11:05:25 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	close_window(t_data *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->window)
		mlx_destroy_window(data->root, data->window);
	if (data->root)
		mlx_destroy_display(data->root);
	exit(0);
	return (0);
}

void	find_player(t_data *data, int move, int j)
{
	int	i;

	i = -1;
	while (data->matriz[++i])
	{
		j = -1;
		while (data->matriz[i][++j])
		{
			if (data->matriz[i][j] == 'P' &&
					data->matriz[i][j + move] != '1')
			{
				if (data->matriz[i][j + move] != 'E')
				{
					data->matriz[i][j] = '0';
					ft_plus_step(data);
					data->matriz[i][j + move] = 'P';
					return ;
				}
				else if (find_collect(data) == 0)
					if (data->matriz[i][j + move] == 'E')
						fechar_mapa("Venceu o Jogo\n");
			}
		}
	}
}

void	find_playery(t_data *data, int move, int j)
{
	int	i;

	i = -1;
	while (data->matriz[++i])
	{
		j = -1;
		while (data->matriz[i][++j])
		{
			if (data->matriz[i][j] == 'P' &&
					data->matriz[i + move][j] != '1')
			{
				if (data->matriz[i + move][j] != 'E')
				{
					data->matriz[i][j] = '0';
					ft_plus_step(data);
					data->matriz[i + move][j] = 'P';
					return ;
				}
				else if (find_collect(data) == 0)
					if (data->matriz[i + move][j] == 'E')
						fechar_mapa("Venceu o Jogo\n");
			}
		}
	}
}

int	move_player(int key, t_data *ptr)
{
	(void)ptr;
	if (key == ESC)
		close_window(ptr);
	if (key == RIGHT || key == RIGHT_D)
	{
		ptr->dir = 1;
		find_player(ptr, 1, 0);
	}
	else if (key == UP || key == UP_W)
		find_playery(ptr, -1, 0);
	else if (key == LEFT || key == LEFT_A)
	{
		ptr->dir = -1;
		find_player(ptr, -1, 0);
	}
	else if (key == DOWN || key == DOWN_S)
		find_playery(ptr, 1, 0);
	init_window_game(ptr);
	return (0);
}
