# casiosa20 Midi Mod
Hacked Casio SA 20 into a midi Keyboard


Hey, this is my first documented project. i have been researching and found different sources to actually build
the code that works with this device. im still tweaking stuff to add more features but its actually working as 
it is now, so i decided to publish this partial result and continue updating it. so, what i did was to take away
the original chip from an old non working SA20 i got from a friend as a gift and the power circuit. also took off
the speakers and the original inputs/outputs. i worked arround to figure out the matrix scanning for the keys and buttons
and programmed it to send actual notes and channel select from arduino. in this case i used the Uno and rebuilt it in
a custom board. im working on the files to order some pcbs and leave the design files and schematics here, but it still not ready.
added a footswitch input, a joystick for mod and pitch wheel and a velocity pot. i figured out that the keys matrix was
8by4 and worked arround to use the buttons that originally selects sounds from the tone bank as another matrix 8by3 readed with a 74hc595 shift register. you 
may note there are only 17 buttons, so there are still 7 digital inputs that can be added. im just thinking of the best
way to use em, by now they are still hiden :D and im only using the 17 buttons for selecting channels 2 to 17 for channel
and left the first button as a kind of Shift button to select a B mode for the channel buttons and control de octave 
up/down as to use the lasting btns as cc maybe...? still working on it.

ill quote here the projects im based to build my frankencode. used parts from here and there to get the desired result

I have used part of the evan kale cheap midi keyboard, strongly recommend you to check the full instructable, pretty educational. unfortunately i was not able to find it anymore....evan kale content is always up and down, idk why? but google it you may find it :
https://github.com/evankale/ArduinoMidiPiano


also used this project to refference and build my own, i strongly suggest you to check this out. he even has a second part adding pressure based velocity and aftertouch and a third part adding usb midi support:

http://www.codetinkerhack.com/2012/11/how-to-turn-piano-toy-into-midi.html?m=1


last but not least used this code from a german site where i did not understood anything but ended figuring out the code for joystick workarround

//edit: i was unable to find the site where i found the joystick code :( but there are still some parts of the code that reffers to that project, so if you know the link please let me know so that i can quote it here :D


and thats it , those where nearly all the refferences i used to build this project. i would like to do a spetial mention to the Notes And Volts youtube channel where i learnt a lot about midi messages and midi stuff. highly recomended.



by now ill leave here the code as it is now, as i mentioned before it is pretty much ready to upload, connect and play with the new instrument.



Visit and follow my Instagram pages to support and check demos, pictures and other media related to my projects that can not be posted here : @desgeneradotv (http://www.instagram.com/desgeneradotv) and @dsgnloopz (http://www.instagram.com/dsgnloopz)  
