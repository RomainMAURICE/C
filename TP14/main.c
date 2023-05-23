#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <unistd.h>

const char *dirpath="ALGO-main";

int ls(const char *fpath, const struct stat *sb, int typeflag){

    printf("%s \n", fpath);
    return 0;
}

int main(int argc, char *argv[]){    
    
    int e = ftw(argv[1], ls, 10);


    return 0;
}
