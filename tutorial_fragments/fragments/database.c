


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// argc - int number of arguments for main parameter
// *argv[] - a character array which is the second argument (argc[1]) that can be used for input into the main executable
//

struct database_header {
    unsigned short version;
    unsigned short employees;
    unsigned int filelength;
};


int main(int argc, char *argv[]) {

    // if (argc != 2) {
    //     printf("Usage: %s <filename>\n", argv[0]);
    //     return 0;
    // };

    int fd = open("./my-db.db", O_RDONLY);
    if (fd == -1) {
        perror("Open");
        return -1;
    }

    struct database_header head = {0};

    read(fd, &head, sizeof(head));
    printf("Database Version %d\n", head.version);

    return 0;

}