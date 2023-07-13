#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

uint32_t rp(FILE *fd) {
    uint32_t value;
    fread(&value,sizeof(uint32_t),1,fd);
    value = ntohl(value);
    return value;
}

int main(int argc,char* argv[]) {

    FILE *fd1;
    FILE *fd2;

    fd1 = fopen(argv[1], "rb");
    fd2 = fopen(argv[2], "rb");

    uint32_t number1 = rp(fd1);
    uint32_t number2 = rp(fd2);
    uint32_t total = number1 + number2;
    
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)",number1,number1,number2,number2, total,total);

    fclose(fd1);
    fclose(fd2);

    return 0;
}
