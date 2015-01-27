#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MOD 1000000007
#define Mod 1000000006
typedef long long LL;
LL k,h;
LL M[2][2],A[2][2],temp[2][2];
void matrix(LL n){
LL i,j,k;
	while(n){
	if(n&1){
		memset(temp,0,sizeof temp);
		for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++)
				temp[i][j]=(temp[i][j]  +  ((A[i][k]%Mod)* (M[k][j]%Mod))%Mod)%Mod;
		for(i=0;i<2;i++)for(j=0;j<2;j++) A[i][j]=temp[i][j]%Mod;

	}
		memset(temp,0,sizeof temp);
		for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++)
				temp[i][j]=(temp[i][j]+((M[i][k]%Mod)*(M[k][j]%Mod))%Mod)%Mod;
		for(i=0;i<2;i++)for(j=0;j<2;j++) M[i][j]=temp[i][j]%Mod;
		n/=2;
	}
}

LL power(LL a,LL b){
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	if(b%2==0){
		LL u = power(a,b/2)%MOD;
		return ((u%MOD)*(u%MOD))%MOD;
	}
	else{
		LL u = power(a,b/2)%MOD;
		return ((((u%MOD)*(u%MOD))%MOD) * (a%MOD))%MOD;
	}
}
int main(){
LL t;
scanf("%lld",&t);
while(t--){
LL a,b,ans,bns;
scanf("%lld %lld %lld %lld",&a,&b,&h,&k);
M[0][0]=k;M[0][1]=k;M[1][0]=1;M[1][1]=0;
A[0][0]=1;A[0][1]=0;A[1][0]=0;A[1][1]=1;
temp[0][0]=0;temp[0][1]=0;temp[1][0]=0;temp[1][1]=0;
if(h==0){ans=1;bns=0;}
else if(h==1){ans=0;bns=1;}
else{
matrix(h-1);
ans=A[0][1];bns=A[0][0];
}
//printf("%lld %lld\n",ans,bns);
LL final = ((power(a,ans)%MOD) * (power(b,bns)%MOD))%MOD;
printf("%lld\n",final);
}
return 0;
}