#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

uint32_t rp(char* a){
	uint32_t value;
	FILE *fd;
	fd = fopen(a,"rb");
	fread(&value,sizeof(uint32_t),1,fd);
	value = ntohl(value);
	fclose(fd);
	return value;
}
int main(int argc,char* argv[]) {

    uint32_t number1 = rp(argv[1]);
    uint32_t number2 = rp(argv[2]);
    uint32_t total = number1 + number2;
    
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)",number1,number1,number2,number2, total,total);
    return 0;
}
