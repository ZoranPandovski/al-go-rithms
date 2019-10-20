/// <note>fsharp-bin and mono are required to run and compile</note>
/// <note>Compile and run with:
///   >fsharpc --nologo caesar_chipher.fsx && mono caesar_chipher.exe</note> 
/// <summary>Ceasar chipher encoding with ASCII characters </summary>
/// <param name="shift">Number of ASCII chars to shift</param>
/// <param name="str">Encoding/Decoding string</param>
/// <return>Encoded or decoded chipher</return>

let ceasar (shift:int) (str:string) = 
    str 
        |> Seq.map(fun x -> string (x + char shift))
        |> String.concat ""

/// Invers the chipher text
let ceasar_invers (shift:int) (str:string) = 
    str 
        |> Seq.map(fun x -> string (x + char -shift))
        |> String.concat ""

let test_ceasar() = 
    let prompt str =
        printf "%s: " str
        System.Console.ReadLine()
    let a = prompt "shift" 
    let b = prompt "str"
    printfn "Encode: %A" (ceasar (int a) b)

test_ceasar()

//printfn "Encode: %A" (ceasar 47 "ABCDEFG")
//printfn "Decode: %A" (ceasar_invers 47 "pqrstuv")