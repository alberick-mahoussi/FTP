/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** connection server and client
*/

#ifndef FTP_H_
    #define FTP_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <stdlib.h>
    #include <netinet/in.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <string.h>
    #define protocol_struct (sock_serv->scket_protocol = getprotobyname("TCP"))
    #define sock_define (sock_serv->scket = socket(AF_INET, SOCK_STREAM, \
    sock_serv->scket_protocol->p_proto))
    #define sockaddr_define (sock_serv->m_address.sin_family = AF_INET, \
    sock_serv->m_address.sin_addr.s_addr = INADDR_ANY, \
    sock_serv->m_address.sin_port = htons(sock_serv->port))
    #define test_accept (m_serv->scket_client = accept(m_serv->scket, \
    (struct sockaddr *)&client_mp, (socklen_t *)&mp_size))
    #define init_clien_data (m_serv->pasv_ = 0, m_serv->pasv_port = -2,  \
    m_serv->pasv_fd = -1, m_serv->scket = m_serv->scket_client,    \
    m_serv->ip = ip, m_serv->quit = false, \
    m_serv->user = NULL, m_serv->pwd = NULL, \
    m_serv->quit_bool = 0, m_serv->var_log = -2, \
    m_serv->tab_cmd = 0)
    #define deconnected (getpeername(sd, (struct sockaddr *)&m_serv->scket, \
    (socklen_t *)&m_serv->scket), \
    printf("Host disconnected, ip %s, port %d\n", \
    inet_ntoa(m_serv->m_address.sin_addr), ntohs(m_serv->m_address.sin_port)), \
    close( sd ), m_serv->client_sock[i] = 0)
    #define read_client (m_serv->buffer[valread] = '\0', \
    printf("Client Said:: %s", m_serv->buffer))
    #define accep_condition (write(m_serv->scket_client, \
    "220 Service ready for new user.\n", 32), \
    printf("Connection from %s:%d\n", inet_ntoa(client_mp.sin_addr), \
    ntohs(client_mp.sin_port)), add_sock_connect(m_serv))
    #define acces_path_dn (write(sd, "550 Error: path doesn't exist.\n", 31))
    #define acces_path (write(sd, "250 Requested file action okay.\n", 32))

typedef struct server_ftp {
    int port;
    char *path;
    int scket;
    struct protoent *scket_protocol;
    int scket_client;
    struct sockaddr_in m_address;
    socklen_t size_m_address;
    char *ip;
    char *user;
    char *pwd;
    bool quit;
    int client_sock[15];
    int max_client;
    int quit_bool;
    int pasv_port;
    int pasv_;
    int var_log;
    int pasv_fd;
    int tab_cmd;
    char buffer[1025];
}m_ftp_t;

int connection(int port, char *path);
void add_sock_connect(m_ftp_t *m_serv);
void read_info_client(m_ftp_t *m_serv, fd_set reads, int sd);
char **my_str_to_word_array(char *str, char f);
void user(m_ftp_t *m_serv, int sd, char *log);
void password(m_ftp_t *m_serv, int sd, char *pwd);
void quit(m_ftp_t *m_serv, int sd, int i);
void table_command(m_ftp_t *m_serv, int sd, int i);
int is_connected(m_ftp_t *m_serv, int sd);
void free_double_array(char **cmd);
void noop(m_ftp_t *m_serv, int sd);
void help(m_ftp_t *m_serv, int sd);
void pwd(m_ftp_t *m_serv, int sd);
void cwd(m_ftp_t *m_serv, int sd);
#endif /* !ftp */
