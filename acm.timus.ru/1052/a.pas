const
   maxn = 600;
var
   x,y : array [1..maxn] of extended;
   n,i,ans,kol,j,k : longint;
function check(x1,y1,x2,y2,x3,y3 : extended) : boolean;
 begin
    if (y3 - y1 =0) then begin
       check:=false;
       exit;
    end;
    if ( (x2-x1)/(y2-y1) = (x3-x1)/(y3-y1) ) then check:=true
    else check:=false;
 end;

begin
   read(n);
   for i:=1 to n do read(x[i],y[i]);

   for i:=1 to n do begin
      for j:=i+1 to n do begin
         kol:=2;
         if (x[i] = x[j]) or (y[i] = y[j]) then begin
            if (x[i] = x[j]) then begin
               for k:=1 to n do
                  if (x[k] = x[i]) and (k <> j) and (k <> i) then inc(kol);
            end;
            if (y[i] = y[j]) then begin
               for k:=1 to n do
                  if (y[k] = y[i]) and (k <> i) and (k <> j) then inc(kol);
            end;
         end else begin
            for k:=1 to n do begin
               if (k <> i) and (k <> j) then
                  if check(x[i],y[i],x[j],y[j],x[k],y[k]) then inc(kol);
            end;
         end;
         if (kol > ans) then ans:=kol;
      end;
   end;
   write(ans);
end.