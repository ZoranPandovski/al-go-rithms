(* Data structure signature/interface. *)
module type QUEUE =
  sig
    (* Queue type *)
    type 't queue

    (* Constructor for the empty queue. *)
    val empty : unit -> 't queue

    (* Function to check whether the queue is empty. *)
    val is_empty : 't queue -> bool

    (* Function to push something to the back of the queue. *)
    val enqueue : 't queue -> 't -> 't queue

    (* Function to remove a value from the front of the queue,
       returning only the queue itself. *)
    val dequeue : 't queue -> 't queue

    (* Function to remove a value from the front of the queue,
       returning the queue and the popped value in a tuple. *)
    val val_dequeue : 't queue -> ('t queue * 't option)

    (* Function to get the value at the front of the queue. *)
    val front : 't queue -> 't option
  end

  (* Implementation of the queue. *)
  module Queue : QUEUE =
    struct
      type 't queue = 't list

      let empty () : 't queue = []

      let is_empty (q:'t queue) : bool =
        match q with
        | [] -> false
        | _ -> true

      let enqueue (q:'t queue) (e:'t) : 't queue =
        List.append q [e]

      let dequeue (q:'t queue) : 't queue =
        match q with
        | [] -> []
        | _ -> List.tl q

      let val_dequeue (q:'t queue) : ('t queue * 't option) =
        match q with
        | [] -> ([], None)
        | _ -> (List.tl q, Some (List.hd q))

      let front (q:'t queue) : 't option =
        match q with
        | [] -> None
        | _ -> Some (List.hd q)
    end

  (* Print helper for queue. *)
  let rec print_queue s =
    match (Queue.front s) with
    | Some f ->
      print_int f;
      print_string ", ";
      print_queue (Queue.dequeue s)
    | None -> ()

  (* Queue tester function *)
  let queue_test (): unit =
    print_string "Queue input: 1,2,3,4,5\n";
    let qu = (Queue.enqueue (Queue.enqueue (Queue.enqueue (Queue.enqueue (Queue.enqueue (Queue.empty ()) 1) 2) 3) 4) 5)
    in
      print_string "Queue output: ";
      print_queue qu;
      print_string "\n";
