/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:23:59 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/13 18:25:42 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_check_hex(char *hex)
{
	int	size;
	int	i;

	size = ft_strlen(hex);
	i = 2;
	if (size > 2 && hex[0] == '0' && hex[1] == 'x')
	{
		while (hex[i] && (hex[i] != '\n' || hex[i] != ' '))
		{
			if (hex[i] == '\n')
				break ;
			if (!ft_isxdigit(hex[i]))
				return (-1);
			i++;
		}
	}
	else
		return (-1);
	return (0);
}

static int	ft_check_num(char *str, long is_neg)
{
	int		i;
	long	res;

	i = 0;
	if (str[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (str[i] == ',' && str[i + 1] != '\0')
	{
		if (ft_check_hex(str + i + 1) == -1)
			return (-1);
	}
	else if (ft_isprint(str[i]))
		return (-1);
	if (res * is_neg < -2147483648 || res * is_neg > 2147483647)
		return (-1);
	return (0);
}

static int	ft_check_line(char *line, int x)
{
	char	**nums;
	int		i;
	long	sign;

	nums = ft_split(line, ' ');
	i = 0;
	sign = 1;
	while (nums[i] != NULL)
	{
		if (ft_check_num(nums[i], sign) == -1)
		{
			ft_free(nums);
			return (-1);
		}
		i++;
	}
	ft_free(nums);
	if (i > x || i < x)
		return (-1);
	return (0);
}

static int	ft_init_check(int fd)
{
	static int	x;
	char		*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!x)
			x = get_x(line);
		if (line == NULL)
			break ;
		if (ft_check_line(line, x) == -1)
		{
			free(line);
			while (1)
			{
				line = get_next_line(fd);
				if (line == NULL)
					break ;
				free(line);
			}
			return (-1);
		}
		free(line);
	}
	return (0);
}

void	ft_check_input(char *file)
{
	int	i;
	int	fd;

	i = ft_strlen(file);
	if (i > 4 && (file[i - 1] != 'f' || file[i - 2] != 'd' \
		|| file[i - 3] != 'f' || file[i - 4] != '.'))
		ft_error_exit("Invalid file format\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_exit("File isn't exist\n");
	if (read(fd, 0, 0) < 0)
	{
		close (fd);
		ft_error_exit("File isn't readable\n");
	}
	if (ft_init_check(fd) == -1)
	{
		close (fd);
		ft_error_exit("Invalid nums or nums in a line occured");
	}
	close (fd);
}
