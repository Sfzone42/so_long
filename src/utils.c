/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:45:40 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 09:45:41 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	c_line(char **matriz)
{
	int	line;

	line = 0;
	while (matriz[line])
		line++;
	return (line);
}

void	fechar_mapa(char *str)
{
	while (*str)
		write(1, str++, 1);
	exit(0);
}

int	c_cols(char **matriz)
{
	int	column;

	column = 0;
	while (matriz[0][column])
		column++;
	return (column);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
