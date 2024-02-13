/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** connection client and server
*/

#include "../include/server.h"

void usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("      port  is the port number on which");
    printf("the server socket listens\n");
    printf("      path  is the path to the home");
    printf("directory for the Anonymous user\n");
}

int main(int ac, char **av)
{
    if (ac > 3 || ac < 3) {
        if (ac == 2 && strcmp(av[1], "-h") == 0) {
            usage();
        } else {
            printf("Bad argument\n");
            return 84;
        }
    } else {
        if (connection(atoi(av[1]), av[2]) == 84);
            return 84;
    }
    return 0;
}
