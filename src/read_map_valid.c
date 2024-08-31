/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:57:24 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/07/20 09:57:25 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] == '\n')
		i++;
	split = malloc(sizeof(char *) * 800);
	while (str[i] != '\0')
	{
		k = 0;
		split[j] = malloc(sizeof(char *) * 1024);
		while (str[i] != '\n' && str[i] != '\0')
			split[j][k++] = str[i++];
		split[j][k] = '\0';
		while (str[i] == '\n')
			i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}

int	check_bord(t_data *ptr)
{
	int	i;
	int	j;

	ptr->matriz = ft_split(ptr->str);
	if (!ptr->matriz)
		return (0);
	i = -1;
	j = -1;
	while (ptr->matriz[0][++i])
		if (ptr->matriz[0][i] != '1')
			return (0);
	while (ptr->matriz[++j])
		if (ptr->matriz[j][0] != '1')
			return (0);
	i = -1;
	while (ptr->matriz[j - 1][++i])
		if (ptr->matriz[j - 1][i] != '1')
			return (0);
	i--;
	while (--j)
		if (ptr->matriz[j - 1][i] != '1')
			return (0);
	return (1);
}

void	open_map(char *s, t_data *data)
{
	int		i;
	int		fd;
	char	buffer[2024];

	fd = open(s, 0);
	if (fd < 0)
		return ;
	i = -1;
	while (s[++i])
		if (s[i] == '.' && !(s[i + 1] == 'b' && s[i + 2] == 'e'
				&& s[i + 3] == 'r' && s[i + 4] == '\0'))
			return ;
	i = -1;
	while (++i <= 2024)
		buffer[i] = '\0';
	i = 1;
	i = read(fd, buffer, 2024);
	if (i == -1 || i == 0)
		return ;
	buffer[i] = '\0';
	f_veri_elems(buffer);
	elems_num_validate(buffer, -1, 0);
	data->str = buffer;
}

void	check_and_exit(t_data *data, char *message)
{
	if (data->player == NULL)
		fechar_mapa(message);
	if (data->player2 == NULL)
		fechar_mapa(message);
	if (data->collect == NULL)
		fechar_mapa(message);
	if (data->parede == NULL)
		fechar_mapa(message);
	if (data->exit == NULL)
		fechar_mapa(message);
	if (data->fundo == NULL)
		fechar_mapa(NULL);
}
