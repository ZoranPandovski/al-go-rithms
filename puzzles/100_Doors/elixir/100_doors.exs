defmodule Doors do
	def run do
		(1..100)
		|> Enum.map(&({&1, :closed}))
		|> open_doors(Enum.to_list(1..100))
		|> output
	end

	def output(list) do
		list
		|> Enum.map(fn({a, b}) -> IO.inspect("Door #{a} is #{b}") end)
	end

	def open_doors(doors, []), do: doors
	def open_doors(doors, [h | t]) do
		open_doors(doors |> Enum.map(fn({door, state}) -> update_if_divisible(door, state, h) end), t)
	end

	def update_if_divisible(door, state, h) when rem(door, h) == 0 do
		case state do
			:closed ->
				{door, :open}
			:open ->
				{door, :closed}
		end
	end

	def update_if_divisible(door, state, _h), do: {door, state}
end

Doors.run()