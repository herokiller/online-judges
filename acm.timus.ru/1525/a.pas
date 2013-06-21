{$H+}
var
   i : longint;
   ans,lr,ud,fb,le,re,ue,de,fe,be : int64;
   s : string;
begin
   readln(lr,ud,fb);
   readln(s);
   for i:=1 to length(s) do begin
      if (s[i] = 'u') then begin
         if (de <> ud-1) then inc(de);
         if (ue <> 0) then dec(ue);
      end;
      if (s[i] = 'd') then begin
         if (ue <> ud-1) then inc(ue);
         if (de <> 0) then dec(de);
      end;
      if (s[i] = 'l') then begin
         if (re <> lr-1) then inc(re);
         if (le <> 0) then dec(le);
      end;
      if (s[i] = 'r') then begin
         if (le <> lr-1) then inc(le);
         if (re <> 0) then dec(re);
      end;
      if (s[i] = 'f') then begin
         if (be <> fb-1) then inc(be);
         if (fe <> 0) then dec(fe);
      end;
      if (s[i] = 'b') then begin
         if (fe <> fb-1) then inc(fe);
         if (be <> 0) then dec(be);
      end;
   end;
   ans:=(lr-le-re)*(fb-fe-be)*(ud-ue-de);
   writeln(ans);
end.