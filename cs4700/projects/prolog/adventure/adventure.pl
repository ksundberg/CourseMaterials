:- dynamic here/1.
:- dynamic has/1.
:- dynamic location/2.
here(bedroom).

room(animal_science).
room(avenue).
room(bedroom).
room(chemistry_lab).
room(common_room).
room(computer_lab).
room(eslc_north).
room(eslc_south).
room(elevator).
room(geology_building).
room(green_beam).
room(hall).
room(hub).
room(kitchen).
room(laser_lab).
room(library).
room(observatory).
room(old_main).
room(plaza).
room(quad).
room(roof).
room(roommate_room).
room(ser_1st_floor).
room(ser_2nd_floor).
room(secret_lab).
room(special_collections).
room(tsc_patio).
room(tunnels_east).
room(tunnels_north).
room(tunnels_west).

door(eslc_north,chemistry_lab).
door(eslc_north,tsc_patio).
door(eslc_south,eslc_north).
door(hub,tunnels_west).
door(old_main,computer_lab).
door(ser_1st_floor,elevator).
door(ser_2nd_floor,laser_lab).
door(ser_2nd_floor,elevator).
door(tsc_patio,hub).
door(tunnels_east,ser_1st_floor).
door(tunnels_north,animal_science).
door(tunnels_north,tunnels_west).
door(tunnels_west,secret_lab).
door(tunnels_west,tunnels_east).
door(avenue,quad).
door(bedroom,hall).
door(hall,common_room).
door(hall,roommate_room).
door(kitchen,hall).
door(library,special_collections).
door(library,plaza).
door(plaza,common_room).
door(plaza,ser_1st_floor).
door(plaza,avenue).
door(quad,animal_science).
door(quad,eslc_south).
door(quad,geology_building).
door(quad,old_main).
door(quad,tsc_patio).
door(roof,green_beam).
door(roof,elevator).
door(roof,observatory).

location(closet,eslc_south).
location(goggles,closet).
location(note,bedroom).
location(book_a,special_collections).
location(book_b,special_collections).
location(book_c,special_collections).
location(recipe,book_a).
location(bone,geology_building).
location(figurine,bedroom).
location(fly,roommate_room).
location(key,coat).
location(coat,green_beam).
location(large_disk,pylon_a).
location(medium_disk,pylon_a).
location(small_disk,pylon_a).
location(pylon_a,secret_lab).
location(pylon_b,secret_lab).
location(pylon_c,secret_lab).
location(flask,chemistry_lab).
location(bunsen_burner,chemistry_lab).
location(laser,laser_lab).

container(closet).
container(coat).
container(book_a).
container(pylon_a).
container(pylon_b).
container(pylon_c).

equipment(laser).
equipment(bunsen_burner).

create_recipe(laser,[bone],charged_bone).
create_recipe(bunsen_burner,[flask,charged_bone,fly],potion).

name(animal_science,"Animal Science Building").
name(avenue,"A tree lined avenue").
name(bedroom,"Your bedroom").
name(bone,"large dragon bone").
name(charged_bone,"a chunk of dragon bone").
name(book_a,"Corpus Hermiticum").
name(book_b,"War and Peace").
name(book_c,"Great Expectations").
name(bunsen_burner,"bunsen burner").
name(chemistry_lab,"Student Chemistry Lab").
name(closet,"equipment closet").
name(coat,"Dr. Sundberg's lab coat").
name(common_room,"Dorm common room").
name(computer_lab,"Student Computer Lab").
name(elevator,"Elevator").
name(potion,"potion").
name(eslc_north,"Eccels Science Learning Center").
name(eslc_south,"Eccels Science Learning Center").
name(figurine,"alien figurine")
name(flask,"glass flask").
name(fly,"dead fly").
name(geology_building,"Geology Building").
name(goggles,"dark saftey goggles").
name(green_beam,"The 'Grean Beam' enclosure").
name(hall,"Hallway").
name(hub,"The Hub").
name(ice_cream, "Aggie Creamery").
name(key,"key").
name(kitchen,"Kitchen").
name(large_disk,"large energy disk").
name(laser,"laser array").
name(laser_lab,"Laser Lab").
name(library,"Merill-Caizer Library").
name(medium_disk,"medium energy disk").
name(note,"note").
name(observatory,"Observatory").
name(old_main,"Old Main").
name(plaza,"Engineering plaza").
name(pylon_a,"red pylon").
name(pylon_b,"blue pylon").
name(pylon_c,"green pylon").
name(quad,"The Quad").
name(recipe,"alchemical recipe").
name(roof,"On the roof of the SER Building").
name(roommate_room,"Your dormmate's room").
name(secret_lab,"Dr. Sundberg's Secret Lab").
name(ser_1st_floor,"1st Floor of SER Building").
name(ser_2nd_floor,"2nd Floor of SER Building").
name(small_disk,"small energy disk").
name(special_collections,"Special Collections Room").
name(tsc_patio,"Patio of the TSC").
name(tunnels_east,"Underground Tunnels").
name(tunnels_north,"Underground Tunnels").
name(tunnels_west,"Underground Tunnels").
name(_,"").
short_desc(animal_science,"a cozy-looking, white-bricked old building.").
short_desc(avenue,"A broad walkway lined with trees.").
short_desc(bedroom,"your bedroom - complete with dirty laundry and heaps of old homework, the sad remains of many hard fought battles waged over Dr. Sundberg's homework").
short_desc(potion,"An oily black potion").
short_desc(bone,"a large dark stone").
short_desc(charged_bone,"A small piece of 'dragon' bone").
short_desc(book_a,"a copy of 'Corpus Hermiticum' a book on alchemy").
short_desc(book_b,"a copy of 'War and Peace'").
short_desc(book_c,"a copy of 'Great Expectations'").
short_desc(bunsen_burner,"A stand with a tube connected to a natural gas supply").
short_desc(chemistry_lab,"A lab with fume hoods and various chemical instuments").
short_desc(closet,"Basically a hole in a wall").
short_desc(coat,"A large white lab coat with lots of pockets").
short_desc(common_room,"A typical scene of college living, an ever growing pile of pizza boxes in the corner, you know they will not be thrown out until they begin to develop consciousness.").
short_desc(computer_lab,"Many computers lined up and a desk at front of room").
short_desc(elevator,"You are in a plain metal box.  There are buttons labeled with various locations.").
short_desc(eslc_north,"You are on the north side of the ESLC.").
short_desc(eslc_south,"You are on the south side of the ESLC.").
short_desc(figurine,"Your roommate's alien figurine.  He always keeps it on his shelf.")
short_desc(flask,"a glass flask suitable for mixing reagents").
short_desc(fly,"the partially squished body of a dead house fly").
short_desc(geology_building,"Large building with rocks and trees surrounding it").
short_desc(goggles,"dark eye protection left over from the 'Great American Eclipse'").
short_desc(green_beam,"Dr. Sundberg is standing at a large machine which is emitting a bright beam of green light.  You overhear a conversation indicating that he has set up a wormhole generator in his secret lab.  This will allow the alien invasion force to reach earth.").
short_desc(hall,"Long pathway that has pictures hanging on wall").
short_desc(hub,"Smells of coffee and pizza linger in the air. Students congregate around tables slaving away at endless homework.").
short_desc(key,"an ornate key glowing with alien energies").
short_desc(kitchen,"A small room containing the bare essentials, including a leaning tower of pizza boxes").
short_desc(large_disk,"a large disk glowing with alien energy").
short_desc(laser,"Pulsating with energy, this laser could be used to imbue something with energy").
short_desc(laser_lab,"Lasers shine in a beautiful array of cornea charing horror, good thing you have goggles on!").
short_desc(library,"Endless floors of books full of knowledge. A smiling librarian greets you as you enter, \"welcome to the library\" she says.").
short_desc(medium_disk,"a medium sized disk glowing with alien energy").
short_desc(note,"a handwritten note from your roommate").
short_desc(observatory,"A tower where you can stargaze.").
short_desc(old_main,"The building is full of nerdy looking people.").
short_desc(plaza,"A large open space between engineering buildings").
short_desc(pylon_a,"a glowing red pyramid shaped structure").
short_desc(pylon_b,"a glowing blue pyramid shaped structure").
short_desc(pylon_c,"a glowing green pyramid shaped structure").
short_desc(quad,"A large open field split into four even sections").
short_desc(recipe,"a page from 'Corpus Hermiticum' containing a recipe for an invisibility potion").
short_desc(roof,"It's a long way down, don't fall off.").
short_desc(roommate_room,"Its pretty messy. A computer light is blinking and there are textbooks near by.").
short_desc(secret_lab,"").
short_desc(ser_1st_floor,"").
short_desc(ser_2nd_floor,"").
short_desc(small_disk,"a small disk glowing with alien energy").
short_desc(special_collections,"Only the rarest books are kept here, who knows what secrets they might hold?").
short_desc(tsc_patio,"A concrete patio with a water feature and multiple paths").
short_desc(tunnels_east,"The underground tunnels are a confusing place.  I hope you don't get lost.").
short_desc(tunnels_north,"The underground tunnels are a confusing place.  I hope you don't get lost.").
short_desc(tunnels_west,"The underground tunnels are a confusing place.  I hope you don't get lost.").
short_desc(_,"").

long_desc(animal_science,"The early twentieth-century edifice has a certain charm to it; the worn white bricks, coral roof tiling, and neo-classical columns adorning the entrance lend themselves to a certain prideful, nostalgic semblence of old academia. A laminated banner with the words 'Animal Science' is sloppily taped above the front doors. Inside, however, you are surprised to only be met with fluorescent lighting, disjointed rennovations, and caffeine-dependent mathematicians.").
long_desc(avenue,"A myriad of people walk every which way along the avenue.  All are seemingly unaware of their imminent destruction at Dr.Sundberg's hand.").
long_desc(bone,"The femur bone from a dragon discovered in the hills of St. Ignatius, Montana.").
long_desc(bedroom,"The college dorm room where you currently reside. These walls have witnessed more late night study sessions than you care to consider. The bed is soaked with the dried tears of uncounted tests failed. Fortunately, the building is aired frequently enough that you can't still smell the years of dirty laundry that have sat in the closet.").
long_desc(book_a,"An ancient work on alchemy containing many magical formulae.").
long_desc(book_b,"A seemingly very old copy of War and Peace. A classic story about a Russian family during the invasion of Napoleon Bonaparte.").
long_desc(book_c,"The classic story of an orphan boy named Pip from the marshes of Kent.").
long_desc(bunsen_burner,"A Bunsen burner, named after Robert Bunsen, is a common piece of laboratory equipment that produces a single open gas flame, which is used for heating, sterilization, and combustion.").
long_desc(chemistry_lab,"").
long_desc(closet,"").
long_desc(coat,"A spiffy looking lab coat. The pockets are lined with some kind of residue from Dr. Sundberg's experiments. It smells like aliens... Gross!").
long_desc(common_room,"").
long_desc(computer_lab,"The room is filled with the glow and hum of many computers and the feverish typing of college students.").
long_desc(elevator,"A large metal container used to transport people and large objects to different floors in a building.").
long_desc(eslc_north,"").
long_desc(eslc_south,"").
long_desc(figurine,"Your roommate's alien figurine.  He's been obsessed with aliens since you met him.  You always wondered why, but after reading that note about Dr.Sundberg, it is all beginning to make sense.")
long_desc(flask,"A small container made of glass that is wide at the base and narrow at the neck.  A purple liquid seems to have been left over from a previous experiment.").
long_desc(fly,"Scientifically known as Syrphus Ribessi, this nuisance enjoys long buzzes around human faces and landing on perfectly good food. This particular house fly met an untimely death by squishing.").
long_desc(geology_building,"").
long_desc(goggles,"").
long_desc(green_beam,"").
long_desc(hall,"A narrow area or passage that connects rooms of an edifice.  The passage is laid with dark red carpeting with pictures hanging on its walls.").
long_desc(hub,"").
long_desc(key,"").
long_desc(kitchen,"").
long_desc(large_disk,"").
long_desc(laser,"A rather powerful laser for research. Probably shouldnt look into it.").
long_desc(laser_lab,"").
long_desc(library,"").
long_desc(medium_disk,"").
long_desc(note,"In the handwriting of your room mate is hastily scrawled: 'You've got to help.  Dr. Sundberg is an alien and wants to take over the world.  I think he is on to me, you are the only hope left! Try to find out what he is doing with the green beam.'").
long_desc(observatory,"").
long_desc(old_main,"The building has four floors, and is the location of much pain during the Evil Dr. Sundber's class.").
long_desc(plaza,"").
long_desc(pylon_a,"").
long_desc(pylon_b,"").
long_desc(pylon_c,"").
long_desc(quad,"A large grass field quarted by concrete sidewalks and bordered by large trees. A favorite destination of students and pets alike. Multiple buildings face into the field, most of them quite historic looking.").
long_desc(recipe,"A potion for invisibility: Bathe the bone of a dragon in pure light.  Distill charged bone with the wings of a fly.  Let cool before quaffing.").
long_desc(roof,"Not a place to be caught in a windstorm - the shingles are slippery and cracked.").
long_desc(roommate_room,"").
long_desc(secret_lab,"").
long_desc(ser_1st_floor,"").
long_desc(ser_2nd_floor,"").
long_desc(small_disk,"A small disk pulsates in your hand, glowing an toxic green color as it breathes slowly, a slight warm gasey feel pukes from the disk.").
long_desc(special_collections,"").
long_desc(tsc_patio,"An open area with birds chirping and hipsters drinking their coffee. You won't find any CS majors here as they're all in cavedwelling in Old Main.").
long_desc(tunnels_east,"").
long_desc(tunnels_north,"").
long_desc(tunnels_west,"").
long_desc(_,"").

puzzle(laser_lab):-has(goggles),!.
puzzle(laser_lab):-write("It is too dangerous to go in without eye protection."),nl,!,fail.
puzzle(secret_lab):-has(key),!.
puzzle(secret_lab):-write("The door is locked, so you can't get in"),nl,!,fail.
puzzle(green_beam):-has(potion),write("You quaff some potion so that Dr. Sundberg can't see you."),nl.
puzzle(green_beam):-write("Dr. Sundberg escorts you out saying 'Sorry, this is a restricted area'."),nl,!,fail.
puzzle(_).

read_words(W):-read_string(user_input,"\n\r","\n\r",_,L),split_string(L,"\t ","\t ",W).
