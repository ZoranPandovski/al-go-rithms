(* Data structure signature/interface. *)
module type STACK =
  sig
    (* Stack type *)
    type 't stack

    (* Constructor for the empty stack. *)
    val empty : unit -> 't stack

    (* Function to check whether the stack is empty. *)
    val is_empty : 't stack -> bool

    (* Function to push something to the front of the stack. *)
    val push : 't stack -> 't -> 't stack

    (* Function to remove a value from the top of the stack,
       returning only the stack itself. *)
    val pop : 't stack -> 't stack

    (* Function to remove a value from the top of the stack,
       returning the stack and the popped value in a tuple. *)
    val val_pop : 't stack -> ('t stack * 't option)

    (* Function to get the value at the top of the stack. *)
    val peek : 't stack -> 't option
  end

(* Implementation of the stack. *)
module Stack : STACK =
  struct
    type 't stack = 't list

    let empty () : 't stack = []

    let is_empty (s:'t stack) : bool =
      match s with
      | [] -> false
      | _ -> true

    let push (s:'t stack) (e:'t) : 't stack =
      List.append [e] s

    let pop (s:'t stack) : 't stack =
      match s with
      | [] -> []
      | _ -> List.tl s

    let val_pop (s:'t stack) : ('t stack * 't option) =
      match s with
      | [] -> ([], None)
      | _ -> (List.tl s, Some (List.hd s))

    let peek (s:'t stack) : 't option =
      match s with
      | [] -> None
      | _ -> Some (List.hd s)
  end

(* Print helper for stack. *)
let rec print_stack s =
  if (Stack.is_empty s) then
    match (Stack.peek s) with
    | Some f ->
      print_int f;
      print_string ", ";
      print_stack (Stack.pop s)
    | None -> ()

(* Stack tester function *)
let stack_test (): unit =
  print_string "Stack input: 1,2,3,4,5\n";
  let stck = (Stack.push (Stack.push (Stack.push (Stack.push (Stack.push (Stack.empty ()) 1) 2) 3) 4) 5)
  in
    print_string "Stack output: ";
    print_stack stck;
    print_string "\n";
