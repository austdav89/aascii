#include <stdio.h>

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
    int alphaonly = 0;
    int numonly   = 0;
    int symonly   = 0;

    if(argc == 2){
        if (argv[1][0] == '-' && slen(argv[1]) == 2){
        
            switch(argv[1][1]){
                case 'A':
                    alphaonly = 1;
                    break;
                case 'n':
                    numonly   = 1;
                    break;
                case 's':
                    symonly   = 1;
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
