#pragma config(Sensor, S1,     touch,          sensorTouch)
#pragma config(Sensor, S2,     hallEffect,     sensorDigitalIn)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor, motorB, rightMotor, tmotorNXT, PIDControl, driveRight, encoder)
#pragma config(Motor, motorC, leftMotor, tmotorNXT, PIDControl, driveLeft, encoder)

#define BATTERY_THRESHOLD 1000

typedef struct location_struct {
	float x;
	float y;
} location;

typedef struct path_struct {
	location first;
	location second;
} path;

void initializeRobot()
{
	string brickName = "Team51";
	clearTimer(timer1);
	resetMotorEncoder(motorB);
	resetMotorEncoder(motorC);
	playSound(soundBeepBeep);
	wait1Msec(50);
	stopAllMotors();
	return;
}

// 0 = left, 1 = right

int followLine(int side) {
	int sideOfLine = side;
	// lineTrackLeft(sensorName, threshold, speedPrimary, speedSecondary);
	// lineTrackRight(sensorName, threshold, speedPrimary, speedSecondary);

	if ((SensorValue(sonar) >= 525) && (sideOfLine == 0)) { //white
		turnRight(75); //turn right
		wait(0.50);
		sideOfLine = 0;
	}
	else if ((SensorValue(sonar) >= 525) && (sideOfLine == 1)) {
		turnLeft(75); //turn left
		wait(0.50);
		sideOfLine = 1;
	}
	else if ((SensorValue(sonar) < 525) && (sideOfLine == 0)) { //black
		sideOfLine = 1; //came from left, now turn left
		turnRight(75); //turn right
		wait(0.50);
	}
	else if ((SensorValue(sonar) < 525) && (sideOfLine == 1)) {
		sideOfLine = 0; //came from right, now turn right
		turnLeft(75); //turn left
		wait(0.50);
	}
	else {
		sideOfLine = 0;
	}
	return sideOfLine;
}

task main()
{
	initializeRobot();
	path robot;
	while(1==1)
	{
		int side = 0;
		int left = 0;
		int right = 0;

		while (SensorValue(sonar) < 15) {
			turnLeft(75);
		}

		forward(75);

		if((SensorValue(sonar) <= 18)){
			turnLeft(75);
		}
		else {
			side = followLine(side);
			if (side == 1) {
				right = right + 1;
			}
			else {
				right = 0;
				if (right == 7) {
					side = 0;
				}
			}
		}
		//wait1Msec(100);
		//if (nImmediateBatteryLevel > BATTERY_THRESHOLD ) 	//check mV level
	}
}
