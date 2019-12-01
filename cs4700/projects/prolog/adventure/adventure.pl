:- dynamic here/1.
:- dynamic has/1.
:- dynamic location/2.

:- set_prolog_flag(double_quotes,atom).

here(bedroom).

room(agricultural_science).
room(animal_science).
room(avenue).
room(bedroom).
room(bedroom_closet).
room(chemistry_lab).
room(common_room).
room(computer_lab).
room(elevator).
room(engr).
room(eslc_north).
room(eslc_south).
room(conference_center).
room(geology_building).
room(green_beam).
room(hackathon_judging).
room(hall).
room(hub).
room(kitchen).
room(laser_lab).
room(laundry_room).
room(library).
room(observatory).
room(old_main).
room(plaza).
room(quad).
room(roof).
room(roommate_room).
room(secret_lab).
room(ser_1st_floor).
room(ser_2nd_floor).
room(ser_basement).
room(ser_conference).
room(gas_lab).
room(special_collections).
room(tsc_patio).
room(tsc).
room(tunnels_east).
room(tunnels_north).
room(tunnels_west).

door(avenue,quad).
door(bedroom,bedroom_closet).
door(bedroom,hall).
door(eslc_north,chemistry_lab).
door(eslc_north,tsc_patio).
door(eslc_south,eslc_north).
door(hall,common_room).
door(hall,laundry_room).
door(hall,roommate_room).
door(hub,tunnels_west).
door(kitchen,hall).
door(library,plaza).
door(library,special_collections).
door(old_main,computer_lab).
door(plaza,avenue).
door(plaza,common_room).
door(plaza,engr).
door(plaza,ser_1st_floor).
door(quad,agricultural_science).
door(quad,animal_science).
door(quad,eslc_south).
door(quad,geology_building).
door(quad,old_main).
door(quad,tsc_patio).
door(quad,conference_center).
door(roof,elevator).
door(roof,green_beam).
door(roof,observatory).
door(ser_1st_floor,elevator).
door(ser_2nd_floor,elevator).
door(ser_2nd_floor,ser_conference).
door(ser_basement,elevator).
door(ser_basement,gas_lab).
door(ser_2nd_floor,laser_lab).
door(tsc,hub).
door(tsc_patio,tsc).
door(tunnels_east,ser_1st_floor).
door(tunnels_north,animal_science).
door(tunnels_north,tunnels_west).
door(tunnels_west,secret_lab).
door(tunnels_west,tunnels_east).

location(bone,geology_building).
location(book_a,special_collections).
location(book_b,special_collections).
location(book_c,special_collections).
location(bunsen_burner,chemistry_lab).
location(closet,eslc_south).
location(closet,eslc_south).
location(coat,green_beam).
location(combination_gas,ser_conference).
location(dirty_clothes, bedroom_closet).
location(dripping_stalagtite,tunnels_east).
location(energy_drink_mix,conference_center).
location(figurine,bedroom).
location(flask,chemistry_lab).
location(fly,roommate_room).
location(goggles,closet).
location(goggles,closet).
location(key,coat).
location(kitchen_stove, kitchen).
location(kitchen_trashcan,kitchen).
location(large_disk,pylon_a).
location(laser,laser_lab).
location(laundry_soap,laundry_room).
location(lost_homework,engr).
location(medium_disk,pylon_a).
location(movie, roomate_room).
location(note,bedroom).
location(note,bedroom).
location(paper_cup,conference_center).
location(participation_sticker,hackathon_judging).
location(pylon_a,secret_lab).
location(pylon_b,secret_lab).
location(pylon_c,secret_lab).
location(recipe,book_a).
location(sauce, kitchen).
location(small_disk,pylon_a).
location(spaghetti, kitchen).
location(tower_of_pizza_boxes, kitchen).
location(wash_machine,laundry_room).
location(money, bedroom).
location(vending_machine, tsc).

container(book_a).
container(closet).
container(coat).
container(kitchen_trashcan).
container(pylon_a).
container(pylon_b).
container(pylon_c).

equipment(bunsen_burner).
equipment(dripping_stalagtite).
equipment(kitchen_stove).
equipment(laser).
equipment(wash_machine).
equipment(vending_machine).

create_recipe(bunsen_burner,[flask,charged_bone,fly],potion).
create_recipe(dripping_stalagtite,[energy_drink_mix,paper_cup],energy_drink).
create_recipe(kitchen_stove,[spaghetti, sauce], cooked_spaghetti).
create_recipe(laser,[bone],charged_bone).
create_recipe(wash_machine,[dirty_clothes,laundry_soap],clean_clothes).
create_recipe(vending_machine, [money], bag_of_chips).

heavy(bunsen_burner).
heavy(closet).
heavy(kitchen_trashcan).
heavy(large_disk).
heavy(laser).
heavy(medium_disk).
heavy(pylon_a).
heavy(pylon_b).
heavy(pylon_c).
heavy(small_disk).
heavy(wash_machine).
heavy(vending_machine).

name(agricultural_science,"Agricultural Sciences Building").
name(animal_science,"Animal Science Building").
name(avenue,"A tree lined avenue").
name(bedroom,"Your bedroom").
name(bedroom_closet, "Your Bedroom's Closet").
name(bone,"large dragon bone").
name(book_a,"Corpus Hermiticum").
name(book_b,"War and Peace").
name(book_c,"Great Expectations").
name(bunsen_burner,"bunsen burner").
name(charged_bone,"charged dragon bone").
name(cheese, "Shredded Cheese").
name(chemistry_lab,"Student Chemistry Lab").
name(clean_clothes, "Your Clothes").
name(closet,"equipment closet").
name(coat,"Dr. Sundberg's lab coat").
name(combination_gas,"A scrap of paper with a sequence of numbers scribbled on it").
name(common_room,"Dorm common room").
name(computer_lab,"Student Computer Lab").
name(conference_center,"Eccles Conference Center").
name(cooked_spaghetti, "Lot's a Spaghetti").
name(dirty_clothes, "Your Dirty Clothes").
name(dripping_stalagtite,"Dripping stalagtite").
name(elevator,"Elevator").
name(energy_drink,"Magical energy drink").
name(energy_drink_mix,"Energy drink mix packet").
name(engr,"ENGR - The Main Engineering Building").
name(eslc_north,"Eccels Science Learning Center").
name(eslc_south,"Eccels Science Learning Center").
name(figurine,"alien figurine").
name(flask,"glass flask").
name(fly,"dead fly").
name(gas_lab, "The Get Away Special Lab").
name(geology_building,"Geology Building").
name(goggles,"dark saftey goggles").
name(green_beam,"The 'Grean Beam' enclosure").
name(hackathon_judging,"Hackathon Judging Room").
name(hall,"Hallway").
name(hub,"The Hub").
name(ice_cream, "Aggie Creamery").
name(key,"key").
name(kitchen,"Kitchen").
name(kitchen_trashcan,"trashcan").
name(large_disk,"large energy disk").
name(laser,"laser array").
name(laser_lab,"Laser Lab").
name(laundry_room,"Laundry Room").
name(laundry_soap,"Laundry Soap").
name(library,"Merill-Caizer Library").
name(lost_homework,"Some student's lost geometry homework.").
name(medium_disk,"medium energy disk").
name(movie, "Men in Black").
name(note,"note").
name(observatory,"Observatory").
name(old_main,"Old Main").
name(paper_cup,"paper cup").
name(participation_sticker,"HackUSU participation sticker").
name(plaza,"Engineering plaza").
name(potion,"potion").
name(pylon_a,"red pylon").
name(pylon_b,"blue pylon").
name(pylon_c,"green pylon").
name(quad,"The Quad").
name(recipe,"alchemical recipe").
name(roof,"On the roof of the SER Building").
name(roommate_room,"Your dormmate's room").
name(sauce, "Marinara Sauce").
name(secret_lab,"Dr. Sundberg's Secret Lab").
name(ser_1st_floor,"1st Floor of SER Building").
name(ser_2nd_floor,"2nd Floor of SER Building").
name(ser_basement,"Basement of the SER Building").
name(ser_conference,"The SER Conference Room").
name(small_disk,"small energy disk").
name(spaghetti, "Spaghetti").
name(special_collections,"Special Collections Room").
name(stove, "A Kitchen Stove.").
name(tower_of_pizza_boxes,"tower of pizza boxes").
name(tsc,"Taggart Student Center").
name(tsc_patio,"Patio of the TSC").
name(tunnels_east,"Underground Tunnels").
name(tunnels_north,"Underground Tunnels").
name(tunnels_west,"Underground Tunnels").
name(wash_machine,"Washing Machine").
name(money, "Money").
name(vending_machine, "Vending machine").

short_desc(agricultural_science,"Looks like a nice place to grab a bite.").
short_desc(animal_science,"a cozy-looking, white-bricked old building.").
short_desc(avenue,"A broad walkway lined with trees.").
short_desc(bedroom,"your bedroom - complete with dirty laundry and heaps of old homework, the sad remains of many hard fought battles waged over Dr. Sundberg's homework").
short_desc(bedroom_closet, "A cozy little room used for storing your valuables").
short_desc(bone,"a large dark bone").
short_desc(book_a,"a copy of 'Corpus Hermiticum' a book on alchemy").
short_desc(book_b,"a copy of 'War and Peace'").
short_desc(book_c,"a copy of 'Great Expectations'").
short_desc(bunsen_burner,"Piece of equipment commonly found in a laboratory.  It produces a single open gas flame.").
short_desc(charged_bone,"A charged piece of 'dragon' bone").
short_desc(cheese, "A variety blend of shredded cheese").
short_desc(chemistry_lab,"A lab with fume hoods and various chemical instuments").
short_desc(clean_clothes, "Clean clothes fresh from the wash").
short_desc(closet,"The equipment closet used to store extra materials for science experiments").
short_desc(coat,"A large white lab coat with lots of pockets").
short_desc(common_room,"A place where students gather for homework, food, and naps").
short_desc(computer_lab,"Many computers lined up together and a desk at the front of the room").
short_desc(conference_center,"A black, glassy building where this year's hackathon is being held").
short_desc(cooked_spaghetti, "The essence of perfection.").
short_desc(dirty_clothes, "Gritty clothes you should probably wash").
short_desc(dripping_stalagtite,"A sharp, fang-like stalagtite dripping sparkly water").
short_desc(elevator,"You are in a plain metal box.  There are buttons labeled with various locations.").
short_desc(energy_drink,"A magical energy drink").
short_desc(energy_drink_mix,"A magical energy drink mix packet with instructions on the back").
short_desc(engr,"A large building with many classrooms, you're surprised to see students wandering the halls at this time.").
short_desc(eslc_north,"You are on the north side of the ESLC.").
short_desc(eslc_south,"You are on the south side of the ESLC.").
short_desc(figurine,"Your roommate's alien figurine sitting atop a shelf.").
short_desc(flask,"a glass flask suitable for mixing reagents").
short_desc(fly,"the partially squished body of a dead house fly").
short_desc(gas_lab, "A place of space research and frendship").
short_desc(geology_building,"Large building with rocks and trees surrounding it").
short_desc(goggles,"dark eye protection left over from the 'Great American Eclipse'").
short_desc(green_beam,"Dr. Sundberg is standing at a large machine which is emitting a bright beam of green light.  You overhear a conversation indicating that he has set up a wormhole generator in his secret lab.  This will allow the alien invasion force to reach earth.").
short_desc(hackathon_judging,"Judges go from table to table to see the teams present their hacks.").
short_desc(hall,"Long pathway that has pictures hanging on wall").
short_desc(hub,"Smells of coffee and pizza linger in the air. Students congregate around tables slaving away at endless homework.").
short_desc(key,"an ornate key glowing with alien energies").
short_desc(kitchen,"A small room containing the bare essentials, including a leaning tower of pizza boxes").
short_desc(kitchen_trashcan,"This is the trashcan that resides in the kitchen.").
short_desc(large_disk,"a large disk glowing with alien energy").
short_desc(laser,"Pulsating with energy, this laser could be used to imbue something with energy").
short_desc(laser_lab,"Lasers shine in a beautiful array of cornea charing horror, good thing you have goggles on!").
short_desc(laundry_room,"A place for doing laundry").
short_desc(laundry_soap,"Used for washing dirty clothes").
short_desc(library,"Endless floors of books full of knowledge. A smiling librarian greets you as you enter, \"welcome to the library\" she says.").
short_desc(lost_homework,"The abandoned pages call out to a grader, a grader who will never see them.").
short_desc(medium_disk,"a medium sized disk glowing with alien energy").
short_desc(movie, "A movie about policing and monitoring aliens").
short_desc(note,"a handwritten note from your roommate").
short_desc(observatory,"A tower where you can stargaze.").
short_desc(old_main,"The building is full of nerdy looking people.").
short_desc(paper_cup,"A paper cup sporting a blue and purple wavey pattern out of the 90s").
short_desc(participation_sticker,"An awesome, octogon-shaped sticker that says 'HackUSU - I demoed'").
short_desc(plaza,"A large open space between engineering buildings").
short_desc(potion,"An oily black potion").
short_desc(pylon_a,"a glowing red pyramid shaped structure").
short_desc(pylon_b,"a glowing blue pyramid shaped structure").
short_desc(pylon_c,"a glowing green pyramid shaped structure").
short_desc(quad,"four large fields split up by sidewalks").
short_desc(recipe,"a page from 'Corpus Hermiticum' containing a recipe for an invisibility potion").
short_desc(roof,"the roof of the dorm building.").
short_desc(roommate_room,"its even messier than your room!").
short_desc(sauce, "Rich and flaverfull Marinara Sauce").
short_desc(secret_lab,"a secret lab?! This must be where Dr. Sundberg is hiding his secret!").
short_desc(ser_1st_floor,"The bottom floor of the SER building. Nothing too exciting is happening here.").
short_desc(ser_2nd_floor,"The 2nd floor of the SER building. You can see flashing lights near the laser lab room.").
short_desc(ser_basement,"The basement of the SER building.").
short_desc(small_disk,"a small disk glowing with alien energy").
short_desc(spaghetti, "The food of champions.").
short_desc(special_collections,"the 'special' section of the library. Holds the more important and classical books.").
short_desc(stove, "A kitchen stove for cooking food.").
short_desc(tower_of_pizza_boxes,"A stack of (hopefully) empty pizza boxes").
short_desc(tsc,"community center for students, faculty, and alumni").
short_desc(tsc_patio,"a place to sit an study or eat outside the TSC.").
short_desc(tunnels_east,"The underground tunnels are a confusing place.  I hope you don't get lost.").
short_desc(tunnels_north,"The underground tunnels are a confusing place.  I hope you don't get lost.").
short_desc(tunnels_west,"The underground tunnels are a confusing place.  I hope you don't get lost.").
short_desc(wash_machine,"An old beat up washing machine used for cleaning students' foul smelling clothes").
short_desc(money, "A couple of dollars.").
short_desc(vending_machine, "A vending machine located in the TSC.").

long_desc(agricultural_science, "There is a line of students waiting to eat at the cafe. Everyone seems to be in a hurry.").
long_desc(avenue,"A myriad of people walk every which way along the avenue.  All are seemingly unaware of their imminent destruction at Dr.Sundberg's hand.").
long_desc(bedroom,"The college dorm room where you currently reside. These walls have witnessed more late night study sessions than you care to consider. The bed is soaked with the dried tears of uncounted tests failed. Fortunately, the building is aired frequently enough that you can't still smell the years of dirty laundry that have sat in the closet.").
long_desc(bedroom_closet, "Four shelves stand before you, piles of your clothes at your feet, its quiet cramped in here.").
long_desc(bone,"The femur bone from a dragon discovered in the hills of St. Ignatius, Montana.").
long_desc(book_a,"An ancient work on alchemy containing many magical formulae.").
long_desc(book_b,"A seemingly very old copy of War and Peace. A classic story about a Russian family during the invasion of Napoleon Bonaparte.").
long_desc(book_c,"The classic story of an orphan boy named Pip from the marshes of Kent.").
long_desc(bunsen_burner,"A Bunsen burner, named after Robert Bunsen, is a common piece of laboratory equipment that produces a single open gas flame, which is used for heating, sterilization, and combustion.").
long_desc(charged_bone, "A piece of dragon bone imbued with energy from the laser lab.").
long_desc(cheese, "A combiniation of colby, montery jack, and cheddar cheese.").
long_desc(chemistry_lab,"A laboratory for research in chemistry. You see a few goofy looking students with big green goggles mixing chemicals.").
long_desc(clean_clothes, "These are all you have of value in this world but at least they are clean.").
long_desc(closet,"Amid all the extra equipment and junk in the closet, you notice some saftey goggles that are just your size.").
long_desc(coat,"A spiffy looking lab coat. The pockets are lined with some kind of residue from Dr. Sundberg's experiments. It smells like aliens... Gross!").
long_desc(common_room,"The common room in the SER building. You see a few scattered couches, benches, and tables. It smells like Little Cesears Pizza here...").
long_desc(computer_lab,"The room is filled with the glow and hum of many computers and the feverish typing of college students.").
long_desc(conference_center,"Hundreds of geeky-looking students exitedly walk about with free food in hand. Rooms are filled with tables of students with their laptops or impressive desktop rigs. Some code with headphones while sipping Mountain Dew. Others laugh or intently plan with team-mates around their table. All are settled in for a long night of fun and hacking.").
long_desc(cooked_spaghetti, "Al dente spaghetti dressed up with the best sauce imaginable. If there ever was a reason to save the world, this is it.").
long_desc(dirty_clothes, "These are all you have of value in this world are these crusted gritty clothes, that need to be washed.").
long_desc(dripping_stalagtite,"This formation of calcium salts appears to have been there for a long time. There is something entrancing about the sparkling water dripping at about 3 Hertz.").
long_desc(elevator,"A large metal container used to transport people and large objects to different floors in a building.").
long_desc(energy_drink,"An energy drink made from magical water").
long_desc(energy_drink_mix,"Zoom Mango Rush flavor formulated with B vitamins and midichlorians. Instructions: just add pure water that has never been in human plumbing. GMO and gluten free.").
long_desc(engr,"There is a display for Orbital ATK and chairs to collapse into after class. You hear your footsteps echoing down the halls as you walk.").
long_desc(eslc_north,"A large open area where you can see chemistry labs , and the doors out to the TSC patio.").
long_desc(eslc_south,"Smaller area lined with classrooms, labs, and closets. You notice a lot of students are wearing lab coats and goggles.").
long_desc(figurine,"Your roommate's alien figurine.  They've been obsessed with aliens since you first met.  You always wondered why, but after reading that note about Dr.Sundberg, it is all beginning to make sense.").
long_desc(flask,"A small container made of glass that is wide at the base and narrow at the neck.  A purple liquid seems to have been left over from a previous experiment.").
long_desc(fly,"Scientifically known as Syrphus Ribessi, this nuisance enjoys long buzzes around human faces and landing on perfectly good food. This particular house fly met an untimely death by squishing.").
long_desc(gas_lab,"Founded in 1976, the Get Away Special team is a student-driven, space research team which has established and upheld Utah State University's reputation as the university that has flown more experiments into space than any other university in the world.").
long_desc(geology_building,"An old looking building that secretly hides the math department. The only reason people want to go in, is to see the large 'dinosaur' bone exhibit they have in there.").
long_desc(goggles,"Specialized Eclipse goggles that allow you to stare at the sun, or intense lasers without going blind.").
long_desc(green_beam,"Dr. Sundberg is standing at a large machine which is emitting a bright beam of green light.  You overhear a conversation indicating that he has set up a wormhole generator in his secret lab.  This will allow the alien invasion force to reach earth.").
long_desc(hackathon_judging,"The students have made some pretty sweet projects. Thankfully, Dr. Sundberg is not a judge.").
long_desc(hall,"A narrow area or passage that connects rooms of an edifice.  The passage is laid with dark red carpeting with pictures hanging on its walls.").
long_desc(hub,"Choose from 9 different areas to eat at while enjoying a large seating area, which is perfect for hanging out and studying.").
long_desc(key,"You feel the alien energy flowing from the key. Could it be? Have you been chosen as the next wielder of the Keyblade? You hold out your hand to the side, but sadly, nothing happens. It's just a normal alien key....").
long_desc(kitchen,"There are an assortment of pots and pans. Someone is cooking your favorite food but it doesn't look like they are going to share.").
long_desc(kitchen_trashcan,"A black, round, plastic container lined with a flexible bag. It's as generic as can be, lacking any logo or branding.").
long_desc(large_disk,"a large disk on the bottom of the red pylon. You worked out today so if there isn't anything on top of it, you could probably move it...").
long_desc(laser,"A rather powerful laser for research. Probably shouldnt look into it.").
long_desc(laser_lab,"You imagine yourself as a secret agent in Mission Impossible flipping and sliding around the room to avoid the lasers... Maybe then you could get a date.").
long_desc(laundry_room,"A dimly lit room that has a musty smell from all the laundry piling up.").
long_desc(laundry_soap,"This soap looks like it has been sitting here for years without being used.").
long_desc(library,"Endless floors of books full of knowledge. A smiling librarian greets you as you enter, 'Welcome to the library!'").
long_desc(lost_homework,"This homework appears to be a geometric proof of the origin of the green beam that is sometimes seen in the sky. The proof shows that the beam originates on the roof of the SER building.").
long_desc(medium_disk,"a medium sized disk in between the small and large disks on the red pylon. It looks like you can move it if there isn't anything on top of it...").
long_desc(movie, "Stars Will Smith and Tommy Lee Jones as members of a secret task force dedicated to protecting earth from alien invaders and earth's inhabitants from any knowledge of aliens. Your dormmate must have been conducting research").
long_desc(note,"In the handwriting of your roommate is hastily scrawled: 'You've got to help.  Dr. Sundberg is an alien and wants to take over the world.  I think he is on to me, you are the only hope left! Try to find out what he is doing with the green beam.'").
long_desc(observatory,"Welcome to the Atmospheric Lidar Observatory. Here you will find information about the 'Green Beam' at Utah State University.").
long_desc(old_main,"The building has four floors, and is the location of much pain during the Evil Dr. Sundber's class.  Few can navigate their way to the 4th floor where dreams become computer programs.").
long_desc(paper_cup,"Paper cups are great for beverages.").
long_desc(participation_sticker,"This sticker would look really cool on the back of your laptop. All the cool kids have their laptops plastered in these.").
long_desc(plaza,"A well known spot for Pokemon Go players. It is home to 2 Gyms and 3 pokestops. Terf wars have been known to occur here, so avoid wearing solid blue, yellow or red clothes to avoid potential conflict.").
long_desc(pylon_a,"A red platform with a rod coming out of the middle that comes up to your chest. There are three disks that have been placed here on the rod from smallest to biggest forming a pyramid.").
long_desc(pylon_b,"A blue platform with a rod coming out of the middle that comes up to your chest. It looks like you could put something on the rod...").
long_desc(pylon_c,"A green platform with a rod coming out of the middle that comes up to your chest. It looks like you could put something on the rod...").
long_desc(quad,"A large grass field quarted by concrete sidewalks and bordered by large trees. A favorite destination of students and pets alike. Multiple buildings face into the field, most of them quite historic looking.").
long_desc(recipe,"A potion for invisibility: Bathe the bone of a dragon in pure light.  Distill charged bone with the wings of a fly.  Let cool before quaffing.").
long_desc(roof,"Not a place to be caught in a windstorm - the shingles are slippery and cracked.").
long_desc(roommate_room,"Not quite as messey as yours, your roommate's room has a mini fridge stocked with Dr. Pepper. You see the sun shining through the locked window. ").
long_desc(sauce, "Marinara Sauce").
long_desc(secret_lab,"You notice your surroundings are almost identical to the cartoon Dexter's laboratory. There are many experiments being done around the room.").
long_desc(ser_1st_floor,"...even though I said nothing exciting happens here, you want to know more? Sorry, I got nothing...").
long_desc(ser_2nd_floor,"The main part of the 2nd floor is the laser lab. The students in there experiment with what they can cut, burn, or imbue with magical energy with lasers.").
long_desc(ser_basement, "Behind every door is another labrotory. The hallways are strewn with machines that appear to belong to a mad scientist although it's probably only Dr. JR Dennison").
long_desc(small_disk,"A small disk pulsates in your hand, glowing an toxic green color as it breathes slowly, a slight warm gasey feel pukes from the disk.").
long_desc(spaghetti, "These long thin pasta noodles are a staple for a student on a budget. So much better than ramen, can be combined with various sauces for maximum effect.").
long_desc(special_collections,"a small section of the library that is home to all sorts of extrordiary books. You can read up on Russian Literature, Classic Dickens, Alchemy, and even more!").
long_desc(stove, "A stove splattered with various substances that you assume, or at least hope used was food.").
long_desc(tower_of_pizza_boxes,"Domino's, Pizza-Hut, Little Ceaser's and more. All are rendered equal in this towering graveyard of cardboard.").
long_desc(tsc,"This massive building is the perfect place to go to spend way too much money on overpriced things... You'll find students eating, studying, socializing, and lamenting their massive student debts.").
long_desc(tsc_patio,"An open area with birds chirping and hipsters drinking their coffee. You won't find any CS majors here as they're all in cavedwelling in Old Main.").
long_desc(tunnels_east,"The tunnel seems to go on forever. Its dark and you are having a hard time seeing anything. You try to not let your imagination take over as you think you hear someone following you...").
long_desc(tunnels_north,"The tunnel seems to go on forever. Its dark and you are having a hard time seeing anything. You try to not let your imagination take over as you think you hear someone following you...").
long_desc(tunnels_west,"The tunnel seems to go on forever. Its dark but you see what looks like a door off to your right. You try to not let your imagination take over as you think you hear someone following you...").
long_desc(wash_machine,"You open the door and to your surprise the washing machine is empty and available to use. You shut the door again.").
long_desc(money, "A couple of dollars found on your dresser. You've heard it can be exchanged for goods and services.").
long_desc(vending_machine, "The vending machine is stocked with a large variety of chips. The machine requires money to use, of course.").

puzzle(laser_lab):-has(goggles),!.
puzzle(laser_lab):-write("It is too dangerous to go in without eye protection."),nl,!,fail.
puzzle(secret_lab):-has(key),!.
puzzle(secret_lab):-write("The door is locked, so you can't get in"),nl,!,fail.
puzzle(gas_lab):-has(combination_gas),!.
puzzle(gas_lab):-write("The light's are off and the door is locked. There must not be any friends in the GAS Lab right now, you need the combination to unlock the door").
puzzle(green_beam):-has(potion),write("You quaff some potion so that Dr. Sundberg can't see you."),nl.
puzzle(green_beam):-write("Dr. Sundberg escorts you out saying 'Sorry, this is a restricted area'."),nl,!,fail.
puzzle(hackathon_judging):-has(energy_drink),write("With the help of your magical energy drink, you were able to finish up your project."),nl.
puzzle(hackathon_judging):-write("You were too tired to finish your project, so you can't participate in judging."),nl,!,fail.
puzzle(_).

%Below are helper functions to display the towers of hanoi game
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

%invoke display_pylons to pretty print the final puzzle.
display_pylons:-write("---A------B------C---"),nl,display_top, display_middle, display_bottom,write("---------------------"),nl,!.

%NLP
article([the|X]-X).
article([a|X]-X).
article([an|X]-X).

verb(place,look,[look|X]-X).
verb(place,look,[study|X]-X).
verb(place,look,[look,around|X]-X).

verb(thing,study,[look|X]-X).
verb(thing,study,[study|X]-X).
verb(thing,study,[look,at|X]-X).

verb(place,move,[go|X]-X).
verb(place,move,[go,to|X]-X).
verb(place,move,[walk|X]-X).
verb(place,move,[walk,to|X]-X).
verb(place,move,[move|X]-X).
verb(place,move,[move,to|X]-X).

verb(thing,take,[take|X]-X).
verb(thing,take,[grab|X]-X).
verb(thing,take,[get|X]-X).
verb(thing,take,[pick,up|X]-X).

verb(thing,make,[make|X]-X).
verb(thing,make,[create|X]-X).

verb(thing,put,[put|X]-X).
verb(thing,put,[drop|X]-X).
verb(thing,put,[put,down|X]-X).
verb(thing,put,[lay,down|X]-X).

verb(thing,transfer,[move|X]-X).

noun(place,agricultural_science,[agricultural,science,building|X]-X).
noun(place,animal_science,[animal,science,building |X]-X).
noun(place,avenue,[avenue|X]-X).
noun(place,bedroom,[bedroom |X]-X).
noun(place,bedroom,[room |X]-X).
noun(place,bedroom_closet,[closet |X]-X).
noun(place,chemistry_lab,[chemistry,lab |X]-X).
noun(place,common_room,[common,room |X]-X).
noun(place,computer_lab,[computer,lab |X]-X).
noun(place,conference_center,[conference,center |X]-X).
noun(place,elevator,[elevator |X]-X).
noun(place,engr,[engineering,building |X]-X).
noun(place,eslc_north,[eslc |X]-X).
noun(place,eslc_south,[eslc |X]-X).
noun(place,geology_building,[geology,building |X]-X).
noun(place,green_beam,[enclosure |X]-X).
noun(place,hackathon_judging,[hackathon,judging |X]-X).
noun(place,hall,[hall |X]-X).
noun(place,hub,[hub |X]-X).
noun(place,kitchen,[kitchen |X]-X).
noun(place,laser_lab,[laser,lab |X]-X).
noun(place,laundry_room,[laundry |X]-X).
noun(place,library,[library |X]-X).
noun(place,observatory,[observatory |X]-X).
noun(place,old_main,[old,main |X]-X).
noun(place,plaza,[plaza |X]-X).
noun(place,quad,[quad |X]-X).
noun(place,roof,[roof |X]-X).
noun(place,roommate_room,[roommate,room |X]-X).

noun(place,secret_lab,[secret,lab |X]-X).
noun(place,ser_1st_floor,[ser |X]-X).
noun(place,ser_2nd_floor,[second,floor |X]-X).
noun(place,ser_basement,[basement |X]-X).
noun(place,ser_conference,[conference,room |X]-X).
noun(place,gas_lab,[gas,lab |X]-X).
noun(place,special_collections,[special,collections |X]-X).
noun(place,tsc_patio,[patio |X]-X).
noun(place,tsc,[tsc |X]-X).
noun(place,tunnels_east,[tunnels |X]-X).
noun(place,tunnels_north,[tunnels |X]-X).
noun(place,tunnels_west,[tunnels |X]-X).

noun(thing,bone,[bone |X]-X).
noun(thing,book_a,[corpus,hermiticum |X]-X).
noun(thing,book_b,[war,and,peace |X]-X).
noun(thing,book_c,[great,expectations |X]-X).
noun(thing,bunsen_burner,[burner |X]-X).
noun(thing,closet,[closet |X]-X).
noun(thing,coat,[coat |X]-X).
noun(thing,combination_gas,[scrap,of,paper |X]-X).
noun(thing,dirty_clothes, [clothes |X]-X).
noun(thing,energy_drink, [energy,drink |X]-X).
noun(thing,energy_drink_mix, [energy,drink,mix |X]-X).
noun(thing,figurine,[figurine |X]-X).
noun(thing,flask,[flask |X]-X).
noun(thing,fly,[fly |X]-X).
noun(thing,goggles,[goggles |X]-X).
noun(thing,key,[key |X]-X).
noun(thing,kitchen_stove, [stove |X]-X).
noun(thing,kitchen_trashcan,[trashcan |X]-X).
noun(thing,large_disk,[large,disk |X]-X).
noun(thing,laser,[laser |X]-X).
noun(thing,laundry_soap,[soap |X]-X).
noun(thing,lost_homework,[homework |X]-X).
noun(thing,medium_disk,[medium,disk |X]-X).
noun(thing,movie, [movie |X]-X).
noun(thing,note,[note |X]-X).
noun(thing,paper_cup, [paper,cup |X]-X).
noun(thing,participation_sticker, [participation,sticker |X]-X).
noun(thing,pylon_a,[red,pylon |X]-X).
noun(thing,pylon_b,[blue,pylon |X]-X).
noun(thing,pylon_c,[green,pylon |X]-X).
noun(thing,recipe,[recipe |X]-X).
noun(thing,sauce, [sauce |X]-X).
noun(thing,small_disk,[small,disk |X]-X).
noun(thing,spaghetti, [spaghetti |X]-X).
noun(thing,tower_of_pizza_boxes, [boxes |X]-X).
noun(thing,wash_machine,[washing,machine |X]-X).
noun(thing,money, [money |X]-X).
noun(thing,vending_machine, [vending,machine |X]-X).
noun(thing,potion, [potion |X]-X).
noun(thing,cooked_spaghetti, [spaghetti |X]-X).
noun(thing,charged_bone, [bone |X]-X).
noun(thing,clean_clothes, [clothes |X]-X).
noun(thing,bag_of_chips, [chips |X]-X).

object(Type,N,S1-S3):-article(S1-S2),noun(Type,N,S2-S3).
object(Type,N,S1-S2):-noun(Type,N,S1-S2).

command([V,O],In) :- verb(Type,V,In-S),object(Type,O,S-[]).


%Game loop
read_words(W):-read_string(user_input,"\n\r","\n\r",_,L),split_string(L,"\t ","\t ",W).

play :- read_words(W),command(C,W),P=..C,P,win.
