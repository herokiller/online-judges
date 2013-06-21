var
   h,hx,x0,y0,x,y,r,w,v,vx,b,bx,c : extended;

function rasst(x1,y1,x2,y2 : extended) : extended;
 begin
    rasst:=sqrt(sqr(x1 - x2) + sqr(y1 - y2));
 end;

begin
   read(h,w,x0,y0,r);
   x0:=abs(x0); y0:=abs(y0);
   if (x0 > y0) then begin
      c:=x0;
      x0:=y0;
      y0:=c;
   end;
   x:=w*x0/y0/2;
   y:=w/2;

   b:=rasst(0,0,x,y);
   bx:=b - rasst(0,0,x0,y0);

   hx:=(bx*h)/b;

   v:=w*w*h/3;
   vx:=PI*r*r*hx;

   write(v - vx : 0 : 5);
end.