display_top_disk(Pylon):-location(small_disk, Pylon),location(medium_disk,Pylon),location(large_disk, Pylon),  write("  [|]  "),!.
display_top_disk(_):- write("   |   "),!.

display_middle_disk(Pylon):- location(small_disk,Pylon), location(medium_disk,Pylon), not(location(large_disk,Pylon)),write("  [|]  "),!.
display_middle_disk(Pylon):- location(large_disk,Pylon), location(medium_disk,Pylon), write(" [-|-] "),!.
display_middle_disk(_):- write("   |   "),!.

display_bottom_disk(Pylon):-location(small_disk, Pylon),not(location(medium_disk,Pylon)),not(location(large_disk, Pylon)),  write("  [|]  "),!.
display_bottom_disk(Pylon):- not(location(large_disk,Pylon)), location(medium_disk,Pylon), write(" [-|-] "),!.
display_bottom_disk(Pylon):- location(large_disk,Pylon),write("[--|--]"),!.
display_bottom_disk(_):- write("   |   "),!.

display_top:-display_top_disk(pylon_a),display_top_disk(pylon_b),display_top_disk(pylon_c),fail.
display_top:-nl.
display_middle:-display_middle_disk(pylon_a),display_middle_disk(pylon_b),display_middle_disk(pylon_c),fail.
display_middle:-nl.
display_bottom:-display_bottom_disk(pylon_a),display_bottom_disk(pylon_b),display_bottom_disk(pylon_c),fail.
display_bottom:-nl.


display_pylons:-write("---A------B------C---"),nl,display_top, display_middle, display_bottom,write("---------------------"),nl,!.
