#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void log_message(char* message, char* log_file_path) {
    FILE* log_file = fopen(log_file_path, "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

void send_response(int socket, int status_code, char* status_message, char* content_type, char* body) {
    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, "HTTP/1.1 %d %s\nContent-Type: %s\n\n%s", status_code, status_message, content_type, body);
    send(socket, buffer, strlen(buffer), 0);
    printf("Response sent:\n%s\n", buffer);
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <HTTP PORT> <Log File> <DocumentRootFolder>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    char* log_file_path = (char*) argv[2];
    char* document_root_folder = (char*) argv[3];

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Accept client connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read data from the client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Received request: %s\n", buffer);
        log_message(buffer, log_file_path); // Log the request

        // Parse the request to determine the requested resource and method
        char* method = strtok(buffer, " ");
        char* resource_path = strtok(NULL, " ");
        char* full_resource_path = malloc(strlen(document_root_folder) + strlen(resource_path) + 1);
        strcpy(full_resource_path, document_root_folder);
        strcat(full_resource_path, resource_path);

        // Handle GET request
        if (strcmp(method, "GET") == 0) {
            // Try to open the requested resource
            FILE* resource_file = fopen(full_resource_path, "r");
            if (resource_file == NULL) {
                // Resource not found
                send_response(new_socket, 404, "Not Found", "text/html", "<html><body><h1>404 Not Found</h1></body></html>");
            } else {
                // Resource found, send it to the client
                if (strcmp(request_method, "GET") == 0) {
                    // Handle GET request
                    char file_buffer[BUFFER_SIZE];
                    int file_size;
                    fseek(resource_file, 0L, SEEK_END);
                    file_size = ftell(resource_file);
                    fseek(resource_file, 0L, SEEK_SET);
                    fread(file_buffer, 1, file_size, resource_file);
                    fclose(resource_file);
                    send_response(new_socket, 200, "OK", "text/html", file_buffer);
                } else if (strcmp(request_method, "HEAD") == 0) {
                    // Handle HEAD request
                    fclose(resource_file);
                    send_response(new_socket, 200, "OK", "text/html", "");
                } else if (strcmp(request_method, "POST") == 0) {
                    // Handle POST request
                    char content_length_str[BUFFER_SIZE];
                    char* content_length_header = strstr(buffer, "Content-Length: ");
                    if (content_length_header == NULL) {
                        // Invalid POST request, missing Content-Length header
                        send_response(new_socket, 400, "Bad Request", "text/html", "<html><body><h1>400 Bad Request</h1></body></html>");
                        fclose(resource_file);
                        continue;
                    }
                    sscanf(content_length_header, "Content-Length: %s", content_length_str);
                    int content_length = atoi(content_length_str);
                    char* body = malloc(content_length + 1);
                    fread(body, 1, content_length, resource_file);
                    body[content_length] = '\0';
                    fclose(resource_file);
                    // Echo back the POST body as response
                    send_response(new_socket, 200, "OK", "text/plain", body);
                } else {
                    // Unsupported request method
                    fclose(resource_file);
                    send_response(new_socket, 400, "Bad Request", "text/html", "<html><body><h1>400 Bad Request</h1></body></html>");
                }
            }
