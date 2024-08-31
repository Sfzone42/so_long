/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:44:53 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 10:44:55 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	put_image(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->root, data->window,
		image, x * data->ligax, y * data->ligax);
}

void	put_player_image(t_data *data, int x, int y)
{
	if (data->dir == 1)
		put_image(data, data->player, x, y);
	else
		put_image(data, data->player2, x, y);
}

void	handle_tile(t_data *data, char tile, int x, int y)
{
	if (tile == '1')
		put_image(data, data->parede, x, y);
	else if (tile == '0')
		put_image(data, data->fundo, x, y);
	else if (tile == 'P')
		put_player_image(data, x, y);
	else if (tile == 'E')
		put_image(data, data->exit, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(data->root, data->window,
			data->collect, x * data->ligax, y * data->ligax);
}

void	init_window_game(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->matriz[i])
	{
		j = 0;
		while (data->matriz[i][j])
		{
			handle_tile(data, data->matriz[i][j], j, i);
			j++;
		}
		i++;
	}
}
