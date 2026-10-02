#include <sys/utsname.h>
#include <string.h>

void kernel_monitor(char *kernel){
    struct utsname info;

    uname(&info);

    strcpy(kernel, info.release);

    return;
}