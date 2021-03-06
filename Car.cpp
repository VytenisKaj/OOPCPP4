#include"Car.h"
#include<sstream>
#include<exception>
#include<stdexcept>

#define NOT_INITIALISED_ERROR "Car object has to be initialised with constructor or operator >>"

namespace MyCar{

    unsigned int Car::ID = 0;
    const std::string CarCheck::possibleColors[] = {

            "Red",
            "Blue",
            "Green",
            "Yellow",
            "Black",
            "White",
            "Grey"

    };


    // Checkers

    bool CarCheck::checkColor(const std::string& color){

        for(int i = 0; i < COLOR_AMOUNT; ++i){
            if(color == possibleColors[i]){
                return true;
            }
        }
        return false;

    }

    bool CarCheck::checkPlate(const std::string& plate){

        for(int i = 0; i < (int) plate.length(); ++i){
            if(i < LETTER_AMOUNT){
                if(!isupper(plate[i])){
                    return false;
                }
            }
            else{
                if(!isdigit(plate[i])){
                    return false;
                }
            }
            if(i > PLATE_LENGTH){
                return false;
            }
        }
        return true;
    }

    bool CarCheck::checkEnginePower(unsigned int enginePower){

        if(enginePower <= MAX_ENGINE_POWER){
            return true;
        }
        else{
            return false;
        }

    }

    bool CarCheck::checkWeight(unsigned int weight){

        if(weight <= MAX_WEIGHT){
            return true;
        }
        else{
            return false;
        }
    }

    bool CarCheck::checkManufactureYear(unsigned int manufactureYear){

        if(manufactureYear >= FIRST_CAR_DATE && manufactureYear <= CURRENT_YEAR){
            return true;
        }
        else{
            return false;
        }
    }

    Car::Car(){
        isInitialised = false;
    }

    Car::Car(const std::string& manufacturer, const std::string& model, unsigned int manufactureYear, const std::string& color,
                    const std::string& plate, const std::string& vin, unsigned int enginePower, unsigned int weight)
    {
        isInitialised = true;
        setColor(color);
        setVin(vin);
        setPlate(plate);
        setEnginePower(enginePower);
        setWeight(weight);
        setManufacturer(manufacturer);
        setModel(model);
        setManufactureYear(manufactureYear);
        ++ID;
        objectID = ID;
    }

    Car::~Car(){
        // empty
    }

    Car Car::getInstance(){
        Car instance;
        return instance;
    }

    std::string Car::toString() const{

        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }

        std::stringstream ss;
        ss << manufacturer << " " << model << " " << manufactureYear << " " << color << " " << plate << " "
         << vin << " " << enginePower <<  " " << weight;
        return ss.str();
    }

    // Getters

    std::string Car::getColor() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return color;
    }

    std::string Car::getVin() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return vin;
    }

    std::string Car::getPlate() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return plate;
    }

    unsigned int Car::getEnginePower() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return enginePower;
    }

    std::string Car::getModel() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return model;
    }

    unsigned int Car::getWeight() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return weight;
    }

    std::string Car::getManufacturer() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return manufacturer;
    }

    unsigned int Car::getManufactureYear() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return manufactureYear;
    }

    unsigned int Car::getID() const{
        if(!(this->isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        return objectID;
    }

    // Setters

    void Car::setColor(const std::string& color){
        if(CarCheck::checkColor(color)){
            this->color = color;
        }
        else{
            throw std::invalid_argument("Not available color");
        }
    }

    void Car::setVin(const std::string& vin){
        this->vin = vin;
    }

    void Car::setPlate(const std::string& plate){
        if(CarCheck::checkPlate(plate)){
            this->plate = plate;
        }
        else{
            throw std::invalid_argument("Not a valid plate (plate has to have only 3 capital letters followed by 3 numbers)");
        }
    }

    void Car::setEnginePower(unsigned int enginePower){
        if(CarCheck::checkEnginePower(enginePower)){
            this->enginePower = enginePower;
        }
        else{
            throw std::invalid_argument("Engine power out of range");
        }

    }
    void Car::setWeight(unsigned int weight){
        if(CarCheck::checkWeight(weight)){
            this->weight = weight;
        }
        else{
            throw std::invalid_argument("Weight out of range");
        }

    }

    void Car::setManufacturer(const std::string& manufacturer){
        this->manufacturer = manufacturer;
    }

    void Car::setModel(const std::string& model){
        this->model = model;
    }

    void Car::setManufactureYear(unsigned int manufactureYear){
        if(CarCheck::checkManufactureYear(manufactureYear)){
            this->manufactureYear = manufactureYear;
        }
        else{
            throw std::invalid_argument("Manufacture year out of range");
        }
    }

    bool Car::operator==(const Car& object) const{

        if(objectID == object.getID()){
            return true;
        }
        else{
            return false;
        }

    }

    bool Car::operator!=(const Car& object) const{

        return !(*this == object);
    }

    bool Car::operator<(const Car& object) const{
        if(objectID < object.getID()){
            return true;
        }
        else{
            return false;
        }

    }

    bool Car::operator<=(const Car& object) const{
        if(objectID <= object.getID()){
            return true;
        }
        else{
            return false;
        }

    }

    bool Car::operator>(const Car& object) const{
        if(objectID > object.getID()){
            return true;
        }
        else{
            return false;
        }

    }

    bool Car::operator>=(const Car& object) const{
        if(objectID >= object.getID()){
            return true;
        }
        else{
            return false;
        }

    }

    Car& Car::operator++(){
        ID++;
        this->objectID = ID;
        return *this;
    }

    Car Car::operator++(int){
        Car temp = *this;
        ID++;
        this->objectID = ID;
        return temp;
    }

    std::ostream& operator<<(std::ostream& stream, const Car& object){
        if(!(object.isInitialised)){
            throw std::logic_error(NOT_INITIALISED_ERROR);
        }
        stream << object.toString();
        return stream;
    }
    std::istream& operator>>(std::istream& stream, Car& object){
        Car temp;
        stream >> temp.manufacturer >> temp.model >> temp.manufactureYear >> temp.color >> temp.plate >> temp.vin >> temp.enginePower >> temp.weight;
        Car temp2;
        if(object.isInitialised){
            temp2.isInitialised = true;
            temp2.objectID = object.objectID;
        }
        temp2.setManufacturer(temp.manufacturer);
        temp2.setModel(temp.model);
        temp2.setManufactureYear(temp.manufactureYear);
        temp2.setColor(temp.color);
        temp2.setPlate(temp.plate);
        temp2.setVin(temp.vin);
        temp2.setEnginePower(temp.enginePower);
        temp2.setWeight(temp.weight);
        object = temp2;
        if(!(object.isInitialised)){
            Car::ID++;
            object.objectID = Car::ID;
            object.isInitialised = true;
        }
        return stream;

    }
}
