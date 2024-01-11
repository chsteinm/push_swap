#include <stdlib.h>
#include <stdio.h>

int is_here(char c, const char *s)
{
    while (*s)
        if (*s++ == c)
            return (1);
    return (0);
}

int count_w(char *s)
{
    int w = 0;
    int set = 1;
    while (*s)
    {
        if (is_here(*s, " \n\t"))
            set = 1;
        else if (set)
        {
            w++;
            set = 0;
        }
        s++;
    }
    return (w);
}

char    **ft_split(char *str)
{
    char **strs = NULL;
    int w = count_w(str);
    strs = malloc(sizeof(char *) * w + 1);
    int len;
    int i;
    int j = -1;
    while (++j < w)
    {
        while (is_here(*str, " \n\t"))
            str++;
        len = 0;
        while (str[len] && !is_here(str[len], " \n\t"))
            len++;
        strs[j] = malloc(len + 1);
        strs[j][len + 1] = 0;
        i = -1;
        while (++i < len)
            strs[j][i] = str[i];
        str += len + 1;
    }
    strs[j] = 0;
    return (strs);
}

// int main(int c, char **v){
//     int j = -1;
//     char **ss = ft_split(v[c-1]);
//     while (ss[++j])
//         printf("%s\n", ss[j]);}