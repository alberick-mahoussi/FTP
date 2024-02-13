/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** using_fonction
*/

#include "../include/server.h"

void add_sock_connect(m_ftp_t *m_serv)
{
    for (int i = 0; i < 15; i++) {
        if (m_serv->client_sock[i] == 0 ) {
            m_serv->client_sock[i] = m_serv->scket_client;
            break;
        }
    }
}

void read_info_client(m_ftp_t *m_serv, fd_set reads, int sd)
{
    int valread;
    int i = 0;
    for (i = 0; i < 15; i++) {
        sd = m_serv->client_sock[i];
        if (FD_ISSET(sd, &reads)) {
            valread = read(sd, m_serv->buffer, 1024);
            read_client;
            table_command(m_serv, sd, i);
        }
    }
}

void free_double_array(char **cmd)
{
    for (int u = 0; cmd[u] != NULL; u++)
        free(cmd[u]);
    free(cmd);
}
