#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
int             get_next_line(int fd, char **line);

#endif
