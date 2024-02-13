/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** etablished connection beetween socket and server
*/

#include "../include/server.h"

void init_info(m_ftp_t *m_serv, char *ip)
{
    init_clien_data;
}

void init_socket(fd_set *reads, m_ftp_t *m_serv, int max_sd)
{
    int sd;
    FD_ZERO(reads);
    FD_SET(m_serv->scket, reads);
    max_sd = m_serv->scket;
    m_serv->max_client = 15;
    for (int i = 0; i < m_serv->max_client; i++) {
            sd = m_serv->client_sock[i];
            sd > 0 ? FD_SET(sd, reads) : 0;
            sd > max_sd ? max_sd = sd : 0;
    }
    if (select(max_sd + 1, reads, NULL, NULL, NULL) < 0) {
        perror("select error");
        exit (84);
    }
}

m_ftp_t *conf_server(m_ftp_t *sock_serv)
{
    protocol_struct;
    sock_define;
    for (int i = 0; i < 15; i++)  sock_serv->client_sock[i] = 0;
    if (sock_serv->scket == -1) {
        perror("socket Fail");
        return (NULL);
    }
    sockaddr_define;
    if (bind(sock_serv->scket, (struct sockaddr *)&sock_serv->m_address,
    sizeof(sock_serv->m_address)) < 0) {
        perror("bind Fail");
        return (NULL);
    }
    if (listen(sock_serv->scket, 3) < 0) {
        close(sock_serv->scket);
        return (NULL);
    }
    return sock_serv;
}

int estable_connection(m_ftp_t *m_serv)
{
    int max_sd;
    fd_set reads;
    int sd;
    struct sockaddr_in client_mp;
    socklen_t mp_size = sizeof(client_mp);
    while (1) {
        init_socket(&reads, m_serv, max_sd);
        if (FD_ISSET(m_serv->scket, &reads)) {
            test_accept;
            m_serv->scket_client != -1 ? accep_condition :\
            printf("Connection error!\n");
        } else read_info_client(m_serv, reads, sd);
    }
    close(m_serv->scket);
    return 0;
}

int connection(int port, char *path)
{
    m_ftp_t *m_serv = malloc(sizeof(m_ftp_t));
    if (chdir(path) < 0) {
        perror("path don't exist or empty");
        return 84;
    }
    m_serv->port = port;
    m_serv->path = path;
    m_serv = conf_server(m_serv);
    if (m_serv == NULL) {
        perror("confirugation server Fail");
        return 84;
    }
    estable_connection(m_serv);
    close(m_serv->scket);
    return 0;
}
