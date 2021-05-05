#include<cstdio>

int mult(int a, int b, int c){
    if(b==1) return a%c;
    long long res=1;
    if (b%2==0){
        res=mult(a, b/2, c);
        return (res*res)%c;
    }else{
        res=mult(a, b/2, c);
        res=(res*res)%c;
        return (res*a)%c;
    }
}

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", mult(a, b, c));
}
//Note: 큰 수 말고 작은수도 확인.. input 4 1 2일때 mult()함수가 4%2가 출력하도록
