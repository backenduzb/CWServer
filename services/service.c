#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include "../config/settings.h"

int run_service() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    address.sin_port = htons(PORT);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(serveservices/r_fd, 5);
    
    printf("Server starts running: http://127.0.0.1:%d\n", PORT);
    
    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        
        int bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
        buffer[bytes_read] = '\0';
        
        printf("Have a request: \n%s\n", buffer);
        
        char *response =
                   "HTTP/1.1 200 OK\r\n"
                   "Content-Type: text/plain\r\n"
                   "Content-Length: 12\r\n"
                   "\r\n"
                   "Hello C Dev";
        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }
    
    close(server_fd);
    return 0;
}