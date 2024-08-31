/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:06:31 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 11:06:33 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	find_collect(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->matriz[++i])
	{
		j = -1;
		while (data->matriz[i][++j])
		{
			if (data->matriz[i][j] == 'C')
				return (1);
		}
	}
	return (0);
}

void	flood_fill(char **matriz, int x, int y, int *found)
{
	int	rows;
	int	cols;

	rows = c_line(matriz);
	cols = c_cols(matriz);
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return ;
	if (matriz[x][y] == 'P')
	{
		*found = 1;
		return ;
	}
	if (matriz[x][y] == '1' || matriz[x][y] == 'V')
		return ;
	matriz[x][y] = 'V';
	flood_fill(matriz, x + 1, y, found);
	flood_fill(matriz, x - 1, y, found);
	flood_fill(matriz, x, y + 1, found);
	flood_fill(matriz, x, y - 1, found);
}

char	**aux_matrix(char **matriz, int rows, int i)
{
	char	**matriz_aux;
	int		j;

	matriz_aux = (char **)malloc(rows * sizeof(char *));
	if (!matriz_aux)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matriz_aux[i] = ft_strdup(matriz[i]);
		if (!matriz_aux[i])
		{
			j = 0;
			while (j < i)
			{
				free(matriz_aux[j]);
				j++;
			}
			free(matriz_aux);
			return (NULL);
		}
		i++;
	}
	return (matriz_aux);
}

void	bloquear_caminho(t_data *data, char c, int i, int j)
{
	int		found;
	char	**matriz_aux;

	i = 0;
	while (i < c_line(data->matriz))
	{
		j = 0;
		while (j < c_cols(data->matriz))
		{
			if (data->matriz[i][j] == c)
			{
				matriz_aux = aux_matrix(data->matriz,
						c_line(data->matriz), 0);
				if (!matriz_aux)
					return ;
				found = 0;
				flood_fill(matriz_aux, i, j, &found);
				free_matrix(matriz_aux, c_line(data->matriz));
				if (!found)
					fechar_mapa("Mapa sem caminho válido\n");
			}
			j++;
		}
		i++;
	}
}
