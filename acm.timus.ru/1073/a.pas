var
   a : array [1..100000] of longint;
   n,i,j,ans : longint;
begin
   read(n);
   for i:=1 to trunc(sqrt(n)) do
      a[i*i]:=1;
   for i:=1 to n do 
      if (a[i] = 1) then 
         for j:=1 to trunc(sqrt(n-i)) do 
            if (a[i+j*j] = 0) then 
               a[i+j*j]:=2;
   for i:=1 to n do 
      if (a[i] = 2) then  
         for j:=1 to trunc(sqrt(n-i)) do 
            if (a[i+j*j] = 0) then a[i+j*j]:=3;    
   if (a[n] = 0) then ans:=4 else ans:=a[n];
   write(ans);
end.