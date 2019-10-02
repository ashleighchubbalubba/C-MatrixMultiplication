#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _GNU_SOURCE

int main(int argc, char** argv){
  if (argc != 2){
    printf("error: needs file");
    return 0;
  }

  FILE *fp = fopen(argv[1], "r");
  int firstRow, firstCol, secondRow, secondCol;
  int i, j, k, value = 0;

  if(fp == NULL){
    printf("error: file empty");
    return 0;
  }

  //creates space for first matrix
  fscanf(fp, "%d %d", &firstRow, &firstCol);
  int** first = (int**)malloc(firstRow*sizeof(int*));
  int m;
  for(m=0;m<firstRow;m++){
    first[m] = (int*)malloc(firstCol*sizeof(int));
  }

  //creates the first matrix
  for(i = 0; i < firstRow; i++){
    for(j = 0; j < firstCol; j++){
      fscanf(fp, "%d", &first[i][j]);
    }
    fscanf(fp, "\n");
  }

  //creates space for second array
  fscanf(fp, "%d %d", &secondRow, &secondCol);
  int** second = (int**)malloc(secondRow*sizeof(int*));
  int u;
  for(u=0;u<secondRow;u++){
    second[u] = (int*)malloc(secondCol*sizeof(int));
  }

  //checks if they can't be multiplied
  if(firstCol!=secondRow){
    printf("bad-matrices");
    return 0;
  }

  //creates the second matrix
  for(i = 0; i < secondRow; i++){
    for(j = 0; j < secondCol; j++){
      fscanf(fp, "%d", &second[i][j]);
    }
    fscanf(fp, "\n");
  }

  //creates space for the final matrix
  int** final = (int**)malloc(firstRow*sizeof(int*));
  int p;
  for(p=0;p<firstRow;p++){
    final[p] = (int*)malloc(secondCol*sizeof(int));
  }
  //creates the final matrix
  for(i = 0; i < firstRow; i++){
    for(j = 0; j < secondCol; j++){
      for(k = 0; k < secondRow; k++){
	      value = value + first[i][k] * second[k][j];
      }
      final[i][j] = value;
      value = 0;
    }
  }

  //prints matrix
  for(i = 0; i < firstRow; i++){
    for(j = 0; j < secondCol; j++){
      printf ("%d\t", final[i][j]);
    }
    printf("\n");
  }

  return 0;
} 