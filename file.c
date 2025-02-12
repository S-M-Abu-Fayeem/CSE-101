#include<stdio.h>
#include<stdlib.h>

/* documents : https://www.geeksforgeeks.org/basics-file-handling-c/ 
*/

/* statement
    update a file and later copy the content of the file to another file and also determine the size of the file before updating and after updating
*/

int main() {
    FILE *fptr1 = fopen("in.txt","r+"); // read the modes
    char a[100], b[100];
    if(fptr1 == NULL){
        printf("Error");
        return 0;
    }
    FILE *fptr2 = fopen("out.txt","w");
    if(fptr2 == NULL){
        printf("Error");
        return 0;
    }
    fseek(fptr1,0, SEEK_END);
    fpos_t pos;
    fgetpos(fptr1, &pos); // we can store the current position of the file and later use it
    fseek(fptr1,0,SEEK_SET);// setting the file pointer to the begining
    fsetpos(fptr1, &pos); // again setting the file pointer to previous stored position;

    int n; scanf("%d",&n);
    for(int i = 0 ; i < n; i++) {
        scanf("%s %s",a,b);
        fprintf(fptr1,"%s %s\n", a, b);
    }
    fseek(fptr1,0,SEEK_SET); // rewind(fptr1); does the same job

    while(fscanf(fptr1,"%s %s", a , b)==2) {
        fprintf(fptr2, "%s %s\n", a , b);
    }
    // file size
    fseek(fptr1,0,SEEK_END);
    int yo = ftell(fptr1); // returns number of bytes till that pointer;
    printf("size %d ",yo);
    //altr
    fpos_t tt ;
    fgetpos(fptr1,&tt);
    printf("size %d", (int)tt); // don't forget to type cast
    fclose(fptr1);
    fclose(fptr2);
}
