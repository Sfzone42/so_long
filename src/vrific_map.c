/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrific_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:33:50 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 10:33:52 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	validate_matrix(char **matrix, int *lines, int *columns)
{
	int	i;
	int	curr_columns;

	*lines = 0;
	*columns = 0;
	if (!matrix)
		return (-1);
	while (matrix[*lines])
	{
		curr_columns = 0;
		i = -1;
		while (matrix[*lines][++i])
			curr_columns++;
		if (*lines == 0)
			*columns = curr_columns;
		else if (curr_columns != *columns)
			return (-1);
		(*lines)++;
	}
	return (0);
}

void	f_veri_elems(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != 'E')
		{
			if (buffer[i] != 'C' && buffer[i] != 'P'
				&& buffer[i] != '\0' && buffer[i] != '\n')
				fechar_mapa("Elementos inválidos\n");
		}
		i++;
	}
}

void	free_matrix(char **matriz, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	elems_num_validate(char *buffer, int i, int aux)
{
	while (buffer[++i])
		if (buffer[i] == 'E')
			aux++;
	if (aux != 1)
		fechar_mapa("Número de elementos inválidos\n");
	while (buffer[++i])
		if (buffer[i] == 'P')
			aux++;
	if (aux != 1)
		fechar_mapa("Número de elementos inválidos\n");
	i = -1;
	aux = 0;
	while (buffer[++i])
		if (buffer[i] == 'C')
			aux++;
	if (aux < 1)
		fechar_mapa("Número de elementos inválidos\n");
}
