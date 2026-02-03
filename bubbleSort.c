#include <stdio.h>

int main(){
    int v[5] = {2,3,5,4,1};
    
    /*
        {2, 3, 4, 1, 5}
        {2, 3, 1, 4, 5}
        {2, 1, 3, 4, 5}
        {1, 2, 3, 4, 5}
    */
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d\n",v[i]);
    }

    return 0;
}