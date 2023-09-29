#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){
    printf("%d\t",b);
    if (a > b) return a;
    return b;
}
int length(char str[]){
    int len = 0;
    int start = 0;
    int last_index[256];
    char arr[50];
    memset(last_index,-1,sizeof(last_index));
    for(int i = 0; str[i] != '\0';i++){
        start = max(start, last_index[str[i]] + 1);
        len = max(len,i - start + 1);
        //printf("%d\t",len);
        last_index[str[i]] = i;
        arr[len]=str[i];
    }
    printf("%s",arr);
    return(len);
}
int main(){
    char str[256];
    printf("Enter the String: ");
    scanf("%s",str);
    int l = length(str);
    printf("The length of the longest Sub string : %d",l);
    return(0);
}
