// 4月20日ポインタを使った文字列の結合
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
    // 下記は間接演算子先に働き値のメモリに移動した後-1の処理をしているため、予期せぬ値が出力されている。
    // printf("アドレス：%p 格納されている値：%c\n", string-1, *string-1);
    // 正しくは下記です。
    printf("アドレス：%p 格納されている値：%c\n", string-1, *(string-1));
    // printf("アドレス：%p 格納されている値：%c\n", &string[0]-1, string[0]-1);
  }

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

  printf("===========配列アクセス==========\n");
  printf("アドレス：%p 格納されている値：%c\n", &string[0], string[0]);
  printf("アドレス：%p 格納されている値：%c\n", &string[1], string[1]);
  printf("アドレス：%p 格納されている値：%c\n", &string[2], string[2]);

  return 0;
}

// 4月20日　ポインタを使った文字列の結合
#include <stdio.h>
int test(char* );
int printx(char* );
int copy1(char* ,char*, char*);
int copy2(char* ,char*, char*);
int main() {
  char string1[20];
  char string2[20];
  char string3[20];
  copy1("ABC","XYZ",string1);
  printf("ABC + XYZ -> %s\n", string1);
  copy2("123","789",string2);
  printf("123 + 789 -> %s\n", string2);
  copy1(string1,string2,string3);
  printf("string1 + string2 -> %s\n", string3);
  test(string3);
  return 0;
}
int test(char* string3){
  while (*string3) {
    printx(string3);
    string3++;
  }
  return 0;
}
int printx(char* string3){
  printf("charアドレス -> %p 格納されている値：%c\n", string3, *string3);
  return 0;
}
int copy1(char* test, char* data, char* string1){
  while(*test){
    *string1++ = *test++;
    // 下記の格納されている値が想定外の値なのはなぜか？
    printf("charアドレス -> %p 格納されている値：%c\n", string1, *string1);
  }
  while(*data){
    *string1++ = *data++;
  }
  *string1 = 0x00;
  // 下記がループしないのはなぜか？
  while(*string1){
    printf("=in=\n");
    printf("charアドレス -> %p 格納されている値：%c\n", string1, *string1);
  }
  return 0;
}
int copy2(char* test, char* data, char* string2){
  while(*test){
    *string2++ = *test++;
  }
  do {
    *string2++ = *data;
  } while(*data++);
  return 0;
}