/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:37:30 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 16:37:32 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	push_z(t_mlx **data, char **z, int j)
{
	int	i;
	int	k;

	i = 0;
	while (i < (*data)->x)
	{
		k = 0;
		(*data)->arr[j][i] = ft_atoi(z[i]);
		if (strchr(z[i], ','))
		{
			while (z[i][k] != ',')
				k++;
			if (z[i][k] == ',')
				k++;
			(*data)->color[j][i] = ft_strtol((char *)(z[i] + k), 16);
		}
		else
			(*data)->color[j][i] = 0xFFFFFF;
		i++;
	}
}

static void	fill_matrix(t_mlx *data, char *file)
{
	int		fd;
	char	*line;
	char	**z;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		z = ft_split(line, ' ');
		free(line);
		push_z(&data, z, i);
		i++;
		ft_free(z);
	}
}

static void	allocate_color(t_mlx *data)
{
	int	i;

	i = 0;
	data->color = (long **)(malloc(sizeof(long *) * (data->y + 1)));
	if (data->color == NULL)
	{
		free_matrix(&data);
		free(data->mlx_ptr);
		ft_error_exit("Error allocating memory");
	}
	while (i < data->y)
	{
		data->color[i] = (long *)malloc(sizeof(long) * (data->x + 1));
		if (data->color[i] == NULL)
		{
			free(data->mlx_ptr);
			free_matrix(&data);
			free_color(&data);
			ft_error_exit("Error allocating memory");
		}
		i++;
	}
	data->color[i] = NULL;
}

static void	allocate_matrix(t_mlx *data, char *file)
{
	int	i;

	i = 0;
	data->arr = (int **)(malloc(sizeof(int *) * (data->y + 1)));
	if (data->arr == NULL)
	{
		free(data->mlx_ptr);
		ft_error_exit("Error allocating memory");
	}
	while (i < data->y)
	{
		data->arr[i] = (int *)malloc(sizeof(int) * (data->x + 1));
		if (data->arr[i] == NULL)
		{
			free(data->mlx_ptr);
			free_matrix(&data);
			ft_error_exit("Error allocating memory");
		}
		i++;
	}
	data->arr[i] = NULL;
	allocate_color(data);
	fill_matrix(data, file);
}

void	init_matrix(t_mlx *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	data->y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (data->y == 0)
			data->x = get_x(line);
		data->y++;
		free(line);
	}
	close(fd);
	allocate_matrix(data, file);
}
