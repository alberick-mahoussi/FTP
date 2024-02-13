/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** check_command
*/

#include "../include/server.h"

int check_command(char *cmd)
{
    char *all_cmd[] = {
    "USER", "PASS", "CWD", "CDUP",
    "PWD", "DELE", "PASV", "RETR",
    "NOOP", "HELP", "QUIT", NULL
    };
    int i = 0;

    for (i = 0; all_cmd[i] != NULL; i++) {
        if (strcmp(cmd, all_cmd[i]) == 0)
            return i;
    }
    return (-1);
}

void second_command(m_ftp_t *m_serv, int sd, int u)
{
    switch (u) {
    case 8:
        noop(m_serv, sd);
        break;
    case 9:
        help(m_serv, sd);
        break;
    case 4:
        pwd(m_serv, sd);
        break;
    case 2 :
        cwd(m_serv, sd);
        break;
    default:
        write(sd, "500 Error: non valid command.\n", 30);
        break;
    }
}

void table_command(m_ftp_t *m_serv, int sd, int u)
{
    char *str = m_serv->buffer;
    str[strlen(str) - 2] = '\0';
    char **cmd = my_str_to_word_array(str, ' ');
    int i = check_command(cmd[0]);
    switch (i) {
    case 0:
        user(m_serv, sd, cmd[1]);
        break;
    case 1:
        password(m_serv, sd, cmd[1]);
        break;
    case 10:
        quit(m_serv, sd, u);
        break;
    default:
        second_command(m_serv, sd, i);
        break;
    }
    free_double_array(cmd);
}
