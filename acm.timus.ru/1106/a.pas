const
   maxn = 1005;
var
   a : array [1..maxn,1..maxn] of longint;
   st,p : array [1..maxn] of longint;
   b : array [1..maxn] of boolean;
   i,j,n,x,k,yk,res : longint;
   ans : array [1..maxn] of longint;

begin
   read(n);
   for i:=1 to n do begin
     while true do begin
      read(x);
      if (x=0) and (k=0) then begin
         write(0);
         halt(0);
      end;
      if x=0 then begin
         k:=0;
         break;
      end;
      a[i,x]:=1;
      a[x,i]:=1;
      inc(k);
     end;
   end;

   for k:=1 to n do
      if (b[k] = false) then begin
         yk:=1;
         st[1]:=k;
         b[k]:=true;
         p[k]:=1;
         i:=0;
         while (i < yk) do begin
            inc(i);
            for j:=1 to n do
               if (a[st[i],j] = 1) and (b[j] = false) then begin
                  inc(yk);
                  st[yk]:=j;
                  b[j]:=true;
                  p[j]:=-p[st[i]];
               end;
         end;
      end;

   for i:=1 to n do
      if p[i]=1 then begin
         inc(res);
         ans[res]:=i;
      end;
   writeln(res);
   for i:=1 to res do
      write(ans[i],' ');
end.