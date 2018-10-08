defmodule Search do
  def binary_search(array, num) do
    low = 1
    high = Enum.count(array)
    binary_search(array, low, high, num)
  end

  defp binary_search(array, low, high, num) when low <= high do
    mid = Integer.floor_div(low + high, 2)

    cond do
      Enum.at(array, mid) == num
        -> true
      Enum.at(array, mid) < num
        -> binary_search(array, mid + 1, high, num)
      true 
        -> binary_search(array, low, mid - 1, num)
    end
  end

  defp binary_search(_array, low, high, _num) when low > high, do: false
end

IO.inspect Search.binary_search([4, 5, 9, 88, 104, 203, 501, 670], 5)