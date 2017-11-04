
type Process
  id::Int32
  participant::Bool
  leader_process_id::Int32
  next_process::Process
  Process(id) = (x = new(); x.id = id; x.participant = false; x.leader_process_id = 0; x.next_process = x)
end

function send_election_message(p::Process)
  handle_election_message(p.next_process, p.id)
end

function handle_election_message(p::Process, msg::Int32)
  if msg > p.id
    handle_election_message(p.next_process, msg)
  elseif msg < p.id && p.participant == false 
    send_election_message(p)
  elseif msg == p.id
    p.leader_process_id = p.id
    send_elected_message(p)
  end
end

function send_elected_message(p::Process)
  p.participant = false
  handle_elected_message(p.next_process, p.id)
end

function handle_elected_message(p::Process, msg::Int32)
  if msg == p.id
    return
  end

  p.participant = false
  p.leader_process_id = msg
  handle_elected_message(p.next_process, msg)
end

function elect_leader(p::Process)
  send_election_message(p)
end


function create_ring(n)
  uids = shuffle(1:n)

  ring = Process[]
  for i = uids
    p = Process(i)
    push!(ring, p)
  end

  for i = 1:n-1
    ring[i].next_process = ring[i+1]
  end
  ring[end].next_process = ring[1]

  ring
end

# This is the implementation of a Leader Election algorithm in a ring
# proposed by Chang and Roberts (1979) (https://en.wikipedia.org/wiki/Chang_and_Roberts_algorithm)
# The final outcome is, that the process with the highest UID is elected as a leader.
# The processes do not require knowledge about the amount of processes in the ring

ring = create_ring(10)
elect_leader(ring[1])
for r = ring
  @printf("For %d the leader is: %d\n", r.id, r.leader_process_id)
end
