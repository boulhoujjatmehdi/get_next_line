/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:53:04 by eboulhou          #+#    #+#             */
/*   Updated: 2022/11/04 20:31:42 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char	*ft_strjoin(char *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*str;
	
	if (!s1)
	{
		s1 = malloc(1);
		*s1 = 0;
	}
	size1 = strlen(s1);
	size2 = strlen(s2);
	str = (char *)malloc(size1 + size2 + 1);
	if (!str)
		return (0);
	strlcpy(str, s1, size1 + 1);
	strlcat(str + size1, s2, size2 + 1);
	free(s1);
	return (str);
}
int found_back_n(char *str)
{
	int i;
	
	i = 0;
	if(!str)
		return 0;
	while(str[i] && str[i] != 10)
		i++;
	if(str[i] == 10)
		return 1;
	return 0;
}

char ft_get_line(char *temp)
{
	char *line;
	int i = 0;
	while (temp[i] !)// this is where we start tomorrow
}
char *read_function(int fd)
{
	char *temp;
	char buff[BUFFER_SIZE + 1];
	int rd;

	rd = 1;
	while(rd && !found_back_n(temp))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if(rd == -1)
			return NULL;
		temp = ft_strjoin(temp, buff);
	}
	return temp;
}
char *get_next_line(int fd)
{
	char static stat[BUFFER_SIZE + 1];
	char *temp;
	char *line;

	temp = NULL;
	temp = read_function(fd);
	line = ft_get_line(temp);
	puts(temp);
	// temp = NULL;
	return NULL;
}


int main ()
{
	int fd  = open ("file.txt" , O_RDONLY);
	get_next_line(fd);
	
}












// void get_static(char *stat, char *temp)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	j = 
// 	stat[0] = 0;
// 	while(temp[i] && temp[i] != '\n')
// 	{
// 		i++;
// 	}
// 	if (!temp[i])
// 		return ;
// 	if (temp[i] == '\n')
// 		i++;
// 	while(temp[i + j])
// 	{
// 		stat[j] = temp[i+j];
// 		j++;
// 	}
// 	stat[j] = 0;
// }

// int		isendline(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i++] == '\n')
// 			return (1);
// 	}
// 	return (0);
// }

// char	*reading_func(int fd, char *temp)
// {
// 	char	buff[BUFFER_SIZE + 1];
// 	int		j;
// 	int		rd;

// 	rd = 1;
// 	while(!isendline(temp) && rd)
// 	{
// 		j = 0;
// 		while (j < BUFFER_SIZE + 1)
// 			buff[j++] = 0;
// 		rd = read(fd, buff, BUFFER_SIZE);
// 		if (rd == -1 || (rd == 0 && !temp))
// 			return (NULL);
// 		buff[rd] = 0;
// 		temp = ft_strjoin(temp, buff);
// 		if (!temp)
// 			return (NULL);
// 	}
// 	return (temp);
// }

// char	*ft_get_line(char *line, char *temp)
// {
// 	int len;

// 	len = 0;
// 	while (temp[len] && temp[len] != '\n')
// 		len++;
// 	if (temp[len] == '\n')
// 		len++;
// 	line = malloc(len + 1);
// 	len = 0;
// 	while (temp[len] && temp[len] != '\n')
// 	{
// 		line[len] = temp[len];
// 		len++;
// 	}
// 	if (temp[len] == '\n')
// 		line[len++] = '\n';
// 	line[len] = 0;
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	char static stat[BUFFER_SIZE + 1];
// 	char *temp;
// 	char *line;
	
// 	temp = NULL;
// 	line = NULL;
// 	if (*stat != 0)
// 		temp = ft_strjoin(temp, stat);
// 	//printf("temp:%s\n", temp);
// 	temp = reading_func(fd, temp);
// 	if (!temp)
// 		return (NULL);
// 	line = ft_get_line(line, temp);
// 	get_static(stat, temp);
// 	free(temp);
// 	return (line);
// }

// int main ()
// {
// 	int fd = open("file.txt" , O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	fd = open("file.txt" , O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// }
