var
   a : array [1..30000] of longint;
   ans: extended;
   n,m,i,x : longint;
begin    
   read(m,n);
   for i:=1 to n do begin
      read(x);
      inc(a[x]);  
   end;
   for i:=1 to m do begin
      ans:=a[i]/n; ans:=ans*100;
      writeln(ans:0:2,'%');
   end;
end. 