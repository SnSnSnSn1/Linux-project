#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
void print_network_usage() {
    FILE *fp = popen("nethogs", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}