#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int cnt;
int flag[2] = {0,0};
int turn = 0;

void *func0() {
    for (int i = 0; i < 100000; i++) {
        while (flag[1]) {}
        flag[0] = 1;
        cnt++;
        printf("cnt1 :: %d\n", cnt);
        flag[0] = 0;
    }
}

void *func1() {
    for (int i = 0; i < 100000; i++) {
        while (flag[0]) {}
 	flag[1] = 1;
        cnt++;
        printf("cnt2 :: %d\n", cnt);
        flag[1] = 0;
    }
}

int main(){

     pthread_t thread1, thread2;
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, func0, NULL);
     iret2 = pthread_create( &thread2, NULL, func1, NULL);

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread error: %d\n",200000-cnt);
     exit(0);
}
