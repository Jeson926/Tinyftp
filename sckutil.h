#ifndef _SCK_UTIL_H_
#define _SCK_UTIL_H_

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <time.h>

#include <netdb.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define ERR_EXIT(m) \
  do \
  { \
    perror(m); \
	exit(EXIT_FAILURE); \
  } \
  while (0)

	  
#define MAX_COMMAND_LINE 1024
#define MAX_COMMAND      32
#define MAX_ARG			 1024

int getlocalip(char *ip);	  

int tcp_client(const char *address, unsigned short port);

int activate_nonblock(int fd);
int deactivate_nonblock(int fd);

int read_timeout(int fd, unsigned int wait_seconds);
int write_timeout(int fd, unsigned int wait_seconds);
int accept_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);


ssize_t readn(int fd, void *buf, size_t count);
ssize_t writen(int fd, const void *buf, size_t count);
ssize_t recv_peek(int sockfd, void *buf, size_t len);
ssize_t readline(int sockfd, void *buf, size_t maxline);

void send_fd(int sock_fd, int fd_to_send);
int recv_fd(const int sock_fd);

/*获取权限位信息*/
const char* statbuf_get_perms(struct stat *sbuf);
const char* statbuf_get_date(struct stat *sbuf);

//锁
int lock_internal(int fd, int lock_type);
int lock_file_read(int fd);
int lock_file_write(int fd);
int unlock_file(int fd);

//时间
long get_time_sec();
long get_time_usec();
void nano_sleep(double seconds);

#endif /* _SYS_UTIL_H_ */
