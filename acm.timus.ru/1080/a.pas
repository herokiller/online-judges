var
   st,p : array [1..100] of longint;
   a : array [1..100,1..100] of longint;
   b : array [1..100] of boolean;
   n,i,j,x : longint;
procedure amir_eban(ver : longint);
var
   i,j,yk,q : longint;
 begin
    yk:=0;
    q:=-1;
    b[ver]:=true;inc(yk);st[yk]:=ver;
    p[ver]:=q;
    q:=-q;
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
begin
   read(n);
   for i:=1 to n do
      while true do begin
         read(x);
         if (x = 0) then break;
            a[i,x]:=1;
            a[x,i]:=1;
      end;
   for i:=1 to n do
      if not (b[i]) then
         amir_eban(i);
   for i:=1 to n do
      for j:=1 to n do
         if (a[i,j] = 1) and (p[i] = p[j]) then begin
            write(-1);
            halt(0);
         end;
   for i:=1 to n do
      if (p[i] = -1) then write(0) else write(1);
end.
