const
   st : array [1..11] of longint = (1,2,4,8,16,32,64,128,256,512,1024);
   maxn = 200;
var
   res : array [-6..maxn+6,-6..maxn+6] of longint;
   a : array [1..maxn,1..maxn] of longint;
   i,j,n,m,ans : longint;
   b : array [1..12] of boolean;

procedure trans(y : longint);
var
        i,x : longint;
 begin
    x:=y;
    for i:=11 downto 1 do begin
       if (x >= st[i]) and (b[i] = false) then begin
          b[i]:=true;
          x:=x-st[i];
          ans:=ans+st[i];
       end;
       if (x >= st[i]) then x:=x-st[i];
    end;
 end;
procedure get(x,y : longint);
var
        i,j : longint;
 begin
    ans:=0;
    fillchar(b,sizeof(b),false);
    for i:=x-6 to x+6 do
       for j:=y-6 to y+6 do
          if (abs(i-x)+abs(j-y) = 1) and (a[i,j] <> 0) then begin
                trans(a[i,j]);

             end;
    if (ans <> 0) then begin
       res[x,y]:=ans;
       exit;
    end;

    for i:=x-6 to x+6 do
       for j:=y-6 to y+6 do
          if (abs(i-x)+abs(j-y) = 2) and (a[i,j] <> 0) then begin
                trans(a[i,j]);

             end;
    if (ans <> 0) then begin
       res[x,y]:=ans;
       exit;
    end;

    for i:=x-6 to x+6 do
       for j:=y-6 to y+6 do
          if (abs(i-x)+abs(j-y) = 3) and (a[i,j] <> 0) then begin
                trans(a[i,j]);

             end;
    if (ans <> 0) then begin
       res[x,y]:=ans;
       exit;
    end;

    for i:=x-6 to x+6 do
       for j:=y-6 to y+6 do
          if (abs(i-x)+abs(j-y) = 4) and (a[i,j] <> 0) then begin
                trans(a[i,j]);

          end;
    if (ans <> 0) then begin
       res[x,y]:=ans;
       exit;
    end;

    for i:=x-6 to x+6 do
       for j:=y-6 to y+6 do
          if (abs(i-x)+abs(j-y) = 5) and (a[i,j] <> 0) then begin
                trans(a[i,j]);

          end;
    if (ans <> 0) then begin
       res[x,y]:=ans;
       exit;
    end;
 end;

begin
   read(n,m);
   for i:=1 to n do
      for j:=1 to m do
         read(a[i,j]);

   for i:=1 to n do
      for j:=1 to m do begin
         if (a[i,j] <> 0) then begin
            res[i,j]:=-1;
            continue;
         end else begin
            get(i,j);
         end;
      end;

   for i:=1 to n do begin
      for j:=1 to m do
         write(res[i,j],' ');
      writeln;
   end;
end.