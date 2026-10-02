#include <stdio.h>

int main(){
    FILE *file = fopen("/proc/meminfo", "r");

    if(file == NULL){
        printf("Erro de fopen!\n");
        return 1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}