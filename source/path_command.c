/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** path_command
*/

#include "../include/server.h"

void pwd(m_ftp_t *m_serv, int sd)
{
    char cwd[1024];
    char path[1024];

    if (is_connected(m_serv, sd) != -1) {
        chdir(".");
        getcwd(cwd, sizeof(cwd));
        if (cwd == NULL) {
            write(sd, "550 Error: pwd.\n", 15);
        } else {
            sprintf(path, "257 %s created.\n", cwd);
            write(sd, path, strlen(path));
        }
    }
}

void cwd(m_ftp_t *m_serv, int sd)
{
    if (is_connected(m_serv, sd) != -1) {
        if (m_serv->path == NULL)
            write(sd, "550 Error: no path.\n", 20);
        else {
            chdir(m_serv->path) == -1 ? acces_path_dn : acces_path;
        }
    }
}
