const
   maxn = 10000;
var
   list : array [1..maxn] of string;
   kol : array [1..maxn] of longint;
   ch : char;
   s : string;
   ok : boolean;
   n,k,i,j,max,ans,yk : longint;
begin
   readln(n);
   k:=1;
   for i:=1 to n do
      k:=k*2;

   for i:=1 to k do begin
      while true do begin
         read(ch);
         if ch = ' ' then break;
      end;
      s:='';
      list[i]:='';
      while not seekeoln do begin
         read(ch);
         s:=s+ch;
      end;
      readln;

      ok:=false;
      for j:=1 to yk do
         if (list[j] = s) then begin
            inc(kol[j]);
            ok:=true;
            break;
         end;
      if ok = false then begin
         inc(yk);
         list[yk]:=s;
         kol[yk]:=1;
      end;
   end;

   for i:=1 to yk do
      if (kol[i] > max) then
         max:=kol[i];

   while true do begin
      if (max > (k div 2)) then begin
         write(ans);
         halt(0);
      end;
      inc(ans);
      k:=k div 2;
      if (k = 1) then break;
   end;

   write(ans);
end.
