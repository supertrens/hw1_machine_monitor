#ifndef HW1_PROTCL_H
#define HW1_PROTCL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


struct monitor_protocol {
	char choice;
	pid_t pid;
	char description[256];
	char info[BUFSIZ];
};

#endif
