var
   st : array [1..50] of string;
   s,s1,new : string;
   n,i,j,yk,k : longint;
procedure check;
var
        i : longint;
        ok : boolean;
 begin
    ok:=false;
    for i:=1 to yk do
       if (st[i] = new) then begin
          ok:=true;
          break;
       end;
    if (ok = false) then begin
       inc(yk);
       st[yk]:=new;
    end;
 end;

begin
   readln(s1);
   yk:=1; st[yk]:=s1;
   while true do begin
      readln(s); n:=length(s);
      if s= '#' then break;
      new:='';
      for i:=1 to n do
         if (s[i] = '-') then begin
            k:=i;
            break;
         end else new:=new+s[i];
      check;
      new:='';
      for i:=k+1 to n do
         new:=new+s[i];
      check;
   end;
   write(yk-1);
end.