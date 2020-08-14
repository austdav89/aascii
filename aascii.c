#include <stdio.h>
#include <stdbool.h>

void usage(void){
    printf("Usage: ./aascii [-A | -n | -s]\n");
}

int slen(char *s){
    int c = 0;
    while(*s++ != '\0'){
        c++;
    }
    return c;
}

int main(int argc, char *argv[]){
    //parse args
    bool alphaonly = false;
    bool numonly   = false;
    bool symonly   = false;

    if(argc == 2){
        if (argv[1][0] == '-' && slen(argv[1]) == 2){
        
            switch(argv[1][1]){
                case 'A':
                    alphaonly = true;
                    break;
                case 'n':
                    numonly   = true;
                    break;
                case 's':
                    symonly   = true;
                    break;
                default:
                    usage();
                    return 1;
            }   
        }
    }

    for(int i = 0; i < 128; i++){
        if(alphaonly){
            if((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')){
                printf("%3i: %c\n",i,i);
            }
        }else if(numonly){
            if(i >= '0' && i <= '9'){
                printf("%3i: %c\n",i,i);
            }
        }else if(symonly){
            if((i >= '!' && i <= '/') || (i >= ':' && i <= '@') || (i >= '[' && i <= '`') || (i >= '{' && i <= '~')){
                printf("%3i: %c\n",i,i);
             }
        }else{printf("%3i: %c\n",i,i);}
    }       
} 
