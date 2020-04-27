#include <stdio.h>

int copy(char* ,char* );

int main() {

  char string[20];

  copy("ABC",string);
  printf("=========MAIN========\n");
  printf("%s\n", string);
  return 0;
}

int copy(char* test, char* string){
  printf("=========while内========\n");
  while(*test){
    *string++ = *test++;
    // 下記はなぜ不定値
    printf("アドレス：%p 格納されている値：%c\n", string-1, *string-1);
    // 正しくは下記です
    printf("アドレス：%p 格納されている値：%c\n", string-1, *(string-1));
    // printf("アドレス：%p 格納されている値：%c\n", &string[0]-1, string[0]-1);
  }

  printf("=========カッコ無しなぜ不定値=========\n");
  printf("アドレス：%p 格納されている値：%c\n", string-3, *string-3);
  printf("アドレス：%p 格納されている値：%c\n", string-2, *string-2);
  printf("アドレス：%p 格納されている値：%c\n", string-1, *string-1);

  printf("=======減算ポインタアクセス=======\n");
  printf("アドレス：%p 格納されている値：%c\n", string-3, *(string-3));
  printf("アドレス：%p 格納されている値：%c\n", string-2, *(string-2));
  printf("アドレス：%p 格納されている値：%c\n", string-1, *(string-1));

  string = string-3;

  // string--;string--;string--;

  printf("========加算ポインタアクセス=======\n");
  printf("アドレス：%p 格納されている値：%c\n", string, *string);
  printf("アドレス：%p 格納されている値：%c\n", string+1, *string+1);
  printf("アドレス：%p 格納されている値：%c\n", string+2, *string+2);

  printf("========カッコ加算ポインタアクセス=======\n");
  printf("アドレス：%p 格納されている値：%c\n", string, *string);
  printf("アドレス：%p 格納されている値：%c\n", string+1, *(string+1));
  printf("アドレス：%p 格納されている値：%c\n", string+2, *(string+2));

  printf("===========配列アクセス==========\n");
  printf("アドレス：%p 格納されている値：%c\n", &string[0], string[0]);
  printf("アドレス：%p 格納されている値：%c\n", &string[1], string[1]);
  printf("アドレス：%p 格納されている値：%c\n", &string[2], string[2]);

  return 0;
}
