const
   maxn = 100006;
   maxm = 6000;
var
   x : array [-1..maxm] of boolean;
   a,b,ar,br : array [1..maxn] of longint;
   min,pr,num,ans  : array [-1..maxm] of longint;
   n,m,i,j,yk,c,pos,res,k : longint;

procedure sort(l,r : longint);
var
        i,j,x,y : longint;
 begin
    i:=l; j:=r; x:=b[(l+r) div 2];
    repeat
       while (b[i] < x) do inc(i);
       while (x < b[j]) do dec(j);
       if (i <= j) then begin
          c:=b[i];
          b[i]:=b[j];
          b[j]:=c;
          c:=a[i];
          a[i]:=a[j];
          a[j]:=c;
          c:=ar[i];
          ar[i]:=ar[j];
          ar[j]:=c;
          c:=br[i];
          br[i]:=br[j];
          br[j]:=c;
          inc(i);
          dec(j);
       end;
    until i>j;
    if (l<j) then sort(l,j);
    if (i<r) then sort(i,r);
 end;


begin
   read(m);
   while not eof do begin
      inc(n);
      read(a[n],b[n]);
      ar[n]:=a[n]; br[n]:=b[n];
      if (a[n]=0) and (b[n]=0) then break;
      if a[n] < 0 then a[n]:=0;
      if b[n] > m then
         b[n]:=m;
      if a[n] > b[n] then
         dec(n);
   end;
   dec(n);
   sort(1,n);
   yk:=1;
   x[-1]:=true; x[0]:=true;
   for i:=-1 to m do
      min[i]:=maxlongint div 2;
   min[-1]:=0;
   min[0]:=0;

   for i:=0 to m do begin
      for j:=yk to n do begin
         if b[j] < i then continue;
         if b[j] > i then begin
            yk:=j;
            break;
         end;
         if b[j] = i then begin
            if (x[a[j]] = true) then begin
               if (min[a[j]] + 1 < min[i]) then begin
                  min[i]:=min[a[j]] + 1;
                  pr[i]:=a[j];
                  x[i]:=true;
                  num[i]:=j;
                  for k:=i-1 downto 0 do begin
                     if (min[i] < min[k]) then begin
                        min[k]:=min[i];
                        pr[k]:=pr[i];
                        x[k]:=true;
                        num[k]:=num[i];
                     end;
                  end;
               end;
            end;
         end;
      end;
   end;
   if x[m] = true then begin
      pos:=m;
      while true do begin
         inc(res);
         ans[res]:=num[pos];
         pos:=pr[pos];
         if pos = 0 then break;
      end;
      writeln(res);
      for i:=1 to res do begin
         b[i]:=ar[ans[i]];
         a[i]:=br[ans[i]];
      end;
      sort(1,res);
      for i:=1 to res do
         writeln(b[i],' ',a[i]);
   end else write('No solution');
end.
