#include <stdio.h>
#include <unistd.h>

int main (int argc, char** argv)
{
    FILE *fp = fopen ("out","w");
    int r = fork();
    for (int i = 0; i < 1000; i++) {
        fprintf(fp, "%d - %d\n", r, i);
    }

    fclose(fp);
    return 0;
 }