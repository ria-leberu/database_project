#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// argc - int number of arguments for main parameter
// *argv[] - a character array which is the second argument (argc[1]) that can be used for input into the main executable
//

struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
};



int main(int argc, char *argv[]) {

    struct database_header_t head = {0};
    struct stat dbStat = {0};
    
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Open");
        return -1;
    }

    if (read(fd, &head, sizeof(head)) != sizeof(head)) {
        perror("Read");
        close(fd);
        return -1;
    }

    printf("DB Version %u\n", head.version);
    printf("DB Number of Employees: %u\n", head.employees);
    printf("DB File Length: %u\n", head.filesize);

    if (fstat(fd, &dbStat) < 0) {
        perror("stat");
        close(fd);
        return -1;
    }
    printf("DB File Length, reported by stat: %lu\n", dbStat.st_size);

    if (dbStat.st_size != head.filesize) {
        printf("Improper length detected.\n");
        close(fd);
        return -2;
    };

    return 0;

}