var
   n,i : longint;
   x,y : array [1..10000] of extended;
   r,ans : extended;
begin
   read(n,r);
   for i:=1 to n do read(x[i],y[i]);
   ans:=0;
   for i:=1 to n-1 do
      ans:=ans+sqrt(sqr(x[i]-x[i+1])+sqr(y[i]-y[i+1])); 
   ans:=ans+sqrt(sqr(x[1]-x[n])+sqr(y[1]-y[n]));
   ans:=ans+(2*PI*r);
   write(ans:0:2);
end.