#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#include <iostream>

class Sample
{

    uint32_t member;

    public:
        Sample(uint32_t value) : member(value){}
        ~Sample(){}
        uint32_t getValue() const { return member; }
        void doubleValue() { 
            auto doubleVal = [this]()
            {
                this->member *= 2;
                return (this->member) * (this->member);
            };

            std::cout << "(" << this->member << ")" << std::endl;
            member = doubleVal();
        }

};

#endif