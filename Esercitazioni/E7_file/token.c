#include <stdio.h>


int main(int argc, char* argv[]){

    char buffer[20]="",buffer1[20]="";

    int found = sscanf(argv[1], "%19[^,],%19[^,]", buffer, buffer1);

    printf("%s\n%s\n\n",buffer,buffer1);

    return 0;
}