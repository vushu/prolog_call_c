
:- assertz(file_search_path(foreign,'./')).
main :-
    [foo],
    say_hello('World').
