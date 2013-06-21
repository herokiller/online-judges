const
   maxn = 600;
var
   n,i,j,k,yk,max,pos : longint;
   x1,x2 : array [1..maxn] of longint;
   kol,num : array [1..maxn] of longint;
   ans : array [1..maxn,1..maxn] of longint;

procedure sort(l,r : longint);
var
        i,j,x,y : longint;
 begin
    i:=l; j:=r; x:=x1[(l+r) div 2];
    repeat
       while x1[i]<x do inc(i);
       while x1[j]>x do dec(j);
       if (i<=j) then begin
          y:=x1[i];
          x1[i]:=x1[j];
          x1[j]:=y;
          y:=x2[i];
          x2[i]:=x2[j];
          x2[j]:=y;
          y:=num[i];
          num[i]:=num[j];
          num[j]:=y;
          inc(i);
          dec(j);
       end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
 end;

begin
   read(n);
   for i:=1 to n do
      num[i]:=i;
   for i:=1 to n do
      read(x1[i],x2[i]);
   sort(1,n);
   for i:=1 to n do begin
      max:=-1;
      for j:=1 to yk do
          if (x1[i] > x1[ans[j,kol[j]]]) and (x2[i] < x2[ans[j,kol[j]]]) then
             if (kol[j] > max) then begin
                max:=kol[j];
                pos:=j;
             end;

      inc(yk);
      if (max = -1) then begin
         kol[yk]:=1;
         ans[yk,1]:=i;
      end else begin
         kol[yk]:=kol[pos]+1;
         for k:=1 to n do
            if (ans[pos,k] <> 0) then
               ans[yk,k]:=ans[pos,k] else break;
         ans[yk,k]:=i;
      end;
   end;


   max:=-1;
   for i:=1 to yk do
      if (kol[i] > max) then begin
         max:=kol[i];
         pos:=i;
      end;

   writeln(max);
   for i:=max downto 1 do
      write(num[ans[pos,i]],' ');
   close(output);
end.
