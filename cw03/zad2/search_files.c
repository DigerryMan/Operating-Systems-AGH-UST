#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int arg, char** argsv){
    DIR* dir = opendir(".");
    struct dirent* element = readdir(dir);
    struct stat file_info;
    unsigned long long sum_of_sizes = 0;

    if(!dir){
        printf("Error while opening dir!\n");
        return 1;
    }

    while(element != NULL){
        stat(element->d_name, &file_info);          
            
        if(!S_ISDIR(file_info.st_mode)){
            sum_of_sizes += file_info.st_size;
            printf("%s %ld\n", element->d_name, file_info.st_size);
        }

        element = readdir(dir);
    }

    printf("Sum of sizes: %lld\n", sum_of_sizes);

    closedir(dir);
    return 0;
}