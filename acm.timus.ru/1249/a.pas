const
   maxn = 3100;
var
   a,b : array [0..maxn] of byte;
   n,i,j,m : longint;
procedure exi;
begin
   write('No');
   halt(0);
end;
procedure check;
var
        i,j,i2,j2 : longint;
 begin
    for i:=1 to m do begin
       if (a[i] = 0) and (b[i] = 1)
       and (a[i+1] = 1) and (b[i+1] = 1) then exi;
       if (a[i] = 1) and (b[i] = 0)
       and (a[i+1] = 1) and (b[i+1] = 1) then exi;
       if (a[i] = 1) and (b[i] = 1)
       and (a[i+1] = 0) and (b[i+1] = 1) then exi;
       if (a[i] = 1) and (b[i] = 1)
       and (a[i+1] = 1) and (b[i+1] = 0) then exi;
    end;
 end;

begin
   read(n,m);

   for i:=1 to n do begin
      for j:=1 to m do
         read(b[j]);
      check;
      for j:=1 to m do
         a[j]:=b[j];
   end;
   write('Yes');
end.