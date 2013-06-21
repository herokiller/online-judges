const
   dig : set of char = ['0'..'9'];
var
    a,b : array [1..6000] of longint;
    num,n,i,j,max,min,sum,k : longint;
    s : string;
    ok : boolean;
procedure get_num(pos : longint);
var
        i,st : longint;
 begin
    st:=1;
    num:=0;
    for i:=pos to length(s) do
       if (s[i] in dig) then st:=st*10 else break;
    for i:=pos to length(s) do begin
       st:=st div 10;
       num:=num+st*(ord(s[i])-ord('0'));
       if st=1 then break;
    end;
 end;
begin
   readln(n);
   for i:=1 to n do begin
      readln(s);
      ok:=false;
      for j:=1 to length(s) do
         if (s[j] in dig) then begin
            if s[j] = '0' then break;
            if s[j] = '1' then begin
               ok:=true;
               k:=j+1;
               break;
            end;
         end;
      if ok then begin
         for j:=k+1 to length(s) do
            if (s[j] in dig) then begin
               get_num(j);
               a[i]:=num;
               break;
            end;
      end;
   end;

         for j:=1 to n do
            b[j]:=a[j];
         max:=10000;
         for j:=1 to n do
            if (b[j] = 0) then
               b[j]:=max else max:=b[j];
         sum:=0;
         for j:=1 to n do
            sum:=sum+b[j];
         if sum < 10000 then begin
            writeln('NO');
            halt(0);
         end;

         for j:=1 to n do
            b[j]:=a[j];
         min:=1;
         for j:=n downto 1 do
            if (b[j] = 0) then b[j]:=min else min:=b[j];
         sum:=0;
         for j:=1 to n do
            sum:=sum+b[j];
         if (sum > 10000) then begin
            writeln('NO');
            halt(0);
         end;
      writeln('YES');
end.
