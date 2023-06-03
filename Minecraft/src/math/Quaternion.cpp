#include "Quaternion.h"

//void Quaternion::euler(float Pitch, float Yaw, float Roll)
//{
//    float Pi = 4 * atan(1);
//
//    //Set the values, which came in degrees, to radians for C++ trig functions
//    float rYaw = Yaw * Pi / 180;
//    float rPitch = Pitch * Pi / 180;
//    float rRoll = Roll * Pi / 180;
//
//    //Components
//    float C1 = cos(rYaw / 2);
//    float C2 = cos(rPitch / 2);
//    float C3 = cos(rRoll / 2);
//    float S1 = sin(rYaw / 2);
//    float S2 = sin(rPitch / 2);
//    float S3 = sin(rRoll / 2);
//
//    //Create the final values
//    a = ((C1 * C2 * C3) - (S1 * S2 * S3));
//    x = (S1 * S2 * C3) + (C1 * C2 * S3);
//    y = (S1 * C2 * C3) + (C1 * S2 * S3);
//    z = (C1 * S2 * C3) - (S1 * C2 * S3);
//}
//
////Overload the multiplier operator
//Quaternion Quaternion::operator* (Quaternion OtherQuat)
//{
//    float A = (OtherQuat.a * a) - (OtherQuat.x * x) - (OtherQuat.y * y) - (OtherQuat.z * z);
//    float X = (OtherQuat.a * x) + (OtherQuat.x * a) + (OtherQuat.y * z) - (OtherQuat.z * y);
//    float Y = (OtherQuat.a * y) - (OtherQuat.x * z) - (OtherQuat.y * a) - (OtherQuat.z * x);
//    float Z = (OtherQuat.a * z) - (OtherQuat.x * y) - (OtherQuat.y * x) - (OtherQuat.z * a);
//    Quaternion NewQuat = Quaternion(0, 0, 0);
//    NewQuat.a = A;
//    NewQuat.x = X;
//    NewQuat.y = Y;
//    NewQuat.z = Z;
//    return NewQuat;
//}
//
////Calculates a rotation matrix and fills Matrix with it
//void Quaternion::RotationMatrix(GLfloat *Matrix)
//{
//    //Column 1
//    Matrix[0] = (a * a) + (x * x) - (y * y) - (z * z);
//    Matrix[1] = (2 * x * y) + (2 * a * z);
//    Matrix[2] = (2 * x * z) - (2 * a * y);
//    Matrix[3] = 0;
//    //Column 2
//    Matrix[4] = (2 * x * y) - (2 * a * z);
//    Matrix[5] = (a * a) - (x * x) + (y * y) - (z * z);
//    Matrix[6] = (2 * y * z) + (2 * a * x);
//    Matrix[7] = 0;
//    //Column 3
//    Matrix[8] = (2 * x * z) + (2 * a * y);
//    Matrix[9] = (2 * y * z) - (2 * a * x);
//    Matrix[10] = (a * a) - (x * x) - (y * y) + (z * z);
//    Matrix[11] = 0;
//    //Column 4
//    Matrix[12] = 0;
//    Matrix[13] = 0;
//    Matrix[14] = 0;
//    Matrix[15] = 1;
//}
