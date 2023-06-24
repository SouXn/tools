#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 1000

void scan_ports(const char* target_ip, int start_port, int end_port) {
    int sock;
    struct sockaddr_in target_addr;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set up target address structure
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    // Scan open ports
    for (int port = start_port; port <= end_port; ++port) {
        target_addr.sin_port = htons(port);

        // Attempt to connect
        if (connect(sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) >= 0) {
            printf("Port %d: Open\n", port);
            // TODO: Retrieve service information if needed
        }
    }

    close(sock);
}

int main() {
    const char* target_ip = "10.10.231.104"; // IP address of the target
    int start_port = 1; // Start port
    int end_port = MAX_PORTS; // End port

    scan_ports(target_ip, start_port, end_port);

    return 0;
}
