Simple code based on CapacitiveSensor library from
https://github.com/PaulStoffregen/CapacitiveSensor
http://playground.arduino.cc/Main/CapacitiveSensor

Connect 2 resistor to Arduino at slot 2, 3, 4, 5. 2 and 5 is the sensor; 3 and 4 is the ground. Ground can be the same slot but I don't recommend it. Use Wire to connect sensor to something metal that you will tap. I used aluminum foil but in the future I plan to use a thin sheet of metal.

I use CapacitiveSensorSketch.ino to check what my threshold should be to activate the touch,
then change the threshold in OsuCode.ino. OsuCode.ino is the one that sends keypress and keyrelease.

I am doing this on a Arduino Yun with 2 300K Ohm resistors.
With higher value resistors there will be more delay but it will be more accurate, and vice versa.

You can also determine how many samples it take each time seen in line 22 of OsuPad.ino
sensors[x].capacitiveSensor(10)
I am taking 10 samples, similar to resistors, more sample more delay more accurate, vice versa.

I found 300k Ohm at 10 samples to be good for me, the delay is around 0~1 ms and rarely 2ms, and sends the key events pretty perfectly for me.

How to read the output on serial monitor
	CapacitiveSensorSketch.ino sample output
		(1) (2) (3)
		1	16	4
		1	12	6
		0	18	6
		1	17	4
		1	178	4
		1	164	6
		1	153	6
		1	172	4
		(1) is this time it took to get a reading from the sensor.
		(2) and (3) is the number the CapacitiveSensor library returns for the capacitiveSensor() number, it doesn't have a unit, and is used to determine the threshold for a touch.
		You can see (2)'s value increased a lot which means my finger is touching the pad, in this case, I might set the threshold to 130.

	OsuPad.ino sample output
		(4) (5) (6) (7)
		x down	1	143
		x keyup	1	46
		z down	1	147
		z keyup	0	67
		(4) is the key, (5) is the action, (6) is the delay, (7) is same (2) and (3) from above
		in this example my threshold is set to 75


Note: idk how the capacitiveSensor() work but I unconnected my Arduino overnight and the next day the threswhold had to be changed.

I'm pretty sure this is the future of osu(at least for me).
I got a new highest pp with A using this, and this is saying something because my top 20 scores are 4xA, 5xB, 10xC, and 1xD.