// 質問用 計算結果が違う
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int GetRandom(int, int);
char* rand_create(int);
int sort_program(char* , int);
struct timeval* run_measure();
struct timeval* fin_measure();

int main(int argc, char *argv[]) {
  printf("起動オプションで入力された数値は「%s」です。\n",argv[1]);
  int create;
  FILE *file;
  char *box;
  // int data = 0;
  char file_name[100000];

  int min_result;
  int micro_result;
  struct timeval *run_time;
  struct timeval *fin_time;

  create = atoi(argv[1]);
  printf("「%d」を数字に変換しました。\n\n", create);

  // 入力管理
  if (argv[1] == NULL) {
    printf("このプログラムを実行する際に、数字を入力してください。\n");
    exit(0);
  }else if(create > 100000){
    printf("100000以下の数字を入力してください。\n");
    exit(0);
  }

  box = rand_create(create);

  run_time = run_measure();

  sort_program(box,create);

  fin_time = fin_measure();


  // 経過時間を計算
  min_result = fin_time->tv_sec - run_time->tv_sec;
  printf("%ld\n", run_time->tv_sec);
  printf("%ld\n", fin_time->tv_sec);
  printf("%d\n", min_result);

  micro_result = fin_time->tv_usec - run_time->tv_usec;
  printf("%06d\n", run_time->tv_usec);
  printf("%06d\n", fin_time->tv_usec);
  printf("%d\n", micro_result);

  printf("このプログラムの処理時間は「%02d,%08d」秒です。\n", min_result,micro_result);

  //ここからファイル操作
  printf("開きたいファイル名を入力してください。\n");
  scanf("%s", file_name);
  printf("=================\n");
  printf("%sに書き込みます。\n", file_name);
  printf("=================\n");

  file = fopen(file_name,"w+");
  if (file == NULL) {
    printf("選択したファイルは見つかりません。\n");
    exit(0);
  }
  // for (i = 0; i < create; i++) {
  //   filerintf("%d ", box[i]);
  // }
  // filerintf("に並べ替えました。\n");
  // filerintf(file, "ソートにかかった時間は、「%ld」でした。\n", time);
  fclose(file);
  return 0;
}

char* rand_create(int create){
  char *box_address;
  char box[100000];
  int i;

  box_address = box;
  // 乱数生成
  for (i = 0; i < create; i++) {
    box[i] = GetRandom(1,100);
    printf("%d ", box[i]);
  }
  printf("が生成されました。\n");
  return box_address;
}

int sort_program(char* box, int create){
  int i,j,tmp;
  //ソートをする
  for (i = 0; i < create; i++) {
    for (j = i+1; j < create; j++) {
      if (box[i]>box[j]) {
        tmp = box[i];
        box[i] = box[j];
        box[j] = tmp;
      }
    }
  }
  for (i = 0; i < create; i++) {
    printf("%d ", box[i]);
  }
  printf("に並べ替えました。\n");
  return 0;
}

struct timeval* run_measure(){
  struct timeval *run_time;
  struct timeval entity;

  run_time = &entity;
  // gettimeofday関数で現在時刻を取得。run_timeタグに格納。実体化。
  gettimeofday(&entity,NULL);
  printf("プログラムが起動された時間は「%02ld,%06d」です。\n", run_time->tv_sec,run_time->tv_usec);
  return run_time;
}

struct timeval* fin_measure(){
  struct timeval *fin_time;
  struct timeval entity;

  fin_time = &entity;
  // gettimeofday関数で現在時刻を取得。fin_timeタグに格納。実体化。
  gettimeofday(&entity,NULL);
  printf("プログラムが起動された時間は「%02ld,%06d」です。\n", fin_time->tv_sec,fin_time->tv_usec);
  return fin_time;
}

int GetRandom(int min, int max){
  return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

// 構造体の中に構造体のポインタを入れる例
#include <stdio.h>

struct test{
  char name[10];
  int age;
  struct test *next;
};

int main() {

  struct test data_1;
  struct test data_2;
  struct test data_3;

  data_2.age = 3;
  data_1.next = &data_2;
  data_3.age = 1000;
  data_2.next = &data_3;

  printf("%d\n", data_1.next->age);
  printf("%d\n", data_1.next->next->age);

  return 0;
}
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAXINPUT 100000


int main() {
  FILE *file;
  char choose;
  int flag;
  char file_name[100];

  while (1) {
    printf("ファイルを選択してください。\n");
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    if (file == NULL) {
      printf("ファイルを新規作成します。\n");
      fclose(file);
      file = fopen(file_name, "w+");
      break;
    }else{
      printf("ファイルが見つかりました。上書きしてもよろしいですか？\n");
      while (1) {
        scanf("%c", &choose);
        if (choose == 'y') {
          printf("上書きします。\n");
          fclose(file);
          file = fopen(file_name, "w+");
          flag = 0;
          break;
        }else if(choose == 'n'){
          printf("もう一度ファイル名を入力してください。\n");
          flag = 1;
          break;
        }else{
          printf("yかnで入力してください\n");
        }
      }
      if (flag == 0) {
        break;
      }
    }
  }

  fclose(file);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAXINPUT 100000

int GetRandom(int, int);
char* rand_create(int);
int sort_program(char* , int);

int main(int argc, char *argv[]) {
  printf("起動オプションで入力された数値は「%s」です。\n",argv[1]);
  // 入力管理
  if (argv[1] == NULL) {
    printf("このプログラムを実行する際に、数字を入力してください。\n");
    exit(0);
  }
  int i;
  int create;
  FILE *file;
  char *box;
  char after_sort_box[MAXINPUT];
  // int data = 0;
  char file_name[MAXINPUT];

  int min_result;
  int micro_result;
  struct timeval run_time;
  struct timeval fin_time;

  create = atoi(argv[1]);
  printf("「%d」を数字に変換しました。\n\n", create);

  if(create > MAXINPUT){
    printf("100000以下の数字を入力してください。\n");
    exit(0);
  }

  // 乱数を生成
  box = rand_create(create);
  // gettimeofday関数で現在時刻を取得。run_timeタグに格納。実体化。
  printf("メインで使えるか。\n");
  for (i = 0; i < create; i++) {
    printf("%d ", box[i]);
  }
  printf("\n");

  gettimeofday(&run_time,NULL);
  printf("プログラムが起動された時間は「%02ld,%06d」です。\n", run_time.tv_sec,run_time.tv_usec);
  // ソートを起動
  sort_program(box,create);
  printf("メインで並び変わってるか。\n");
  for (i = 0; i < create; i++) {
    printf("%d ", box[i]);
  }
  printf("\n");

  // 時間計測
  gettimeofday(&fin_time,NULL);
  printf("ソート後の時間は「%02ld,%06d」です。\n", fin_time.tv_sec,fin_time.tv_usec);

  // 経過時間を計算
  min_result = fin_time.tv_sec - run_time.tv_sec;
  micro_result = fin_time.tv_usec - run_time.tv_usec;
  printf("このプログラムの処理時間は「%02d,%06d」秒です。\n", min_result,micro_result);

  //ここからファイル操作
  printf("開きたいファイル名を入力してください。\n");
  scanf("%s", file_name);
  printf("=================\n");
  printf("%sに書き込みます。\n", file_name);
  printf("=================\n");

  file = fopen(file_name,"r");
  if (file == NULL) {
    printf("選択したファイルは見つかりません。\n");
    exit(0);
  }
  // for (i = 0; i < create; i++) {
  //   filerintf("%d ", box[i]);
  // }
  // filerintf("に並べ替えました。\n");
  // filerintf(file, "ソートにかかった時間は、「%ld」でした。\n", time);
  fclose(file);
  return 0;
}

char* rand_create(int create){
  char *box_address;
  char box[MAXINPUT];
  int i;

  box_address = box;
  // 乱数生成
  for (i = 0; i < create; i++) {
    box[i] = GetRandom(1,100);
    printf("%d ", box[i]);
  }
  printf("が生成されました。\n");
  return box_address;
}

int sort_program(char* box, int create){
  int i,j,tmp;
  //ソートをする
  for (i = 0; i < create; i++) {
    for (j = i+1; j < create; j++) {
      if (box[i]>box[j]) {
        tmp = box[i];
        box[i] = box[j];
        box[j] = tmp;
      }
    }
  }
  for (i = 0; i < create; i++) {
    printf("%d ", box[i]);
  }
  printf("に並べ替えました。\n");
  return 0;
}

int GetRandom(int min, int max){
  return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
●>問題1のところはインクリメント演算子を使用しているため、
>*string1のアドレスは次のアドレスの値を出力しているという認識でよろしいでしょうか？
string1++によって、string1はメモリのアドレスの指定が変わりました。
例えば、最初にstring1はメモリのアドレス１を指定します。
string1++によって、string1はメモリのアドレス２を指定します。
下図のように、string1はメモリのアドレスの指定が変わります。
下記はポインタの話が少し紹介されています。
http://www.itsenka.com/contents/development/c/pointer.html
●>また、そうであれば下記のようにwhile外でメモリの位置を指定してあげれば出力するかと思いましたが
>実行結果の通り、うまく出力することができておりません
>これは、アクセスの仕方が間違っているのでしょうか？
  while(*test){
     *string1++ = *test++;
     printf("charアドレス -> %p 格納されている値：%c\n", string1, *string1);
   }
   printf("while外アドレス -> %p while外値：%c\n", string1, string1[1]);
・格納されている値: string1
while外値: string1
両方の指定しているアドレスが同じです。
・格納されている値: *string1
while外値: string1[1]
string1[1]はstring1が指定しているアドレスの次のアドレスの値を指定しています。
イメージ的に下図のように、
＊string1が指定しているアドレスはメモリのアドレス１です。変わっていません。
以上です。
王様
ご回答いただきありがとうございます。
問題1は
インクリメント演算子を行った時点で次のメモリ先に行くということを理解しました。（実験できていないですが）
しかし
while(*test){
   (下記は配列でいうと[0])
   *string1++ = *test++;
   上記ではインクリメントしているので配列でいうと[1]にすでに移動している
   初期化していないため、[1]には不定な値が入っているため、出力しない
   printf("charアドレス -> %p 格納されている値：%c\n", string1, *string1);
 }
 しかし、下記のprintfは上記のwhile文で代入された後です。下記の最初のアドレス部分は上記の処理後なので
 格納されている値の末尾のアドレスが出力できることを確認しました。しかしstring1[1]は期待通りに出力してくれません。
 明示的にstring1[1]と記載をしているのに出力しないのはなぜでしょうか？(期待の出力は、格納されている値：B)
 printf("while外アドレス -> %p while外値：%c\n", string1, string1[1]);
 私の認識だと、*string1 = string[0], *(string1+1) = string1[1]の認識です。(間違ってたらご指摘お願いします。)
 インクリメントすると*string1 = A, *(string1+1) = B, *(string1+1+1) = Cのように値が代入されていき、
 *(string1+1) = string[1] = B と出力されるのではないでしょうか？？

 理解不足で申し訳ございませんが、ご確認よろしくお願いいたします。


 /*
 作業内容
 下記の入力コマンドに従って動作するプログラムを作成します。
 ・e　　　- クライアント側：サーバ側に送信して、自分はプログラムを終了する
 　　　　　 サーバ側　　　：クライアント側からeコマンドを受信したら、プログラムを終了する
 ・その他 - クライアント側：サーバ側に送信して、次の入力待ちに戻る
 　　　　　 サーバ側　　　：クライアント側から受信した内容を表示する
 */
 //こちらはサーバーです
 #include<stdio.h>
 #include<stdlib.h>
 #include<sys/types.h>
 #include<sys/stat.h>
 #include<sys/errno.h>
 #include<sys/fcntl.h>
 //作業2.メッセージを受け取るサーバーを作成します
 void main()
 {
   //変数宣言
   int fd;
   //ファイルディスクリプター
   int len;
   //FIFOから読み込んだバイト数を格納する変数です
   char buf[256];
   //文字を読み込むバッファー
   //読み込みを行うためにFIFOを開きます
   //クライアントと同じく返り値でエラーチェックをします
   if((fd=open("/tmp/FifoTest",O_RDONLY))==-1)
   {
     perror("open");
     exit(-1);//異常終了
   }
 //FIFOの読み込みを行います
   while(1)
   {
     len = read(fd,buf,sizeof(buf)-1);
     //lenは文字列の要素数となります
     /*
     read関数
     第一引数の内容を第二引数に第三引数を上限に書き込みを行う
     */
     //lenが0の場合は終了します
     if(len == 0)
     {
       printf("終了します\n");
       break;//正常終了
     }
     buf[len] = '\0';//最後の文字をnull文字に置換
     fputs(buf,stdout);//標準出力に出力する
   }
   //FIFOを閉じます
   close(fd);
   //FIFOを消去します
   system("rm -f /tmp/FifoTest");
 }

 /*
 作業内容
 下記の入力コマンドに従って動作するプログラムを作成します。
 ・e　　　- クライアント側：サーバ側に送信して、自分はプログラムを終了する
 　　　　　 サーバ側　　　：クライアント側からeコマンドを受信したら、プログラムを終了する
 ・その他 - クライアント側：サーバ側に送信して、次の入力待ちに戻る
 　　　　　 サーバ側　　　：クライアント側から受信した内容を表示する
 */
 //こちらはクライアントです
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<sys/types.h>
 #include<sys/stat.h>
 #include<sys/errno.h>
 #include<sys/fcntl.h>
 //作業1,メッセージを送るクライアントを作成します
 void main()
 {
 //変数宣言
 int fd;
 /*
 ファイルディスクリプターを格納します
 ファイルディスクリプターは捜査対象のファイルを識別するのに用います
 */
 char buf[256];
 //サーバーに送るメッセージを格納するバッファーです
 //mkfifoで通信用の名前付きパイプ(FIFO)を作成します
 //パイプはデータの通り道となります。参照はファイルディスクリプターにて行います。
 /*
 注釈
 pipe()の引数には、intの配列を渡す。
 ここに書き込み用と読み込み用のファイルディスクリプターが入ってくる。
 （添え字0が読み込み用、1が書き込み用）
 なので、後の操作はファイルディスクリプターを使ったファイル読み書きと同じ。
 */
 //FIFOはファイルシステム内のパス名を持つパイプです=ファイルのように操作できます
 //mkfifoは失敗時の返り値が-1なのでその場合はerrnoを出力します
 if(mkfifo("/tmp/FifoTest",0666)==-1)
 //第二引数はファイルモードを指定しています
 {
   perror("mkfifo");//エラー時にどんな問題があったか確認する関数
 }
 //書き込みを行うためにFIFOを開きます
 //ファイルなのでopenで開きます
 //openもエラーが発生した場合は返り値が-1です
 if((fd=open("/tmp/FifoTest",O_WRONLY))==-1)
 {
   perror("open");
   exit(-1);//異常終了
 }
 //FIFOに書き込みを行います
 while(1)
 {
   fgets(buf,sizeof(buf)-1,stdin);
   if(buf[0] == 'e' && strlen(buf) == 2)
 　//入力がe一文字の場合は終了分岐に入ります
   {
     printf("テストします。入力は%c\n",buf[0]);
     printf("終了コマンド\n");
     break;
   }
   /*
   標準入力ファイルの終了状態をチェックして入力確認します
   ここの挙動は参考にしたサイトをコピーしていて理解出来ていない。復習。
   */
   if(feof(stdin))
   {
     break;
   }
   write(fd,buf,strlen(buf));
   /*
   write関数
   第二引数の内容を第一引数が参照するファイルに第三引数を上限に書き込みを行う
   */
 }
 //FIFOを閉じます
 close(fd);
 //消さないとFIFOは残り続けるので消します
 system("rm -f /tmp/FifoTest");
 //シェルコマンドを呼び出しています
 /*
 注釈
 rmコマンドは「remove」の略で、削除のコマンドだ。ファイルやディレクトリを削除する。
 基本的な書式は次のようになる。
 $ rm ファイル名
 以上のLinuxのコマンドです。
 */
 }


 /*
 作業内容
 下記の入力コマンドに従って動作するプログラムを作成します。
 ・e　　　- クライアント側：サーバ側に送信して、自分はプログラムを終了する
 　　　　　 サーバ側　　　：クライアント側からeコマンドを受信したら、プログラムを終了する
 ・その他 - クライアント側：サーバ側に送信して、次の入力待ちに戻る
 　　　　　 サーバ側　　　：クライアント側から受信した内容を表示する
 */
 //こちらはクライアントです
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 int main(void)
 {
   //変数宣言
   int socket_fd;
   //ソケットディスクリプターを格納する変数
   struct sockaddr_in address ;
   /*
   sys/socket.h 内で定義されている。
   接続先のIPアドレスやポート番号の情報を保持する。Pv6の場合はsockaddr_in6構造体
   */
   int addres_size;
   /*
   ソケットのバイト数を格納する変数
   関数connectの第三引数として必要になる
   */
   int result;
   //connectの戻り値を格納する引数
   char buf[256];
   //サーバーに送るメッセージを格納するバッファー
   /*
   作業1.クライントのソケットを作成します
   関数socketの戻り値はソケットディスクリプターなので格納します
   */
   socket_fd = socket(AF_INET,SOCK_STREAM,0);
   /*
   関数socketの引数
   第１引数
   通信を行なうドメインを指定＝どのプロトコルファミリーを通信に使用するかを指定する。
   第２引数
   通信方法を指定＝基本的にはSOCK_STREAMを使用する
   第３引数
   ソケットによって使用される固有のプロトコルを指定する＝今は0にしておく。
   */
   address.sin_family = AF_INET ;
   /*
   アドレスファミリ
   アドレスファミリは「通信の種類を示す情報」のこと。
   例えば「AF_INET」は「IPv4という種類の通信をするために必要な約束を守る」指示になる。
   */
   address.sin_addr.s_addr = inet_addr("127.0.0.1");
   //IPアドレス　32ビット(4バイト)
   //今回は自分と通信を行うのでローカルループバックアドレスを用いる
   /*
  ローカルループバックアドレス
  常に「自分自身」を指すIPアドレス
  グローバルIPアドレス
  インターネットに接続されているコンピュータや通信機器に一意で割り当てられたIPアドレス
 */
   address.sin_port = 9734;
   //ポート番号　16ビット(2バイト)
 　//理解不足
   addres_size = sizeof(address);
   //直後に使用するconnectの引数用に定義
   //作業2.ソケットをアドレスに接続します
   //関数connectの戻り値はエラーか判断する材料となるので格納します
   result = connect(socket_fd , (struct sockaddr *)&address , addres_size);
   /*
   関数connectの引数
   第１引数
   ファイルディスクリプター
   第２引数
   構造体struct sockaddr_inで指定されたアドレス
   第３引数
   第２引数のバイト数
   */
   //pipeの際と同じく異常終了した際の戻り値は-1です
   if (result == -1)
   {
     perror("open");
     //エラー内容を確認します
     exit(-1);
     //異常終了
   }
   while(1)
   {
     fgets(buf,sizeof(buf)-1,stdin);
     //サーバーに送るメッセージを入力します
     //終了コマンドが入力された場合は終了する
     if(buf[0] == 'e' && strlen(buf) == 2)
     {
       printf("テストします。入力は%c\n",buf[0]);
       printf("終了コマンド\n");
       break;
     }
     write(socket_fd,buf,strlen(buf));
     //第二引数の内容を第一引数が参照するファイルに第三引数を上限に書き込みを行う
   }
   close(socket_fd);
 }

 /*
 作業内容
 下記の入力コマンドに従って動作するプログラムを作成します。
 ・e　　　- クライアント側：サーバ側に送信して、自分はプログラムを終了する
 　　　　　 サーバ側　　　：クライアント側からeコマンドを受信したら、プログラムを終了する
 ・その他 - クライアント側：サーバ側に送信して、次の入力待ちに戻る
 　　　　　 サーバ側　　　：クライアント側から受信した内容を表示する
 */
 //こちらはサーバーです
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 int main(void)
 {
   //変数宣言
   int server_socket_fd;
   //サーバー側のソケットディスクリプター
   int client_socket_fd;
   //クライアント側のソケットディスクリプター
   int server_addres_size;
   /*
   サーバー側のソケットのバイト数を格納する変数
   関数bindの第三引数として必要になる
   */
   int client_addres_size;
   /*
   クライアント側のソケットのバイト数を格納する変数
   関数bindの第三引数として必要になる
   */
   struct sockaddr_in server_address ;
   struct sockaddr_in client_address ;
   /*
   sys/socket.h 内で定義されている。
   接続先のIPアドレスやポート番号の情報を保持する。Pv6の場合はsockaddr_in6構造体
   */
   /*
   作業3.クライントのソケットを作成します
   関数socketの戻り値はソケットディスクリプターなので格納します
   */
   server_socket_fd = socket(AF_INET,SOCK_STREAM,0);
   /*
   関数socketの引数
   第１引数
   通信を行なうドメインを指定＝どのプロトコルファミリーを通信に使用するかを指定する。
   第２引数
   通信方法を指定＝基本的にはSOCK_STREAMを使用する
   第３引数
   ソケットによって使用される固有のプロトコルを指定する＝今は0にしておく。
   */
   server_address.sin_family = AF_INET ;
   /*
   アドレスファミリ
   アドレスファミリは「通信の種類を示す情報」のこと。
   例えば「AF_INET」は「IPv4という種類の通信をするために必要な約束を守る」指示になる。
   */
   server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
   //IPアドレス　32ビット(4バイト) test
   server_address.sin_port = 9734 ;
   //ポート番号　16ビット(2バイト) test
   server_addres_size = sizeof(server_address);
   //直後に使用するbindの引数用に定義
   //作業3.ソケットに名前をつける
   //bindはソケットに名前を付ける関数です
   bind(server_socket_fd , (struct sockaddr *)&server_address , server_addres_size);
   /*
   関数bindの引数
   第１引数
   ファイルディスクリプター
   第２引数
   構造体struct sockaddr_inで指定されたアドレス
   第３引数
   第２引数のバイト数
   */
   listen(server_socket_fd , 5);
   //listenはソケット上の接続を待ちます
   /*
   関数listenの引数
   第１引数
   ファイルディスクリプター
   第２引数
   backlog
   ファイルディスクリプターについての保留中の接続のキューの最大長を指定する。
   キューがいっぱいの状態で接続要求が到着すると、
   クライアントは ECONNREFUSED というエラーを受け取る。
   */
   while(1)
   {
     char buf[256] ;
     printf("server waiting\n");
     client_socket_fd = accept
     //acceptはソケットへの接続を受けます
     (server_socket_fd ,(struct sockaddr *)&client_address , &client_addres_size);
     /*
     関数acceptの引数
     第１引数
     listen関数でリスン状態となっているソケットを識別するディスクリプタを指定します。
     第２引数
     接続中エントリのアドレスを受け取るバッファへのポインタを任意で指定します。
     addrパラメータの実際のフォーマットはsockaddr構造体からソケットが作成された時、
     指定されたアドレスファミリにより決定されます。
     第３引数
     addrパラメータが指す構造体の長さを含む整数へのポインタを任意で指定します。
     */
     while(1)
     {
       int len = read(client_socket_fd,buf,sizeof(buf)-1);
       if(len == 0)//lenが0の場合は終了します
       {
         printf("終了します\n");
         break;//正常終了
       }
       buf[len] = '\0';//最後の文字をnull文字に置換
       fputs(buf,stdout);//標準出力に書き込む
     }
     close(client_socket_fd);
   }
 }
// 4月20日 ポインタを使った文字列の結合
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