#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<string>

#define MAX_ENGINE_POWER 5000
#define MAX_WEIGHT 100000
#define FIRST_CAR_DATE 1886
#define CURRENT_YEAR 2021

#define LETTER_AMOUNT 3
#define PLATE_LENGTH 5

#define COLOR_AMOUNT 7

namespace MyCar{

    class CarCheck{

        private:

            static const std::string possibleColors[COLOR_AMOUNT];

        public:

            // Checkers

            static bool checkColor(const std::string& color);
            static bool checkPlate(const std::string& plate);
            static bool checkEnginePower(unsigned int enginePower);
            static bool checkWeight(unsigned int weight);
            static bool checkManufactureYear(unsigned int manufactureYear);


    };

    class Car{

        private:

            Car();
            std::string manufacturer;
            std::string model;
            unsigned int manufactureYear;
            std::string color;
            std::string plate;
            std::string vin;
            unsigned int enginePower;
            unsigned int weight;

            unsigned int objectID;

            unsigned static int ID;

            bool isInitialised;

        public:
            Car(const std::string& manufacturer, const std::string& model, unsigned int manufactureYear, const std::string& color,
                const std::string& plate, const std::string& vin, unsigned int enginePower, unsigned int weight);
            ~Car();

            static Car getInstance();
            // Getters
            std::string getColor() const;
            std::string getVin() const;
            std::string getPlate() const;
            unsigned int getEnginePower() const;
            unsigned int getWeight() const;
            std::string getManufacturer() const;
            std::string getModel() const;
            unsigned int getManufactureYear() const;
            unsigned int getID() const;

            // Setters
            void setColor(const std::string& color);
            void setVin(const std::string& vin);
            void setPlate(const std::string& plate);
            void setEnginePower(unsigned int enginePower);
            void setWeight(unsigned int weight);
            void setManufacturer(const std::string& manufacturer);
            void setModel(const std::string& model);
            void setManufactureYear(unsigned int manufactureYear);

            std::string toString() const;

            bool operator==(const Car& object) const;
            bool operator!=(const Car& object) const;
            bool operator<(const Car& object) const;
            bool operator<=(const Car& object) const;
            bool operator>(const Car& object) const;
            bool operator>=(const Car& object) const;

            Car& operator++();
            Car operator++(int);

            friend std::ostream& operator<<(std::ostream& stream, const Car& object);
            friend std::istream& operator>>(std::istream& stream, Car& object);
    };

}
#endif // CAR_H_INCLUDED
