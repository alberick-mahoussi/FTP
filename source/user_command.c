/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myftp-alberick.mahoussi
** File description:
** user_command
*/

#include "../include/server.h"

void user(m_ftp_t *m_serv, int sd, char *user)
{
    if (user == NULL) {
        write(sd, "530 Error: waiting login.\n", 26);
    } else {
        m_serv->user = strdup(user);
        write(sd, "331 User name okay, need password.\n", 35);
    }
}

void password(m_ftp_t *m_serv, int sd, char *pwd)
{
    if (m_serv->user == NULL) {
        write(sd, "530 Error: need login.\n", 23);
        return;
    }
    if (strcmp(m_serv->user, "Anonymous") == 0) {
        m_serv->pwd = "";
        write(sd, "230 User logged in, proceed.\n", 29);
    } else {
        if (pwd == NULL) {
            write(sd, "530 Error: waiting password.\n", 29);
            return;
        } else {
            m_serv->pwd = pwd;
            write(sd, "230 User logged in, proceed.\n", 29);
        }
    }
}

void quit(m_ftp_t *m_serv, int sd, int i)
{
    printf("Client disconnected\n");
    if (m_serv->pwd != NULL && m_serv->user != NULL)
        write(sd, "221 Logged out.\n", 16);
    else
        write(sd, "221 Service closing control connection.\n", 40);
    close(sd);
    m_serv->client_sock[i] = 0;

}

void noop(m_ftp_t *m_serv, int sd)
{
    if (is_connected(m_serv, sd) != -1)
        write(sd, "200 Command okay\n", 17);
}

void help(m_ftp_t *m_serv, int sd)
{
    if (is_connected(m_serv, sd) != -1)
        write(sd, "214 Help message.\n", 18);
}
