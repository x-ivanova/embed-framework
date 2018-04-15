#include <string>

using namespace std;

class AutoWaterSystem{
private:
    bool power;
    int temperature;
    string password;
    string plant;

    void setPower(bool power);
    void setTemperature(int temperature);
    void setPassword(const string &password);
    void setPlant(const string &plant);

public:
    AutoWaterSystem(){
        power = 0;
        temperature = 18;
        password = "password";
        plant = "Не выбрано";
    }

    bool isPower() const;
    int getTemperature() const;
    const string &getPassword() const;
    const string &getPlant() const;

    string make_shot();
    string turnOn();
    string turnOff();
    string changePassword(string password);
    string changePlant(string plant);
    string changeTemperature(int temperature);
};

void AutoWaterSystem::setPower(bool power) {
    AutoWaterSystem::power = power;
}

void AutoWaterSystem::setTemperature(int temperature) {
    AutoWaterSystem::temperature = temperature;
}

void AutoWaterSystem::setPassword(const string &password) {
    AutoWaterSystem::password = password;
}

void AutoWaterSystem::setPlant(const string &plant) {
    AutoWaterSystem::plant = plant;
}

bool AutoWaterSystem::isPower() const {
    return power;
}

int AutoWaterSystem::getTemperature() const {
    return temperature;
}

const string &AutoWaterSystem::getPassword() const {
    return password;
}

const string &AutoWaterSystem::getPlant() const {
    return plant;
}



string AutoWaterSystem::make_shot(){
    // Пользовательский код здесь. Например, вызов программы для снимка.
    return "The shot was successfully taken";
}

string AutoWaterSystem::turnOn(){
    // Пользовательский код.
    setPower(true);
    return "System was successfully ON";
}

string AutoWaterSystem::turnOff(){
    // Пользовательский код.
    setPower(false);
    return "System was successfully OFF";
}

string AutoWaterSystem::changePassword(string password){
    setPassword(password);
    return "Password was successfuly changed";
}

string AutoWaterSystem::changePlant(string plant){
    // Пользовательский код.
    setPlant(plant);
    return "Plant was successfuly changed to " + plant;
}

string AutoWaterSystem::changeTemperature(int temperature){
    // Пользовательский код.
    setTemperature(temperature);
    return "Temperature was successfuly changed to " + to_string(temperature) + " C";
}

