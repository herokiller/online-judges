var
   xa,xb,xc,x0,ya,yb,yc,y0,min,max,l,h,k1,k2,b1,b2,x,y,ans1,ans2,xp,yp : extended;

function rasst(x1,y1,x2,y2 : extended) : extended;
 begin
    rasst:=sqrt(sqr(x1 - x2) + sqr(y1 - y2));
 end;

begin
   read(xa,ya,xb,yb,xc,yc,l);
   if (xa = xb) then begin
      h:=abs(xa - xc);
      x0:=xa;
      y0:=yc;
   end else
      if (ya = yb) then begin
         h:=abs(ya - yc);
         x0:=xc;
         y0:=ya;
      end
   else begin
      k2:=(ya - yb)/(xa - xb);
      k1:=(-1)/k2;
      b1:=yc - k1*xc;
      b2:=ya - k2*
      xa;
      x0:=(b2 - b1)/(k1 - k2);
      y0:=k1*x0 + b1;
      h:=rasst(xc,yc,x0,y0);
   end;

   if ((x0 < xa) and (x0 < xb))
   or ((x0 > xa) and (x0 > xb))
   or ((y0 < ya) and (y0 < yb))
   or ((y0 > ya) and (y0 > yb)) then h:=1000000;
   x:=rasst(xc,yc,xa,ya);
   y:=rasst(xc,yc,xb,yb);
   if (x > y) then begin
      max:=x;
      min:=y;
   end else begin
      max:=y;
      min:=x;
   end;
   if (min < h) then begin
      ans1:=min - l;
      if (ans1 < 0) then ans1:=0;
   end else begin
      ans1:=h - l;
      if (ans1 < 0) then ans1:=0;
   end;

   ans2:=max - l;
   if (ans2  < 0) then ans2:=0;

   writeln(ans1:0:2);
   writeln(ans2:0:2);
end.