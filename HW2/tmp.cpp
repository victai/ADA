#include <cstdio>  
#include <cstring>  
  
long long int a[150001], b[150001], dp[150001];  
long long int w,v,c,n,V,l,r;  
void insert(long int x,long int y)  
{  
    while(l<=r&&b[r]<=y)r--;  
    a[++r]=x;b[r]=y;  
}  
int main()  
{  
    scanf("%lld%lld",&n,&V);
    memset(dp,0,sizeof(dp));      
   // int i,j,d;  
    for(long long int i=1;i<=n;i++)  
    {  
    	scanf("%lld%lld%lld",&c,&v,&w);  
        if(!c||V/v<c)  
            c=V/v;  
        for(long long int d=0;d<v;d++)  
        {  
            l=1;  
            r=0;  
            for(long long int j=0;j<=(V-d)/v;j++)  
            {  
                insert(j,dp[j*v+d]-j*w);  
                if(a[l]<j-c)l++;  
                dp[j*v+d]=b[l]+j*w;  
            }  
        }  
    }  
    printf("%lld\n",dp[V]);  
    return 0;  
} 