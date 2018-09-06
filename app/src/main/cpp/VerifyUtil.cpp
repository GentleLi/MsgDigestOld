#include <fcntl.h>
#include <stdio.h>
#include "MD5.h"
#include <stdlib.h>
#include "unistd.h"

const int READ_DATA_SIZE = 8192;
const int MD5_SIZE = 16;

int GetFileMD5(const char *filePath, char *strMD5) {
    int i;
    int fd;
    int ret;
    unsigned char data[READ_DATA_SIZE];
    unsigned char md5_value[MD5_SIZE];
    MD5_CTX md5;

    fd = open(filePath, O_RDONLY);
    if (-1 == fd) {
        perror("open");
        return -1;
    }

    // init md5
    MD5Init(&md5);

    while (1) {
        ret = read(fd, data, READ_DATA_SIZE);
        if (-1 == ret) {
            perror("read");
            close(fd);
            return -1;
        }

        MD5Update(&md5, data, ret);

        if (0 == ret || ret < READ_DATA_SIZE) {
            break;
        }
    }

    close(fd);

    MD5Final(&md5, md5_value);

    for (i = 0; i < MD5_SIZE; i++) {
        snprintf(strMD5 + i * 2, 2 + 1, "%02x", md5_value[i]);
    }
    strMD5[MD5_STR_LEN] = '\0'; // add end
    return 0;
}
