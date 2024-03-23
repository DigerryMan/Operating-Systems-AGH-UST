#include <stdio.h>
#include <time.h>

void reverseBuffer(char* buffer, int buffer_length){
    for(int i = 0; i < buffer_length / 2; i++){
        int reversedIndex = buffer_length - 1 - i;
        char temp = buffer[i];
        buffer[i] = buffer[reversedIndex] ;
        buffer[reversedIndex] = temp;
    }
}

#ifdef CHAR
void copy_by_char(FILE* file_input, FILE* file_output){
    char c;
    fseek(file_input, 0 , SEEK_END);
    long file_length = ftell(file_input);

    for(long i = file_length - 1; i >= 0; i--){
        fseek(file_input, i, SEEK_SET);
        fread(&c, sizeof(char), 1, file_input);
        fwrite(&c, sizeof(char), 1, file_output);
    }
}
#endif

#ifndef CHAR
void copy_by_1024_block(FILE* file_input, FILE* file_output){
    int BUFFER_SIZE = 10;
    fseek(file_input, 0 , SEEK_END);
    long file_length = ftell(file_input);

    long num_of_blocks = file_length / BUFFER_SIZE;
    long leftover_bytes = file_length % BUFFER_SIZE;


    if (leftover_bytes > 0) {
        char leftover_buffer[leftover_bytes];
        fseek(file_input, -leftover_bytes, SEEK_END);
        fread(leftover_buffer, sizeof(char), leftover_bytes, file_input);

        reverseBuffer(leftover_buffer, leftover_bytes);
        printf("LEFTOVER BYTES: %ldBYTS\n", leftover_bytes);
        fwrite(leftover_buffer, sizeof(char), leftover_bytes, file_output);
    }

    printf("NUM OF BLOCKS: %ld\n", num_of_blocks);

    char buffer[BUFFER_SIZE];
    for(long i = 1; i <= num_of_blocks; i++){
        long starting_block_index = -leftover_bytes - (i * BUFFER_SIZE);
        fseek(file_input, starting_block_index, SEEK_END);
        fread(buffer, sizeof(char), BUFFER_SIZE, file_input);

        reverseBuffer(buffer, BUFFER_SIZE);

        fwrite(buffer, sizeof(char), BUFFER_SIZE, file_output);
    }

}
#endif


int main(int argc, char** argsv){
    FILE* file_input = fopen("testInput.txt", "r");
    FILE* file_output = fopen("reversedFile.txt", "w");
    FILE* file_times = fopen("pomiar_zad_1.txt", "w");

    if(!file_input || !file_output || !file_times){
        printf("ERROR with opening files!\n");
        return 1;
    }

    clock_t start, stop;

    #ifdef CHAR
    start = clock();
    copy_by_char(file_input, file_output);
    stop = clock();
    #endif

    #ifndef CHAR 
    start = clock();
    copy_by_1024_block(file_input, file_output);
    stop = clock();
    #endif

    double time = (double) (stop - start) / CLOCKS_PER_SEC;
    fprintf(file_times, "%lf", time);

    printf("Time: %lf\n\n", time);
    
    fclose(file_input);
    fclose(file_output);
    fclose(file_times);

    return 0;
}