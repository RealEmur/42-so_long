/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:21:02 by emyildir          #+#    #+#             */
/*   Updated: 2023/12/18 21:23:44 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_initial_fdata(char **data)
{
	*data = (char *) malloc(sizeof(char));
	if (*data)
		**data = '\0';
	return (*data != 0);
}

static void	swap_str_and_free(char **str, char *newStr)
{
	free(*str);
	*str = newStr;
}

static char	*free_fdata(char	**fdata)
{
	if (*fdata)
	{
		free(*fdata);
		*fdata = 0;
	}
	return (0);
}

static char	*get_line(char *file_data)
{
	size_t	len;

	len = 0;
	while (file_data[len])
		if (file_data[len++] == '\n')
			break ;
	return (ft_substr(file_data, 0, len));
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		buffer[1024];
	char		*line;
	static char	*file_data[1024] = {0};

	if (fd < 0 || (!file_data[fd] && !set_initial_fdata(&file_data[fd])))
		return (0);
	while (file_data[fd] && !ft_strchr(file_data[fd], '\n'))
	{
		bytes_read = read(fd, buffer, 1024);
		if (bytes_read == 0 || bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		swap_str_and_free(&file_data[fd], ft_strjoin(file_data[fd], buffer));
	}
	if (!file_data[fd] || !*file_data[fd] || bytes_read == -1)
		return (free_fdata(&file_data[fd]));
	line = get_line(file_data[fd]);
	if (!line)
		return (free_fdata(&file_data[fd]));
	swap_str_and_free(&file_data[fd], \
	ft_substr(file_data[fd], ft_strlen(line), \
	ft_strlen(file_data[fd]) - ft_strlen(line)));
	return (line);
}
