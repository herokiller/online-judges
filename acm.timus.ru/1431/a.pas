var
   a : array [1..20,1..20] of longint;
   p,x : array [1..20] of longint;
   b : array [1..20] of boolean;
   ans,i,n,j : longint;

function try1(ver : longint) : boolean;
    var i : longint;
begin
   b[ver]:=true;

   for i:=1 to n do begin
      if (a[ver,i]=1) and ((p[i]=0) or ((not b[p[i]])and(try1(p[i])))) then begin
         try1:=true;
         p[i]:=ver;
         exit;
      end;
   end;
   b[ver]:=false;
end;

begin
   read(n);
   for i:=1 to n do 
      read(x[i]);
   for i:=1 to n do 
      for j:=1 to n do 
         if (abs(x[i]-x[j]) = 1 ) then a[i,j]:=1;
  
   for i:=1 to n do begin
     fillchar(b,sizeof(b),false);
     try1(i);
   end;
   ans:=n+n;
   for i:=1 to n do 
      if (p[i] <> 0) then dec(ans);   
   write(ans div 2);
end.