-module(sudoku).
%% Not every need to be provided to users.
%% If it's neccessary, remove comment signs(%).
-export([
        convert/1,
        % extract/3,
        % position_to/2,
        % check_no_empty/1,
        % check_no_value_duplication/1,
        % find_empty_position/1,
        % is_possible_to_add/2,
        solve/1,
        to_string/1
    ]).

-type position() :: {pos_integer(),pos_integer()}.
-type value() :: pos_integer().
-type cell() :: {position(),value()}.

-type board() :: [cell()].

%% Convert list of integers into list of {{Row,Column},Value}
-spec convert([pos_integer()]) -> board().
convert(RawBoard) ->
    lists:foldl(fun
        ({_,0},Acc) -> Acc;
        ({N,Value},Acc) -> [{{((N - 1) div 9) + 1,((N - 1) rem 9) + 1},Value} | Acc]
    end,[],lists:zip(lists:seq(1,81),RawBoard)).


%% Return list of cells on specific row or column or box.
-spec extract(row | column | box, pos_integer(), board()) -> [cell()].
extract(row,N,Board) ->
    lists:filter(fun({{R,_},_}) -> R =:= N end,Board);

extract(column,N,Board) ->
    lists:filter(fun({{_,C},_}) -> C =:= N end,Board);

extract(box,N,Board) ->
    L = [[1,2,3],[4,5,6],[7,8,9]],
    RowList = lists:nth(((N-1) div 3) + 1,L),
    ColList = lists:nth(((N-1) rem 3) + 1,L),
    lists:filter(fun({{R,C},_}) ->
        lists:member(R,RowList) andalso lists:member(C,ColList)
    end,Board).


%% Convert {Row,Column} into index of row | column | box.
-spec position_to(row | column | box, position()) -> pos_integer().
position_to(row,{Row,_Column}) -> Row;

position_to(column,{_Row,Column}) -> Column;

position_to(box,{Row,Column}) ->
    BigRow = ((Row - 1) div 3) + 1,
    BigColumn = ((Column - 1) div 3) + 1,
    ((BigRow - 1) * 3) + BigColumn.


%% If there's no empty cell on board, return true. Otherwise, false.
-spec check_no_empty(board()) -> boolean().
check_no_empty(Board) when length(Board) == 81 ->
    Positions = lists:map(fun({P,_}) -> P end,Board),
    lists:sort(Positions) =:= [{R,C} || R <- lists:seq(1,9), C <- lists:seq(1,9)];

check_no_empty(_AnyEmptyBoard) when is_list(_AnyEmptyBoard) -> false.


%% If there's no value-duplication on every row & column & box, return true. Otherwise, false.
-spec check_no_value_duplication(board()) -> boolean().
check_no_value_duplication(Board) ->
    Strategies = [{Method,Index} || Method <- [row,column,box], Index <- lists:seq(1,9)],
    lists:all(fun({Method,Index}) ->
        L = extract(Method,Index,Board),
        Values = [V || {_,V} <- L],
        lists:sort(Values) =:= lists:usort(Values)
    end,Strategies).


%% Find which position empty
-spec find_empty_position(board()) -> [position()].
find_empty_position(Board) ->
    [{R,C} || R <- lists:seq(1,9), C <- lists:seq(1,9),
        not lists:any(fun({Pos,_}) -> Pos =:= {R,C} end,Board)].


%% Pre-check function of new cell to add
-spec is_possible_to_add(cell(),board()) -> boolean().
is_possible_to_add({{Row,Column},N},Board) ->
    lists:all(fun(Method) ->
        Index = position_to(Method,{Row,Column}),
        L = [{{Row,Column},N} | extract(Method,Index,Board)],
        VList = [V || {_,V} <- L],
        lists:sort(VList) =:= lists:usort(VList)
    end,[row,column,box]).


%% Solve sudoku
-spec solve(board()) -> board().
solve(Board) ->
    EmptyPositionList = find_empty_position(Board),
    Results = lists:flatten(solve(EmptyPositionList,Board)),
    lists:map(fun({R}) -> R end,Results).


-spec solve([position()],board()) -> [{board()}].
solve([],Board) ->
    case check_no_empty(Board) andalso check_no_value_duplication(Board) of
        true -> [{lists:sort(Board)}];
        false -> []
    end;

solve([EmptyPosition|T],Board) ->
    lists:foldl(fun(N,Acc) ->
        case is_possible_to_add({EmptyPosition,N},Board) of
            true -> [solve(T,[{EmptyPosition,N}|Board])|Acc];
            false -> Acc
        end
    end,[],lists:seq(1,9)).


-spec to_list(board()) -> [char()].
to_list(Board) ->
    lists:foldl(fun(N,Acc) ->
        Row = extract(row,N,Board),
        lists:foldl(fun({_,V},Acc_Row) ->
            Acc_Row ++ io_lib:format("~p",[V])
        end,Acc,Row)
    end,"",lists:seq(1,9)).