const
   inf = maxlongint div 3;
   maxn = 600;
var
   a,sum : array [0..maxn,0..maxn] of longint;
   n,i,j,k,ans,i2,j2 : longint;

begin
   read(n);
   for i:=1 to n do
      for j:=1 to n do
         read(a[i,j]);
   for i:=1 to n do
      for j:=1 to n do
         sum[i,j]:=a[i,j]+sum[i-1,j]+sum[i,j-1]-sum[i-1,j-1];
   ans:=-inf;
   for i:=0 to n do
      for j:=0 to n do
         for i2:=i+1 to n do
            for j2:=j+1 to n do
               if (sum[i2,j2]-sum[i,j2]-sum[i2,j]+sum[i,j] > ans) then
                  ans:=sum[i2,j2]-sum[i,j2]-sum[i2,j]+sum[i,j];
   write(ans);
end.