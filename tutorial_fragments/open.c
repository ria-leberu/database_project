#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// argc - int number of arguments for main parameter
// *argv[] - a character array which is the second argument (argc[1]) that can be used for input into the main executable
//




int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    };

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Open");
        return -1;
    }

    char *mydata = "hello there file!\n";
    write(fd, mydata, strlen(mydata));

    close(fd);
    return 0;

}