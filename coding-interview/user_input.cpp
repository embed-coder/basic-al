/* User interface contains two types of user input controls: TextInput, which accepts all characters and NumericInput, which accepts only digits.

Implement the following methods:

    add on class TextInput - adds the given character to the current value
    getValue on class TextInput - returns the current value
    add on class NumericInput - overrides the base class method so that each non-numeric character is ignored

For example, the following code should output "10":

TextInput* input = new NumericInput();
input->add('1');
input->add('a');
input->add('0');
std::cout << input->getValue();
 */
#include <iostream>
#include <string>

class TextInput
{
public:
    void add(char c) { }

    std::string getValue() { return NULL; }
};

class NumericInput : public TextInput { };

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif