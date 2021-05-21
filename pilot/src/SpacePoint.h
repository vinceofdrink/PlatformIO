
#define _SpacePoint_SPC 0x0c // The Doc says 0x18 not 0x0c ?
#define _SpacePoint_CMD_PoolQuat 0x31 //Command to retreive Quaternion 

struct SpacePointQuat {
    double x;
    double y;
    double z;
    double w;
};

struct SpacePointEuler {
    double yaw;
    double pitch;
    double roll;
};

void SpacePoint_init(void) {

    Wire.beginTransmission(_SpacePoint_SPC);  //HwADDR
    Wire.endTransmission(false);  //False end transmission 
    Wire.write(0x31);  //0x31 According to the Datasheet    

}


void SpacePoint_poolData(SpacePointQuat *Quat) {

    Wire.beginTransmission(_SpacePoint_SPC);
    Wire.requestFrom(_SpacePoint_SPC,8,false);  
    Wire.available();


    Quat->x = Wire.read()<<8|Wire.read();
    Quat->x = 3.0518e-005f*(Quat->x-32768);

    Quat->y = Wire.read()<<8|Wire.read();
    Quat->y = 3.0518e-005f*(Quat->y-32768);

    Quat->z = Wire.read()<<8|Wire.read();
    Quat->z = 3.0518e-005f*(Quat->z-32768);

    Quat->w = Wire.read()<<8|Wire.read();
    Quat->w = 3.0518e-005f*(Quat->w-32768);
}


 SpacePointEuler SpacePoint_quatToEuler( SpacePointQuat *Quat ) {
     SpacePointEuler euler;
     double sqx = Quat->x*Quat->x;
     double sqy = Quat->y*Quat->y;
     double sqz = Quat->z*Quat->z;
     double sqw = Quat->w*Quat->w;

    // Derived from SpacePoint doc exemple
    //  sqx = q(1)*q(1) 
    //  sqy = q(2)*q(2); 
    //  sqz = q(3)*q(3); 
    //  sqw = q(4)*q(4);
    // y = (180/pi)*atan2(2.0 * (q(1)*q(2) + q(3)*q(4)),(sqx - sqy - sqz + sqw));
    // p = (180/pi)*asin(-2.0 * (q(1)*q(3) - q(2)*q(4)));
    // r = (180/pi)*atan2(2.0 * (q(2)*q(3) + q(1)*q(4)),(-sqx - sqy + sqz + sqw));
    euler.yaw = (180/PI)*atan2(2.0 * (Quat->x*Quat->y + Quat->z*Quat->w),(sqx - sqy - sqz + sqw));
    euler.pitch = (180/PI)*asin(-2.0 * (Quat->x*Quat->z - Quat->y*Quat->w));
    euler.roll = (180/PI)*atan2(2.0 * (Quat->y*Quat->z + Quat->x*Quat->w),(-sqx - sqy + sqz + sqw));
    return euler;
 }