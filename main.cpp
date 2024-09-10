/*my C++ code: ask user for input using loops, if the user type other answers
 *then the loops do some checks and deal with it once the user finishes then
 *it display the result
*/
#include <iostream>
namespace name {
    double input;
}
void priceIsGood(double x);
void enterNewPrice();
int main() {
    std::string input = " ";
    std::cout<<"**********\n";
    //code in the loop start here
    while(true) {
        try{
            std::cout<<"Enter price or type 'exit' to exit\n";
            std::cin>>input;

            if(input == "exit") {
                std::cout<<"Exiting...\n";
                break;
            }

            name::input = std::stod(input);
            while(true) {
                std::cout<<"Price entered: " <<name::input<< " Would you like to continue\n";
                std::string option;

                std::cout<<"y for Yes and n for N\n";

                std::cin>>option;

                if(option == "y" || option == "Y") {
                    priceIsGood(name::input);
                    break;

                } else if(option == "n" || option == "N") {
                    while(true) {
                        std::cout<<"Any change you want to make?\n";
                        std::string change;
                        std::cout<<"y for Yes and n for N\n";

                        std::cin>>change;
                        if(change == "y" || change == "Y") {
                            enterNewPrice();
                            break;
                        } else if(change == "n" || change == "N") {
                            priceIsGood(name::input);
                            break;
                        } else {
                            std::cout<<"Invalid input, enter y for Yes and n for N\n";
                        }
                    }
                    break;
                }
            }
        } catch(const std::invalid_argument&) {
                std::cout<<"Error: Enter a price number or exit \n";
        }

    }
    return 0;
}

//methods that will be using inside the loop
void priceIsGood(double x) {
    x = x * 1.15;
    std::cout<<"Your price is: "<<x<<std::endl;
}
void enterNewPrice() {
    while(true) {
        try {
            std::cout<<"Enter the new price\n";
            double new_price;
            std::cin>>new_price;

                std::cout<<"New price is: " <<new_price<<"\n";
                std::cout<<"Do you want to continue?\n";

                std::string change2;
                std::cin>>change2;
                if(change2 == "y" || change2 == "Y") {
                    priceIsGood(new_price);
                    break;
                }
        } catch (const std::invalid_argument&) {
            std::cout<<"Error: Enter a price number or exit \n";
        }
    }
}