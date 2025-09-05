#include <iostream>

class Medicine {
    public:
        Medicine(std::string name): m_name{name} {}

        void dispense() {
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

void give_medicine(std::string patient_name, Medicine med) {
    if (safety_check()) {
        med.dispense();
    }
}

int main() {
    Medicine zofran{"Zofran"};

    give_medicine("Will Hawkins", zofran);

    return 0;
}