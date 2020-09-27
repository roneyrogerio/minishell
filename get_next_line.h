/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:09:46 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/09/27 09:25:10 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef	struct	s_pseudo_fd
{
# if BUFFER_SIZE > 0

	char	buf[BUFFER_SIZE];
# endif
# if BUFFER_SIZE <= 0

	char	buf[0];
# endif

	int		size;
	int		offset;
	t_list	*line_liststart;
	t_list	*line_listlast;
	int		list_hasline;
	int		list_linelen;
	int		i;
}				t_pseudo_fd;

int				get_next_line(int fd, char **line);

#endif
