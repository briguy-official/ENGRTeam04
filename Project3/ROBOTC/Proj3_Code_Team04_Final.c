#pragma config(Sensor, S1,     touch,   sensorTouch)
#pragma config(Sensor, S2,     hallEffect, sensorDigitalIn)
#pragma config(Sensor, S3,     gyroSensor,     sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     sonar,  sensorSONAR)
#pragma config(Motor,  motorA, antennaMotor, tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorB, rightMotor, tmotorNXT, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorC, leftMotor, tmotorNXT, PIDControl, driveLeft, encoder)

#include "Proj3_Code_Team04.c" //input header file

task main() {
	int sonarValue = SensorValue(sonar);
	float mean = calibrateGyro();
	float distBallMarker = 7; //cm
	float binDist2Hall = 15; //cm
	int step = 10; //cm step for sensor function
	float originalX = 45;
	float originalY = 49;

	clearTimer(T1);
	initializeRobot();

	//LSTS Code
	startTask (receiveMessage);
	sendMessages();
	wait1Msec(2000);

	//WAIT FOR ORIGINAL LOCATION
	//while(((abs(robot[0].x)-0.0001) <= 0) && ((abs(robot[0].y)-0.0001) <= 0)) {
	//	wait1Msec(5000);
	//	sendMessages();
	//}

	if((robot[0].x < 600) && (robot[0].x > 400) && (robot[0].y < 600) && (robot[0].x > 400)) {
		originalX = robot[0].x / 10;
		originalY = robot[0].y / 10;
	}
	else {
		robot[0].x = 440;
		robot[0].y = 500;
	}

	mean = calibrateGyro();

	//turnDegrees(90, mean); //turn right
	turnDegrees(44.25, mean); //turn right 45 degrees - not exactly linear
	//function did not add raw sums correctly

	moveForward((205 - originalY)); //drive up from start to bin at y = 2.55m
	turnDegrees(90, mean); //turn right
	moveForward((35 - originalX + distBallMarker - step)); //drive to x axis, x = .55m
	beaconStep(step);

	beepThrice();
	moveForward(binDist2Hall); // move away to drop bin
	dispenseBin(); //A
	//sendMessages();

	moveForward(250 - 55 - distBallMarker - binDist2Hall);
	turnDegrees(90, mean); //turn right
	moveForward(113 - 55);
	turnDegrees(-90, mean); //turn left
	beaconStep(step);

	beepThrice();
	moveForward(binDist2Hall); // move away to drop bin
	dispenseBin(); //B
	//sendMessages();

	moveForward(298 - 250 + 40 - step - binDist2Hall); //35 is to go 35cm further
	turnDegrees(90, mean); //turn right
	moveForward(205 - 113);

	//bypass uneven terrain - begin
	turnDegrees(90, mean); //turn right
	moveForward(40);
	turnDegrees(-90, mean); //turn left

	beaconStep(step);
	//bypass uneven terrain - end

	beepThrice();
	moveForward(binDist2Hall); // move away to drop bin
	dispenseBin(); //C
	//sendMessages();

	moveForward(20 - binDist2Hall);
	turnDegrees(90, mean); //turn right
	moveForward(273 - originalX);
	turnDegrees(90, mean); //turn right
	moveForward(60 - originalY + 20);

	beepThrice();
	dispenseBin(); //Done

	sendMessages();
	wait(16);
	sendMessages();
	wait(16);
	sendMessages();
}
