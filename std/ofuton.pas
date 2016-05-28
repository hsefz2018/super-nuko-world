program Ofuton; 
const maxn=50005; 
  
var
   n,i,j:longint; 
   x,y:array [1..maxn] of int64; 
   r_ymin,r_ymax:array [1..maxn] of int64; 
   l_ymin,l_ymax,ans:int64; 
  
procedure swap(var a,b:int64); 
var t:int64; 
begin t:=a; a:=b; b:=t; end; 
  
function min(a,b:int64):int64; begin if a<b then exit(a) else exit(b); end; 
function max(a,b:int64):int64; begin if a>b then exit(a) else exit(b); end; 
  
procedure qsort(l,r:longint); 
var i,j:longint; m:int64; 
begin
   i:=l; j:=r; m:=x[(l+r) div 2]; 
   repeat
      while x[i]<m do inc(i); 
      while x[j]>m do dec(j); 
      if i<=j then begin
         swap(x[i],x[j]); swap(y[i],y[j]); 
         inc(i); dec(j); 
      end; 
   until i>j; 
   if j>l then qsort(l,j); 
   if i<r then qsort(i,r); 
end; 
  
function calc:int64; 
var area:int64; 
begin
   qsort(1,n); 
  
   r_ymin[n]:=y[n]; r_ymax[n]:=y[n]; 
   for i:=n-1 downto 1 do begin
      r_ymin[i]:=min(y[i],r_ymin[i+1]); 
      r_ymax[i]:=max(y[i],r_ymax[i+1]); 
   end; 
  
   l_ymin:=y[1]; l_ymax:=y[1]; 
   area:=(r_ymax[1]-r_ymin[1])*(x[n]-x[1]); 
   for i:=1 to n-1 do begin
      l_ymin:=min(l_ymin,y[i]); 
      l_ymax:=max(l_ymax,y[i]); 
      area:=min(area, 
         (l_ymax-l_ymin)*(x[i]-x[1])+ 
         (r_ymax[i+1]-r_ymin[i+1])*(x[n]-x[i+1])); 
   end; 
  
   exit((r_ymax[1]-r_ymin[1])*(x[n]-x[1])-area); 
end; 
  
begin
   assign(input,'ofuton.in'); reset(input); 
   assign(output,'ofuton.out'); rewrite(output); 
  
   readln(n); 
   for i:=1 to n do readln(x[i],y[i]); 
   ans:=calc; 
   for i:=1 to n do swap(x[i],y[i]); 
   ans:=max(ans,calc); 
  
   writeln(ans); 
   close(input); close(output); 
end. 
