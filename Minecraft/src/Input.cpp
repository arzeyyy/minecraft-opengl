//#include "Input.h"
//#include <iostream>
//
//float xoffset;
//float yoffset;
//
//bool firstMouse = true;
//static float lastX = 1280 / 2.f;
//static float lastY = 720 / 2.f;
//
//void Input::mouseCallback(GLFWwindow *window, double xpos_in, double ypos_in)
//{
//    float xpos = static_cast<float>(xpos_in);
//    float ypos = static_cast<float>(ypos_in);
//
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    xoffset = xpos - lastX;
//    yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//
//    //std::cout << "xoffset: " << xoffset << std::endl;
//
//    lastX = xpos;
//    lastY = ypos;
//
//}
//
//float Input::getAxis(std::string axis)
//{
//    if (axis == "mouseX")
//    {
//        //std::cout << "xoffset: " << xoffset << std::endl;
//        return xoffset;
//    }
//
//    if (axis == "mouseY")
//    {
//        //std::cout << "xoffset: " << xoffset << std::endl;
//        return yoffset;
//    }
//
//    return 0.0f;
//}