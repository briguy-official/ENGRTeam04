#pragma config(Sensor, S1,     touch,          sensorTouch)
#pragma config(Sensor, S2,     hallEffect,     sensorDigitalIn)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          piston,        tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define BATTERY_THRESHOLD 1000

int flag = 0;

typedef struct location_struct{
	float x;
	float y;
} location;

void initializeRobot()
{
	displayCenteredTextLine(6, "Team04");
	clearTimer(T1);							//clear timer for LSTS
	nMotorEncoder[motorA] = 0;	//clear motor encoders
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	wait1Msec(100);
	resetMotorEncoder(motorA);	//zero motor encoders
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	playSound(soundBeepBeep);		//beep
	wait1Msec(500);							//wait half sec
	stopAllMotors();
	return;
}

//forward(sec); //already defined
//backward(sec); //already defined

void beepThrice() {
	int i = 0;
	for(i = 0; i < 3; i++) {
		playSound(soundBlip);
		wait1Msec(100);
	}
	return;
}

void dispenseBin() {
	wait1Msec(10);

	nMotorEncoderTarget[motorA] = 120;
	motor[motorA] = 5;

	while ((nMotorRunState[motorA] != runStateIdle)) //while the encoder wheel turns one revolution
	{
		beepThrice();
	}
	motor[motorA] = 0;

	wait1Msec(100);
	forward(360, degrees, 10); // move forward one second to move out of way
	wait1Msec(1000);
}

void sendMessages() {
	//while(time1[T1] > 1500) { //15 seconds for final, currently 1
	sendMessage(150); //height off the ground of the ALV marker in mm
	wait1Msec(100);
	//if (time1[T1] < 15000) {}
	return;
}

task receiveMessage()
{
	location robot[3];			// past 3 locations
	int error[3];					// past 3 error messages
	int i = 0;							// iterated variable
	while(true)
	{
		if(bQueuedMsgAvailable())     //check if message is available
		{
			wait1Msec(100);
			error[i] = messageParm[0];
			nxtDisplayClearTextLine(1);

			switch(error[i]) {
			case 1: //00000001b : //bitwise operators?
				nxtDisplayClearTextLine(1);
				nxtDisplayClearTextLine(2);
				nxtDisplayCenteredTextLine(1, "No error.");
				break;
			case 2: //00000010b :
				nxtDisplayCenteredTextLine(1, "Manual override");
				nxtDisplayCenteredTextLine(2, "engaged.");
				break;
			case 4: //00000100b :
				nxtDisplayCenteredTextLine(1, "Out of bounds");
				nxtDisplayCenteredTextLine(2, "detected.");
				nxtDisplayCenteredTextLine(5, "System effected");
				break;
				// Multiple errors could exist in a message; therefore, processing errors as flags is recommended.
				//Error message > 4 results in X, Y coordinates returned as (0, 0)
			case 8 : //00001000b :
				nxtDisplayCenteredTextLine(1, "No ALV marker");
				nxtDisplayCenteredTextLine(2, "seen.");
				nxtDisplayCenteredTextLine(5, "System effected");
				break;
			case 16 : //00010000b :
				nxtDisplayCenteredTextLine(1, "LSTS system error."); //not in view
				nxtDisplayCenteredTextLine(5, "System effected");
				break;
			case 32 : //00100000b :
				nxtDisplayCenteredTextLine(1, "Busy");
				nxtDisplayCenteredTextLine(2, "- request again later.");
				nxtDisplayCenteredTextLine(5, "System effected");
				break;
			}
			robot[i].x = messageParm[1]; //mm
			robot[i].y = messageParm[2]; //mm
			nxtDisplayCenteredTextLine(3, "X : %d", robot[i].x);
			nxtDisplayCenteredTextLine(4, "Y : %d", robot[i].y);
			wait1Msec(10); // wait 10 mseconds
			if(i == 2) {
				i = 0;
			}
			else {
				i++;
			}
			flag = 1;
			ClearMessage();
			clearTimer(T1);
		}
		else
		{
			wait1Msec(50); //not ready
		}
	}
}

task moveTo() {

}


task main()
{
	initializeRobot();
	int speed = 0;          // Will hold the speed of the motors.
	int sonarValue = 0;     // Will hold the values read in by the Sonar Sensor.
	int distance = 35;      // Specified distance to be at 35 centimeters.
	//int map[275][365]; //cm NO MEMORY
	// -1 = deep caverns
	// 0 = normal
	// 1 = rough terrain
	// 2 = large hazards
	// 40 - special locations
	clearTimer(T1);

	startTask (receiveMessage);
	sendMessages();
	//turnLeft(180, degrees, 25); //TASK 1
	//forward(30);

	// forward(30, seconds, 25); // TASK 3

	dispenseBin(); // TASK 5

	// TASK 4
	int hallVal = SensorValue(hallEffect);

	while(abs(SensorValue(hallEffect) - hallVal) <= 20) {
		forward(50, milliseconds, 50);
	}
	stopAllMotors();
	beepThrice();
	//dispenseBin(); // NOT FOR POC

	/* // TASK 6
	sendMessages();
	*/


	/* //SONAR *********
	sonarValue = SensorValue(sonar);

	speed = (SensorValue(sonar) - distance);
	// 'speed' is set to the reading of the Sonar Sensor - some distance in centimeters

	if(speed > 100)
	{
	speed = 100;  // Check to see if calculated speed is greater than 100, if so make it 100.
	}
	*/ // END OF SONAR *****
}
