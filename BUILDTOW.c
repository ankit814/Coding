#include <stdio.h>

typedef unsigned long long int ulli;

int mod = 1000000007;
ulli matMul(ulli tempMat[2][2], ulli reqPow)
{
    ulli obtainedPow = 1;
    ulli m11, m12, m21, m22;
    if(reqPow == 1)
    {
        return 1;
    }

    while(2*obtainedPow <= reqPow)
    {
        m11 = tempMat[0][0]%mod;
        m12 = tempMat[0][1]%mod;
        m21 = tempMat[1][0]%mod;
        m22 = tempMat[1][1]%mod;

        tempMat[0][0] = (m11*m11)%mod+(m12*m21)%mod;
        tempMat[0][1] = (m11*m12)%mod+(m12*m22)%mod;
        tempMat[1][0] = (m21*m11)%mod+(m22*m21)%mod;
        tempMat[1][1] = (m21*m12)%mod+(m22*m22)%mod;

        obtainedPow = obtainedPow*2;
    }
    return (obtainedPow);
}

int main(void)
{

    int t;
    scanf("%d",&t);
    ulli n;
    int i,j;
    ulli m11, m12, m21, m22;
    ulli resMat[2][2] = {{1, 0},{0, 1}};
    ulli baseMat[2][2] = {{1, 1}, {1, 0}};
    ulli tempMat[2][2];
    ulli obtainedPow;
    ulli reqPow;
    for (j=0; j<t; j++)
    {
        scanf("%llu",&n);
        n += 1;
        reqPow = n-1;
        resMat[0][0] = 1;
        resMat[0][1] = 0;
        resMat[1][0] = 0;
        resMat[1][1] = 1;
        while(reqPow > 0)
        {

            tempMat[0][0] = 1;
            tempMat[0][1] = 1;
            tempMat[1][0] = 1;
            tempMat[1][1] = 0;

            obtainedPow = matMul(tempMat, reqPow);

            m11 = resMat[0][0]%mod;
            m12 = resMat[0][1]%mod;
            m21 = resMat[1][0]%mod;
            m22 = resMat[1][1]%mod;

            resMat[0][0] = (m11*tempMat[0][0])%mod+(m12*tempMat[1][0])%mod;
            resMat[0][1] = (m11*tempMat[0][1])%mod+(m12*tempMat[1][1])%mod;
            resMat[1][0] = (m21*tempMat[0][0])%mod+(m22*tempMat[1][0])%mod;
            resMat[1][1] = (m21*tempMat[0][1])%mod+(m22*tempMat[1][1])%mod;

            reqPow -= obtainedPow;

        }

        printf("$%llu\n",(((resMat[0][0]+ resMat[0][1])%mod*(resMat[1][0]+ resMat[1][1])%mod-1)%mod));

    }
    return 0;
}
