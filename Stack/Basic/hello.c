#include<stdio.h>
int main(){
    int c=0,s=0,i=0,x[10]={2,6,2,2,21,21,21,21,21,21};
    for(i=0;i<10;i++){
        if(x[i]%2==0){
            c++;
            continue;
        }
        s=s+x[i]/2;
        printf("%d\n",s);
        printf("%.2f\n",s/(float)c);
    }
}