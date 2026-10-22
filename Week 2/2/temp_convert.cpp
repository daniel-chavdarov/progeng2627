#include <iostream>
#include <string>

int main(){ 

    double t_in, t_out;         //t -> temperature
    std::string u_in, u_out;    //u -> unit
    bool valid_unit = true;

    std::cin >> t_in >> u_in;

    if ((u_in == "C") || (u_in == "c")){
        u_out = "F";
        t_out = 1.8*t_in + 32;
    }
    else if((u_in == "F") || (u_in == "f")){
        u_out = "C";
        t_out = (t_in-32)/1.8;
    }
    else{
        valid_unit = false;
    }

    if(valid_unit){
        std::cout << t_out << " " << u_out << std::endl;
    }
    else{
        std::cout << "error - unit not recognised" << std::endl;
    }

    
}