#include <iostream>
#include <string>

int main(){ 

    double l_in, l_out;         //l -> length
    std::string u_in, u_out;    //u -> unit
    bool valid_unit = true;

    const double mile_to_km = 1.609;

    std::cin >> l_in >> u_in;

    if (u_in == "km"){
        u_out = "mile";
        l_out = l_in/mile_to_km;
    }
    else if((u_in == "mile") || (u_in == "miles")){
        u_out = "km";
        l_out = l_in*mile_to_km;  
    }
    else{
        valid_unit = false;
    }

    if(valid_unit){
        std::cout << l_out << " " << u_out << std::endl;
    }
    else{
        std::cout << "error - unit not recognised" << std::endl;
    }

    
}