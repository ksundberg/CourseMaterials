:- set_prolog_flag(double_quotes,atom).
:- [adventure].

%Look at a location
%Display long description,
%        connections,
%        contents (one level deep only)
look(_).

%Study an object
%Display long description,
%        contents
study(_).

%Display names of all items in inventory
inventory.

%Move player to given location
move(_).

%Take item into player inventory
take(_).

%Make item from recipe with equipment
make(_).

%Put item from inventory into current location
put(_).

%Transfer a disk in towers of Hanoi puzzle
transfer(_,_).

%Predicate that is true if the game has been won.
win.

