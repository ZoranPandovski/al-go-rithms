{ name of the program }
program fibonacci;

{ declarations }
var 
    i : integer;
    n : integer;

(* Function Fibonacci *)
function fib(v:integer): integer;
begin
    if v = 1 then
        fib := 0
    else if v = 2 then
        fib := 1
    else
        fib := fib(v-1) + fib(v-2);
end;

begin
    { read the element }
    write('n = ');
    readln(n);

    { show the fibonacci elements }
    for i := 1 to n do
        write(fib(i), ' ');
    
    writeln(' ');
end.
