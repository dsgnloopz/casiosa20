# casiosa20
Hacked Casio SA 20 into a midi Keyboard


Hey, this is my first documented project. i have been researching and found different sources to actually build
the code that works with this device. im still tweaking stuff to add more features but its actually working as 
it is now, so i decided to publish this partial result and continue updating it. so, what i did was to take away
the original chip from an old non working SA20 i got from a friend as a gift and the power circuit. also took off
the speakers and the original inputs/outputs. i worked arround to figure the matrix scanning for the keys and buttons
and programmed it to send actual notes and channel select from arduino. in this case i used the Uno and rebuilt it in
a custom board. im working on the files to order some pcbs and leave the design files here, but it still not ready.
added a footswitch input, a joystick for mod and pitch wheel and a velocity pot. i figured out that the keys matrix was
84 and worked arround to use the buttons that originally selects sounds from the tone bank as another matrix 83. you 
may note there are only 17 buttons, so there are still 7 digital inputs that can be added. im just thinking of the best
way to use em, by now they are still hiden :D and im only using the 17 buttons for selecting channels 2 to 17 for channel
and left the first button as a kind of Shift button to select a B mode for the channel buttons and control de octave 
up/down as to use the lasting btns as cc maybe...? still working on it.

by now ill leave here the code as it is now, as i mentioned before it is pretty much ready to upload, connect and play with the new instrument.
