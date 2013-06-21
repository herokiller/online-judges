var
n,i,j,x:longint;
a:array[0..150000] of smallint;
b:array[0..150000] of longint;
begin

readln(n);
for i:=1 to n do
begin
readln(b[i],a[i]);
end;

for x:=100 downto 0 do
begin
for i:=1 to n do
if a[i]=x then writeln(b[i],' ',a[i]);
end;

end.
