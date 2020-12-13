#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

// NOTA: 548 è il primo syscall number disponibile in Linux 4.13
#define __NR_mysyscall 548

long mysyscall(pid_t pid, char * buffer, unsigned int buf_size) {

        return  syscall(__NR_mysyscall, pid, buffer, buf_size);
}

int main() {

        long err;
        char nomeprocesso[16];

        printf("Invocazione myscall()\n");
        err = mysyscall( getpid(), nomeprocesso, 16 );

        if(err) {
                perror("mysyscall fallita");
                return -1;
        }

        printf("Risultato mysyscall: %s\n", nomeprocesso);

        return 0;
}
