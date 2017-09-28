:- include('adventure.pl').
:- dynamic look/1.
:- dynamic has/1.
:- dynamic connected/2.

connected(X,Y) :- door(X,Y).
connected(X,Y) :- door(Y,X).

look(X):-write(name(X,Y)).
study(X):-write().
