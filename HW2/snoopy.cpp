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


// #include <iostream>
// #include <stdio.h>
// #include <deque>
// #include <algorithm>
// using namespace std;
// struct Pack{
//  	int sum, cost;
//     Pack(int _s, int _c) : sum (_s), cost(_c) {}
// };
// const int Maxv = 150001;
// deque <Pack> Q;
// int N, V;
// long long int F[Maxv];
// int main(){
//      scanf("%d%d", &N, &V);
//      for (int i = 1, p, w, c; i <= N; i++){
//          scanf("%d%d%d", &p, &w, &c);
//          p = min(p, V / w);
//          for (int j = 0; j < w; j ++){
//              Q.clear();
//              for (int k = 0; k <= (V - j) / w; k ++){
//                  int y = F[k * w + j] - k * c;
//                  while (Q.size() && Q.back().cost <= y) Q.pop_back();
//                  Q.push_back(Pack(k, y));
//                  if (Q.front().sum < k - c) Q.pop_front();
//                  F[k * w + j] = Q.front().cost + k * c;
//              }
// 	       }
//      }
//      for(int i = 0; i <=V; i++)
//      printf("%lld\n", F[i]);
//      return 0;
// }