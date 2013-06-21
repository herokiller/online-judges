#include<iostream>
#include<cstdio>
using namespace std;

#define BASE 10000
#define MAXN 800
void ERR(char *c) {
   fprintf(stderr,"ERROR: %s\n",c);
   exit(0);
}

class bigint {
   public:
   int v[MAXN],l;
   bigint() {
      l = 0;
   }
   void operator=(const int &q) {
      l = 1;
      v[0] = q;
   }
   void operator=(const bigint &q) {
      l = q.l;
      for(int i=0; i<l; ++i)
         v[i] = q.v[i];
   }
   void relax() {
      for(int i=0; i<l-1; ++i)
         if( v[i]>=BASE ) {
            v[i+1]+=v[i]/BASE;
            v[i]%=BASE;
         } else
         while( v[i]<0 ) {
            v[i]+=BASE;
            v[i+1]--;
         }
      while( v[l-1]>=BASE ) {
         v[l] = v[l-1]/BASE;
         v[l-1]%=BASE;
         l++;
         if( l==MAXN ) ERR("MAXN OVERLOADED");
      }
      while( l>0 && v[l-1]==0 ) l--;
   }
   void operator+=(const bigint &q) {
      while( l<q.l ) {
         v[l] = 0;
         l++;
      }
      for(int i=0; i<q.l; ++i)
         v[i]+=q.v[i];
      relax();
   }
   void operator-=(const bigint &q) {
      for(int i=0; i<q.l; ++i)
         v[i]-=q.v[i];
      relax();
   }
   void printdig(int q,bool tr,int bb) {
      bool nen = false;
      while( bb>=10 ) {
         bb/=10;
         if( q/bb!=0 ) nen=true;
         if( !(tr && !nen) )
         printf("%d",q/bb);
         q%=bb;
      }
   }
   void print() {
      if( BASE==10 ) {
         for(int i=l-1; i>=0; --i)
            printf("%d",v[i]);
         printf("\n");
      }
      for(int i=l-1; i>=0; --i)
         printdig(v[i],i==l-1,BASE);
   }
};

int N,K;
bigint a[10100],sum;

int main() {
   scanf("%d%d",&N,&K);
   if( K==0 ) {
      printf("1\n");
      return 0;
   }


   /*  SLOW
   a[0] = 1;
   for(int i=1; i<=N+1; ++i)
      for(int j=max(0,i-K-1); j<i; ++j)
         a[i]+=a[j];

   printf("%d\n",a[N+1]);
   */

   /* FASTER
   a[0] = 1;
   sum = a[0];
   for(int i=1; i<=N+1; ++i) {
      if( i-K-2>=0 ) sum-=a[i-K-2];
      a[i] = sum;
      sum+=a[i];
   }
   printf("%d\n",a[N+1]);
   */

   a[0] = 1;
   sum = a[0];
   for(int i=1; i<=N+1; ++i) {
      if( i-K-2>=0 ) sum-=a[i-K-2];
      a[i] = sum;
      sum+=a[i];
   }
   a[N+1].print();

   return 0;
}

