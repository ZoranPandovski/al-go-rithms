%% -*- erlang -*-
%%! -pa ./

% when input comes like this...
% escript test.escript 
% >> 006508400520000000087000031003010080900863005050090600130000250000000074005206300
main([Raw]) when length(Raw) == 81 ->
    RawBoard = lists:map(fun(E) -> E - 48 end,Raw),
    ok = verify_good_raw_board(RawBoard),
    Board = sudoku:convert(RawBoard),
    case sudoku:solve(Board) of
        [] -> io:format("No solution found");
        Results -> lists:foreach(fun({N,R}) ->
            io:format("SOLUTION ~p~n",[N]),
            pretty_print(sudoku:to_list(R)) 
        end,lists:zip(lists:seq(1,length(Results)),Results))
    end;

% when input is wrong or multiple inputs
main([_Raw]) ->
    usage();

% when input comes like this...
% escript test.escript
main([]) ->
    Example = 
        [0,0,6,5,0,8,4,0,0,
         5,2,0,0,0,0,0,0,0,
         0,8,7,0,0,0,0,3,1,
         0,0,3,0,1,0,0,8,0,
         9,0,0,8,6,3,0,0,5,
         0,5,0,0,9,0,6,0,0,
         1,3,0,0,0,0,2,5,0,
         0,0,0,0,0,0,0,7,4,
         0,0,5,2,0,6,3,0,0],
    Board = sudoku:convert(Example),
    case sudoku:solve(Board) of
        [] -> io:format("No solution found");
        Results -> lists:foreach(fun({N,R}) ->
            io:format("SOLUTION ~p~n",[N]),
            pretty_print(sudoku:to_list(R)) 
        end,lists:zip(lists:seq(1,length(Results)),Results))
    end.

usage() ->
    io:format("USAGE: escript solve.escript || escript solve.escript <board>~n"),
    io:format("(<board>'s length must be 81)").

verify_good_raw_board(RawBoard) ->
    81 = length(RawBoard),
    lists:foreach(fun
        (N) when (N >= 0) andalso (N =< 9) -> ok
    end,RawBoard).

pretty_print(String) ->
    lists:foreach(fun({Idx,Value}) ->
        case Idx rem 9 of
            0 -> io:format("~2.. B~n",[list_to_integer(Value)]);
            _ -> io:format("~2.. B",[list_to_integer(Value)])
        end
    end,lists:zip(lists:seq(1,81),String)).
