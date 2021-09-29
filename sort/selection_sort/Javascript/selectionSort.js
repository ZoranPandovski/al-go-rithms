<html>
 <head>
  <title>
   Selection sort
  </title>
 </head>
 <body>
  <script>
   function smallest(a,n,i)
   {
    var small = a[i];
    var pos = i;
    for(j=i+1;j<10;j++)
    {
     if(a[j]<small)
     {
      small = a[j];
      pos = j;
     }
    }
    return pos;
   }
   var a = [10,9,7,101,23,44,12,78,34,23];
   for(i=0;i<10;i++)
   {
    pos = smallest(a,10,i);
    temp = a[i];
    a[i] = a[pos];
   }
   document.writeln(:printing sorted elements...\n" + "<br>");
   for(i=0;i<10;i++)
   {
    document.writeln(a[i]+"<br>");
   }
  </script>
 </body>
</html>
