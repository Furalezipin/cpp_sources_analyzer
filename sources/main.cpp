#include <iostream>

#include <boost/program_options/options_description.hpp>

using namespace boost::program_options;

int main() {
    options_description desc("General options");
    std::cout << "Hello world" << std::endl;
}
