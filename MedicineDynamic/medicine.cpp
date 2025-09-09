#include <iostream>

class Medicine {
    public:
        Medicine(std::string name): m_name{name} {}

        virtual void dispense() {
            std::cout << "Dispensing a generic medicine named " << m_name << ".\n";
        }

        std::string getName() const {
            return m_name;
        }
    private:
        std::string m_name{};

};

class IVMedicine : public Medicine {
    public:
        IVMedicine(std::string name): Medicine(name) {}
        void dispense() {
            std::cout << "Pumping out a medicine named " << getName() << ".\n";
        }
};

class PillMedicine: public Medicine {
    public:
        PillMedicine(std::string name): Medicine(name) {}
        void dispense() {
            std::cout << "Handing a pill of " << getName() << " in a cup to the patient.\n";
        }
};

bool safety_check() {
    return true;
}


// In its current version, dispense method that is executed in this
// function will _always_ be the one from the _actual_ class of the
// object given as an argument for med.
// Enabling _dynamic dispatch_ (which is a requirement of _run-time
// _polymorphism_) requires
// 1. That the member function be virtual _and_
// 2. That the object on which the member function is invoked by either
//    a reference or a pointer.
// Both of those is the case here.
void give_medicine(std::string patient_name, Medicine &med) {
    if (safety_check()) {
        med.dispense();
    }
}

int main() {
    PillMedicine zofran{"Zofran"};

    give_medicine("Will Hawkins", zofran);

    return 0;
}