#include<stdio.h>
#include<string.h>
 
void copy(char* dst, char* src){
  while (*src != '\0') {
    *dst = *src;
    src++;
    dst++;
  }
  *dst = '\0';
}
 
int main(){
  char srcString[] = "We promptly judged antique ivory buckles for the next prize!";

  char dstString[61];

  copy(dstString, srcString);

  printf("%s", dstString);
 
}