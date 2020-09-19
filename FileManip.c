//
// Created by hugod on 14/09/2020.
//

#include "library.h"

void save_solutions_txt(char string[], int ** solution, int size){

    FILE *handler = fopen(string, "a");
    if(handler==NULL) {
        perror("Error opening file.");}
    fflush(handler);
    fprintf(handler,"%d\n",size);
    for (int i = 0; i < size ; i++) {
        for (int j = 0; j < size ; j++) {
            fflush(handler);
            fprintf(handler,"%d ",solution[i][j]);
        }
        fprintf(handler,"\n");
    }
    fclose(handler);
}

void save_solutions_bin(char *string, int **solution, int size){
    FILE *handler = fopen(string, "ab");
    if(handler==NULL) {
        perror("Error opening file.");}
    fprintf(handler,"%d\n",size);
    fwrite(solution,sizeof(int),size*size,handler);
    fclose(handler);


}