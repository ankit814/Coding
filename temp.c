#include <stdio.h>

typedef long long int ulli;

    void matMul(int a[], int n) {
        int i = 22;
        int r;
        int q = 0;
        while (i >= 0 && a[i] != -1) {
            int p = a[i] * n + q;
            r = p % 10;
            q = p / 10;
            a[i] = r;
            i--;
        }
        while (q != 0) {
            a[i] = q % 10;
            q = q / 10;
            i--;

        }
    }

int main(void) {

        int t;
        scanf("%d",&t);
        int arr[t];
                int i,j;
                ulli n;
        for (j=0;j<t;j++){
                        scanf("%llu",&n);

                        if(n<=1259920){
                        ulli z;
                        if(n%2==0){
                        z=n/2;
                        n=z*(n+1)*(n+2);
                        }
                        else{
                                z=(n+1)/2;
                                n=n*z*(n+2);
                                }

                                printf("%llu",n);
                        }
                        else{
                        int a[23];
            for (i = 0; i < 22; i++) {
                a[i] = -1;
            }
            a[22] = 1;

            if (n % 2 == 0) {
                matMul(a, n / 2);
                matMul(a, n + 1);
                matMul(a, n + 2);
            } else {
                matMul(a, n);
                matMul(a, (n + 1) / 2);
                matMul(a, n + 2);
            }
            for (i = 0; i < 23; i++) {
                if (a[i] != -1) {
                    printf("%d",a[i]);
                }
            }
                }
                        printf("\n");
    }
                return 0;
}
