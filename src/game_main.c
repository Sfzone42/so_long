/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:53:20 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 09:53:26 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	init_data(t_data *data, char *filename)
{
	int	i;

	data->str = NULL;
	data->matriz = NULL;
	open_map(filename, data);
	if (!data->str)
		fechar_mapa("Erro: mapa invalido\n");
	if (!check_bord(data))
		fechar_mapa("Erro: mapa invalido\n");
	else if (validate_matrix(data->matriz, &i, &i) == -1)
		fechar_mapa("Erro: mapa invalido\n");
	else if (c_line(data->matriz) > 25 || c_cols(data->matriz) >= 49)
		fechar_mapa("Mapa muito grande\n");
	bloquear_caminho(data, 'C', 0, 0);
	bloquear_caminho(data, 'E', 0, 0);
}

void	load_textures(t_data *data)
{
	data->player = mlx_xpm_file_to_image(data->root, "./textura/player.xpm",
			&(int){0}, &(int){0});
	data->player2 = mlx_xpm_file_to_image(data->root, "./textura/player2.xpm",
			&(int){0}, &(int){0});
	data->collect = mlx_xpm_file_to_image(data->root, "./textura/collect.xpm",
			&(int){0}, &(int){0});
	data->fundo = mlx_xpm_file_to_image(data->root, "./textura/spece.xpm",
			&(int){0}, &(int){0});
	data->parede = mlx_xpm_file_to_image(data->root, "./textura/wall.xpm",
			&(int){0}, &data->ligax);
	data->exit = mlx_xpm_file_to_image(data->root, "./textura/exit.xpm",
			&(int){0}, &(int){0});
	check_and_exit(data, "Erro ao carregar as imagens...\n");
}

void	setup_mlx(t_data *data)
{
	int	lar;
	int	alt;

	lar = c_cols(data->matriz) * data->ligax;
	alt = c_line(data->matriz) * data->ligax;
	data->step = 0;
	data->dir = 1;
	data->window = mlx_new_window(data->root, lar, alt, "So_long");
	init_window_game(data);
	mlx_hook(data->window, 2, 1L << 0, move_player, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_loop(data->root);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		init_data(&data, av[1]);
		data.root = mlx_init();
		load_textures(&data);
		setup_mlx(&data);
	}
	else
		fechar_mapa("./so_long <map.ber>\n");
	return (0);
}
