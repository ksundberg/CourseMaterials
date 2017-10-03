:- dynamic cell/2.
:- dynamic turn/1.

turn(x).

nextturn(x,o).
nextturn(o,x).

can_move(Location):-cell(Location,_),!,fail.
can_move(_).

win(Player):-cell(upperleft,Player),cell(uppercenter,Player),cell(upperright,Player).
win(Player):-cell(centerleft,Player),cell(centercenter,Player),cell(centerright,Player).
win(Player):-cell(lowerleft,Player),cell(lowercenter,Player),cell(lowerright,Player).
win(Player):-cell(upperleft,Player),cell(centerleft,Player),cell(lowerleft,Player).
win(Player):-cell(uppercenter,Player),cell(centercenter,Player),cell(lowercenter,Player).
win(Player):-cell(upperright,Player),cell(centerright,Player),cell(lowerright,Player).
win(Player):-cell(upperright,Player),cell(centercenter,Player),cell(lowerleft,Player).
win(Player):-cell(lowerright,Player),cell(centercenter,Player),cell(upperleft,Player).

move(Location,Player):-can_move(Location),asserta(cell(Location,Player)).

play(Location):-turn(Player),move(Location,Player),nextturn(Player,Other),retract(turn(Player)),asserta(turn(Other)).

displayCell(L):-cell(L,P),write(P),!.
displayCell(_):-write(" ").

displayBoard:-
displayCell(upperleft),write("|"),displayCell(uppercenter),write("|"),displayCell(upperright),nl,write("-+-+-"),nl, displayCell(centerleft),write("|"),displayCell(centercenter),write("|"),displayCell(centerright),nl,write("-+-+-"),nl, displayCell(lowerleft),write("|"),displayCell(lowercenter),write("|"),displayCell(lowerright),nl.

clear:-cell(L,P),retract(cell(L,P)),fail.
clear.
