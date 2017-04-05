typedef struct location_struct{
	float x;
	float y;
} location;

float angleToTurn(location loc1, location loc2, locatoin loc3){
    float mag_a;
    float mag_b;
    float a_dot_b;
    float cosTheta;
    float theta;
    float del;
    
    float a1 = loc2.x - loc1.x;
    float a2 = loc2.y - loc1.y;
    float b1 = loc3.x - loc2.x;
    float b2 = loc3.y - loc2.y;
    
    mag_a = sqrt(a1 * a1 + a2 * a2);
    mag_b = sqrt(b1 * b1 + b2 * b2);
    a_dot_b = a1 * b1 + a2 * b2;
    cosTheta = a_dot_b / (mag_a * mag_b);
    theta = acos(cosTheta) * 180 / PI;
    
    del = a1 * b2 - a2 * b1;
    
    if (del > 0){
        return fabs(theta);
    }
    else{
        return -fabs(theta);
    }  
}