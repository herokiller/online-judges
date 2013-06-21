var
   null,other,a : array [1..5000] of longint;
   n,k,i,j : longint;
begin
   read(n,k);
   k:=k-1;
   other[1]:=k mod 10;
   other[2]:=(k div 10) mod 10;
   other[3]:=(k div 100) mod 10;
   inc(k);
   for i:=2 to n do begin
      fillchar(a,sizeof(a),0);
      for j:=1 to 5000 do
         a[j]:=null[j]+other[j];
      for j:=1 to 5000 do
         if (a[j] >= 10) then begin
            a[j+1]:=a[j+1]+(a[j] div 10);
            a[j]:=a[j] mod 10;
         end;
      for j:=1 to 5000 do
         a[j]:=a[j]*(k-1);
      for j:=1 to 5000 do begin
         if (a[j] >= 10000) then begin
            a[j+4]:=a[j+4]+(a[j] div 10000);
            a[j]:=a[j] mod 10000;
         end;
         if (a[j] >= 1000) then begin
            a[j+3]:=a[j+3]+(a[j] div 1000);
            a[j]:=a[j] mod 1000;
         end;
         if (a[j] >= 100) then begin
            a[j+2]:=a[j+2]+(a[j] div 100);
            a[j]:=a[j] mod 100;
         end;
         if (a[j] >= 10) then begin
            a[j+1]:=a[j+1]+(a[j] div 10);
            a[j]:=a[j] mod 10;
         end;
      end;
      for j:=1 to 5000 do
         null[j]:=other[j];
      for j:=1 to 5000 do
         other[j]:=a[j];
   end;

   fillchar(a,sizeof(a),0);
   for i:=1 to 5000 do
      a[i]:=null[i]+other[i];
   for i:=1 to 5000 do
      if (a[i] >= 10) then begin
         a[i+1]:=a[i+1]+(a[i] div 10);
         a[i]:=a[i] mod 10;
      end;
   for i:=5000 downto 1 do
      if (a[i] <> 0) then begin
         for j:=i downto 1 do
            write(a[j]);
         halt(0);
      end;
end.