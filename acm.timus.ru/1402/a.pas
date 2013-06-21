var
   fact,ans : int64;
   n,i,j,k : longint;
   x,a : array [1..200] of longint;

begin
{   read(n);
   fact:=1;
   for i:=1 to n do fact:=fact*i;

   for i:=1 to n-1 do begin
      ans:=ans+fact;
      fact:=fact div i;
   end;
   write(ans);
   halt(0);
}

  read(n);
   if (n = 1) then begin
      write(0);
      halt(0);
   end;
   k:=n*(n-1);
   a[1]:=k mod 10; a[2]:=(k div 10) mod 10; a[3]:=k div 100;

   for i:=n-2 downto 0 do begin
      for j:=1 to 100 do x[j]:=x[j]+a[j];
      for j:=1 to 100 do
         if (x[j] >= 10) then begin
            x[j+1]:=x[j+1]+(x[j] div 10);
            x[j]:=x[j] mod 10;
         end;
      for j:=1 to 100 do
         a[j]:=a[j]*i;
      for j:=1 to 100 do begin
         if (a[j] >= 100) then begin
            a[j+2]:=a[j+2]+(a[j] div 100);
            a[j]:=a[j] mod 100;
         end;
         if (a[j] >= 10) then begin
            a[j+1]:=a[j+1]+(a[j] div 10);
            a[j]:=a[j] mod 10;
         end;
      end;
   end;

   for i:=100 downto 1 do
      if (x[i] <> 0) then begin
         for j:=i downto 1 do
            write(x[j]);
         halt(0);
      end;
end.
