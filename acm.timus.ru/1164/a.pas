const
   maxn = 1000;
var
   st : array [1..maxn] of char;
   s : string;
   i,j,n,m,k,t,nt,yk : longint;
   a : array [1..20,1..20] of char;
   b : array [1..20,1..20] of boolean;
   ch : char;
procedure check;
var
        i,j : longint;
 begin
    for i:=1 to n do
       for j:=1 to m do
          if (a[i,j] = ch) and (b[i,j] = false) then begin
             b[i,j]:=true;
             exit;
          end;
 end;
begin
   readln(n,m,nt);
   for i:=1 to n do begin
      for j:=1 to m do
         read(a[i,j]);
      readln;
   end;

   for t:=1 to nt do begin
      readln(s);
      for k:=1 to length(s) do begin
         ch:=s[k];
         check;
      end;
   end;

   yk:=0;
   for i:=1 to n do
      for j:=1 to m do
         if (b[i,j] = false)  then begin
            inc(yk);
            st[yk]:=a[i,j];
         end;

   for k:=1 to yk do
      for i:=1 to yk-1 do
         if (st[i] > st[i+1]) then begin
            ch:=st[i];
            st[i]:=st[i+1];
            st[i+1]:=ch;
         end;
   for i:=1 to yk do
      write(st[i]);
end.