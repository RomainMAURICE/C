#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <time.h>

/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}


/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}


int array_size(int* array){
int size=0;
while (array[size] != -1)
{
  size++;
}
  return size;
}


void print_array (int* array){
int i;
for (i=0; i<10; i++){
  if (array[i]){
    printf("%d", array[i]);
    printf("\n");
    }
}
}


int are_arrays_equal(int* first, int* second){
  int i;
  int size = array_size(first);

  if(size != array_size(second)){
    return 0;
  }

  for(i=0 ; i<size; i++){
    if(first[i] != second[i]){
      return 0;
    }
  }
  return 1;
}


int* copy_array(int* array){
  int i;
  int* copy = allocate_integer_array(array_size(array));

  while(array[i] != -1){
    copy[i] = array[i];
    i++;
  }
  return copy;
}


int* fill_array(void){
  int size;
  int i;
  int* new_tab;

  printf("Donnez une taille");
  scanf("%d", &size);
  new_tab = allocate_integer_array(size);
  printf("Donnez des entiers positifs\n");
  for (i=0; i<size; i++){
    scanf("%d", &new_tab[i]);
  }

  return new_tab;
}


int* random_array(int size, int max_entry){
  int i;
  int* new_tab = allocate_integer_array(size);

  for(int i=0; i<size ; i++){
    new_tab[i] = rand() % max_entry;
    i++;
  }
  new_tab[i] = -1;
  return new_tab;
}


int* concat_array(int* first, int* second){
  int* new_tab;
  int size = array_size(first) + array_size(second);
  int i;
  int j;
  new_tab = allocate_integer_array(size);

  while(first[i] != -1){
    new_tab[i] = first[i];
  }
  j = i;
  i = 0;

  while(second[i] != -1){
    new_tab[i] = second[i];
  }

  new_tab[i] = first[i];
}


/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]){
  int* tab=allocate_integer_array(10);
  int* tab2=allocate_integer_array(10);
  print_array(tab);

  if(are_arrays_equal(tab, tab2)==1){
    printf("les tableaux sont identiques");
    printf("\n");
  }
  else{
    printf("les tableaux sont differents");
    printf("\n");
  }

  int* tableauCopy = copy_array(tab);
  print_array(tableauCopy);
  printf("\n");


  int* tableauConso = fill_array();
  print_array(tableauConso);
  printf("\n");

  // int* tableauRandom = random_array(3, 10);
  // print_array(tableauRandom);
  // printf("\n");

  // int* tableauFusion = concat_array(tab, tab2);
  // print_array(tableauFusion);
  // printf("\n");

  return 0;
}