const
   maxn = 305;
var
   ans : extended;
   n,i,j : longint;
   b : array [1..maxn,1..maxn] of boolean;
   x,y : array [1..maxn] of extended;

function online(p1,p2,p3 : longint) : boolean;
 begin
    online:=false;

    if ((x[p1] = x[p2]) and (x[p2] = x[p3])) or
       ((y[p1] = y[p2]) and (y[p2] = y[p3])) or
       ((x[p3]-x[p1])*(y[p2]-y[p1])=(y[p3]-y[p1])*(x[p2]-x[p1])) then
       online:=true;
 end;

procedure check(p1,p2 : longint);
var
        st : array [1..maxn] of longint;
        max : extended;
        i,j,yk : longint;
 begin
    yk:=2;
    st[1]:=p1;
    st[2]:=p2;

    max:=sqrt(sqr(x[p1] - x[p2]) + sqr(y[p1] - y[p2]));
    for i:=1 to n do
       if (i <> p1) and (i <> p2) then
          if online(p1,p2,i) then begin
             inc(yk);
             st[yk]:=i;
          end;

    for i:=1 to yk do
       for j:=1 to yk do begin
          if (sqrt(sqr(x[st[i]]-x[st[j]])+sqr(y[st[i]]-y[st[j]]))>max) then
             max:=sqrt(sqr(x[st[i]]-x[st[j]])+sqr(y[st[i]]-y[st[j]]));
          b[st[i],st[j]]:=true;
       end;

    ans:=ans+max;
 end;

begin
   read(n);
   for i:=1 to n do
      read(x[i],y[i]);

   fillchar(b,sizeof(b),false);
   for i:=1 to n do
      b[i,i]:=true;

   for i:=1 to n do
      for j:=1 to n do
         if not b[i,j] then
            check(i,j);

   writeln(round(ans));
end.