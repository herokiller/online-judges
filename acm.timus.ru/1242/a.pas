const
   maxn = 1050;
   dig : set of char = ['0'..'9'];
var
   st,ans : array [1..maxn*maxn] of longint;
   b1,b2 : array [1..maxn*maxn] of boolean;
   s : string;
   a1,a2 : array [1..maxn,1..maxn] of longint;
   n,i,j,k,num,x1,x2,res,n1 : longint;
procedure get_num(pos : longint);
var
        i,st : longint;
 begin
    st:=1;
    num:=0;
    for i:=pos to n1 do
       if not (s[i] in dig) then begin
          k:=i;
          break;
       end else st:=st*10;
    for i:=pos to n1 do begin
       st:=st div 10;
       num:=num+st*(ord(s[i])-ord('0'));
       if st = 1 then break;
    end;
 end;
procedure bfs1(ver : longint);
var
        i,yk : longint;
 begin
    yk:=1; st[1]:=ver;
    i:=0;
    b1[ver]:=true;
    while (i < yk) do begin
       inc(i);
       for j:=1 to n do
          if (a1[st[i],j] = 1) and (b1[j] = false) then begin
             inc(yk);
             st[yk]:=j;
             b1[j]:=true;
          end;
    end;
 end;

procedure bfs2(ver : longint);
var
        i,yk : longint;
 begin
    yk:=1; st[1]:=ver;
    i:=0;
    b2[ver]:=true;
    while (i < yk) do begin
       inc(i);
       for j:=1 to n do
          if (a2[st[i],j] = 1) and (b2[j] = false) then begin
             inc(yk);
             st[yk]:=j;
             b2[j]:=true;
          end;
    end;
 end;
begin
   readln(n);
   while true do begin
      readln(s); n1:=length(s);
      if (s[1] = 'B') then break;
      for i:=1 to n1 do
         if (s[i] in dig) then begin
            get_num(i);
            break;
         end;
      x1:=num;
      for i:=k to n1 do
         if (s[i] in dig) then begin
            get_num(i);
            break;
         end;
      x2:=num;
      a1[x1,x2]:=1;
      a2[x2,x1]:=1;
   end;


   while not eof do begin
      read(x1);
      if x1 = -1 then break;
      if not (b1[x1]) then bfs1(x1);
      if not (b2[x1]) then bfs2(x1);
   end;

   res:=0;
   for i:=1 to n do
      if (b1[i] = false) and (b2[i] = false) then begin
         inc(res);
         ans[res]:=i;
      end;
   if (res = 0) then begin
      write(0);
      halt(0);
   end;
   for i:=1 to res do write(ans[i],' ');
end.