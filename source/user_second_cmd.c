/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** user_second_cmd
*/

#include "../include/server.h"

int is_connected(m_ftp_t *m_serv, int sd)
{
    if (m_serv->pwd == NULL) {
        write(sd, "530 Error: Not logged in.\n", 26);
        return -1;
    }
    return 0;
}
