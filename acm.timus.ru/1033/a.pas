const
   maxn = 35;
   di : array [1..4] of longint = (0,0,1,-1);
   dj : array [1..4] of longint = (1,-1,0,0);
var
   a : array [0..maxn,0..maxn] of char;
   n,i,j,k1,k2,yk,k,ans : longint;
   st1,st2 : array [1..maxn*maxn] of longint;
begin
   readln(n);
   for i:=0 to n+1 do begin
      a[0,i]:='#';
      a[n+1,i]:='#';
      a[i,0]:='#';
      a[i,n+1]:='#';
   end;
   for i:=1 to n do begin
      for j:=1 to n do
         read(a[i,j]);
      readln;
   end;

   yk:=1;
   st1[1]:=1;
   st2[1]:=1;
   i:=0;
   a[1,1]:='1';

   while (i < yk) do begin
      inc(i);
      k1:=st1[i];
      k2:=st2[i];
      for j:=1 to 4 do
         if (a[k1+di[j],k2+dj[j]] = '.') then begin
            inc(yk);
            st1[yk]:=k1+di[j];
            st2[yk]:=k2+dj[j];
            a[k1+di[j],k2+dj[j]]:='1';
         end;
   end;
   a[0,0]:='.'; a[1,0]:='.'; a[0,1]:='.';
   a[n+1,n+1]:='.'; a[n,n+1]:='.'; a[n+1,n]:='.';
   if (a[n,n] <> '1') then begin
      yk:=1;
      st1[1]:=n;
      st2[1]:=n;
      i:=0;
      a[n,n]:='1';

      while (i < yk) do begin
         inc(i);
         k1:=st1[i];
         k2:=st2[i];
         for j:=1 to 4 do
            if (a[k1+di[j],k2+dj[j]] = '.') then begin
               inc(yk);
               st1[yk]:=k1+di[j];
               st2[yk]:=k2+dj[j];
               a[k1+di[j],k2+dj[j]]:='1';
            end;
      end;
   end;
   for i:=1 to n do
      for j:=1 to n do
         if (a[i,j] = '1') then
            for k:=1 to 4 do
               if (a[i+di[k],j+dj[k]] = '#') then inc(ans);
   write(ans*9);
end.