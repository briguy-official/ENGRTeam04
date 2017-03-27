// Robot initialization and various other functions go here

typedef struct location_struct{
	float x;
	float y;
} location;

typedef struct path_struct{
    location current;
    path* next = NULL;
    path* previous = NULL;
} path;

float angleToTurn(path nextTurn){
    location loc1 = nextTurn->previous.current;
    location loc2 = nextTurn.current;
    location loc3 = nextTurn->previous.current;
    float mag_a;
    float mag_b;
    float a_dot_b;
    float cosTheta;
    float theta;
    
    mag_a = pow((loc2.x - loc1.x), 2) + pow((loc2.y - loc1.y), 2);
    mag_a = sqrt(mag_a);
    
    mag_b = pow((loc3.x - loc2.x), 2) + pow((loc3.y - loc2.y), 2);
    mag_b = sqrt(mag_b);
    
    a_dot_b = (loc2.x - loc1.x) * (loc3.x - loc2.x) + 
              (loc2.y - loc1.y) * (loc3.y - loc2.y);
    
    cosTheta = a_dot_b / (mag_a * mag_b);
    
    theta = acos(cosTheta) * 180 / PI;
    
    return theta;
}

float angleToDrive(path straight){
    location loc1 = straight.current;
    location loc2 = straight->next.current;
    float distance;
    float angle;
    
    distance =  pow((loc2.x - loc1.x), 2) + pow((loc2.y - loc1.y), 2);
    distance = sqrt(distance);
    
    angle = distance / (1.5 * PI) * 360;
    
    return angle;
}



task main()
{
    
    const location N;
    const location S;
    const location E;
    const location W;
    const location NE;
    const location SE;
    const location SW;
    const location NW;
    
    location vsp;
	location start;
    location beaconA;
    location beaconB;
    location beaconC;
    location node1;
    location node2;
    location node3;
    location node4;
    
    path demoPath;
    path currentNode;
    
    demoPath.current = start;
    
    
    initializeRobot();
    
    
}
