#include<iostream>
#include<cstdio>
using namespace std;

int N,vv[1000000];

void add(int e1,int e2,int q1,int q2,int ver,int cc) {
   if( e1==q1 && e2==q2 ) { vv[ver] += cc; return; }
   int ee = (e1+e2)/2;
   if( q2<=ee ) add(e1,ee,q1,q2,ver*2,cc); else
   if( ee<q1 ) add(ee+1,e2,q1,q2,ver*2+1,cc); else {
      add(e1,ee,q1,ee,ver*2,cc);
      add(ee+1,e2,ee+1,q2,ver*2+1,cc);
   }
}

int sm;

int main() {
   scanf("%d",&N);

   sm = 1;
   while( sm<N ) sm*=2;

   for(int i=0; i<=N; ++i) {
      int q1,q2,cc;
      scanf("%d%d%d",&q1,&q2,&cc);
      add(1,sm,q1,q2,1,cc);
   }

   for(int i=0; i<N; ++i) {
      int v = sm+i,res = 0;
      while( v>0 ) {
         res+=vv[v];
         v/=2;
      }
      printf("%d%c",res,(i==N-1)?'\n':' ');
   }
}

