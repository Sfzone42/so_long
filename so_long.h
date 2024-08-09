/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:07:14 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/14 03:07:17 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define UP_W 119
# define DOWN_S 115
# define LEFT_A 97
# define RIGHT_D 100

typedef struct s_data
{
	void	*root;
	void	*window;
	void	*player;
	void	*player2;
	void	*collect;
	void	*fundo;
	void	*parede;
	void	*exit;
	char	*file_name;
	char	*str;
	char	*buffer;
	char	**matriz;
	int		ncollect;
	int		ligax;
	int		x_pos_ply;
	int		y_pos_ply;
	int		fd;
	int		widith_matriz;
	int		height_matriz;
	int		dir;
	int		step;
}			t_data;

/* ft_utilz.c */
void		ft_plus_step(t_data *data);
void		free_textures(t_data *data);

/* read_map_valid.c */
char		**ft_split(char *str);
void		open_map(char *s, t_data *data);
void		check_and_exit(t_data *data, char *message);
int			check_bord(t_data *ptr);

/* vrific_map.c */
void		elems_num_validate(char *buffer, int i, int aux);
void		free_matrix(char **matriz, int rows);
void		f_veri_elems(char *buffer);
int			validate_matrix(char **matrix, int *lines, int *columns);

/* utils.c */
void		fechar_mapa(char *str);
int			c_line(char **matriz);
int			c_cols(char **matriz);
char		*ft_strdup(char *s1);

/* render_window.c */
void		put_image(t_data *data, void *image, int x, int y);
void		put_player_image(t_data *data, int x, int y);
void		handle_tile(t_data *data, char tile, int x, int y);
void		init_window_game(t_data *data);

/* true_way.c */
int			find_collect(t_data *data);
void		flood_fill(char **matriz, int x, int y, int *found);
char		**aux_matrix(char **matriz, int rows, int i);
void		bloquear_caminho(t_data *data, char c, int i, int j);

/* move_hook.c */
void		find_player(t_data *data, int move, int j);
void		find_playery(t_data *data, int move, int j);
int			close_window(t_data *ptr);
int			move_player(int key, t_data *ptr);

/* game_main.c */
void		init_data(t_data *data, char *filename);
void		load_textures(t_data *data);
void		setup_mlx(t_data *data);

#endif
