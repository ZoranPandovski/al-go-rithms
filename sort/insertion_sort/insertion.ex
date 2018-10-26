defmodule Insertion do
  def sort(list) when is_list(list) do
    do_sort([], list)
  end

  def do_sort(_sorted_list = [], _unsorted_list = [head|tail]) do
    do_sort([head], tail)
  end
  def do_sort(sorted_list, _unsorted_list = [head|tail]) do
    insert(head, sorted_list) |> do_sort(tail)
  end
  def do_sort(sorted_list, _unsorted_list = []) do
    sorted_list
  end

  def insert(elem, _sorted_list = []) do
    [elem]
  end
  def insert(elem, sorted_list) do
    [min|rest] = sorted_list
    if min >= elem do [elem|[min|rest]] else [min|insert(elem, rest)] end
  end
end
IO.inspect Insertion.sort([1, 2, 100, 3, 4, 1, 200, 45, 6, 10]) #=> [1, 1, 2, 3, 4, 6, 10, 45, 100, 200]
