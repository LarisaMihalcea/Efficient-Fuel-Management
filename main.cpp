#include <iostream>
#include<vector>
#include <iomanip>
#include<algorithm>
#include <cstdint>

using namespace std;

class Car {
public:
    string mBrand;
    string mLicensePlate;
    uint16_t mYearOfFabrication;
    double mAverageConsumption;
    uint32_t mNumberOfKilometers;

    Car(string Brand, string LicensePlate, uint16_t YearOfFabrication, double AverageConsumption,
        uint32_t NumberOfKilometers) {
        mBrand = Brand;
        mLicensePlate = LicensePlate;
        mYearOfFabrication = YearOfFabrication;
        mAverageConsumption = AverageConsumption;
        mNumberOfKilometers = NumberOfKilometers;
    }

    string getBrand() const {
        return mBrand;
    }

    string getLicensePlate() const {
        return mLicensePlate;
    }

    uint16_t getYearOfFabrication() const {
        return mYearOfFabrication;
    }

    double getAverageConsumption() const {
        return mAverageConsumption;
    }

    uint32_t getNumberOfKilometers() const {
        return mNumberOfKilometers;
    }

    virtual double getFuelConsumption() const = 0;

    virtual double getFuelCost() const = 0;

    virtual string getType() const = 0;

    bool operator<(const Car &c2) const {
        return true;
    }
};

class PetrolCar : public Car {
public:
    PetrolCar(string Brand, string LicensePlate, uint16_t YearOfFabrication, double AverageConsumption,
              uint32_t NumberOfKilometers) : Car(Brand, LicensePlate, YearOfFabrication, AverageConsumption,
                                                 NumberOfKilometers) {}

    double getFuelConsumption() const override {
        return (0.879 * mAverageConsumption * mNumberOfKilometers) / 100;
    }

    double getFuelCost() const override {
        return 4.5 * getFuelConsumption();
    }

    string getType() const override {
        return "benzina";
    }
};

class DieselCar : public Car {
public:
    DieselCar(string Brand, string LicensePlate, uint16_t YearOfFabrication, double AverageConsumption,
              uint32_t NumberOfKilometers) : Car(Brand, LicensePlate, YearOfFabrication, AverageConsumption,
                                                 NumberOfKilometers) {}

    double getFuelConsumption() const override {
        return (0.789 * mAverageConsumption * mNumberOfKilometers) / 100;
    }

    double getFuelCost() const override {
        return 4.8 * getFuelConsumption();
    }

    string getType() const override {
        return "diesel";
    }
};

class HybridCar : public Car {
public:
    HybridCar(string Brand, string LicensePlate, uint16_t YearOfFabrication, double AverageConsumption,
              uint32_t NumberOfKilometers) : Car(Brand, LicensePlate, YearOfFabrication, AverageConsumption,
                                                 NumberOfKilometers) {}

    double getFuelConsumption() const override {
        return (mAverageConsumption * mNumberOfKilometers - 0.124 * mNumberOfKilometers) / 100;
    }

    double getFuelCost() const override {
        return 4.5 * getFuelConsumption();
    }

    string getType() const override {
        return "hibrid";
    }
};

class ElectricCar : public Car {
public:
    ElectricCar(string Brand, string LicensePlate, uint16_t YearOfFabrication, double AverageConsumption,
                uint32_t NumberOfKilometers) : Car(Brand, LicensePlate, YearOfFabrication, AverageConsumption,
                                                   NumberOfKilometers) {}

    double getFuelConsumption() const override {
        return 0;
    }

    double getFuelCost() const override {
        return 0;
    }

    string getType() const override {
        return "electrica";
    }
};

int main() {
    int n;
    cin >> n;
    vector<Car *> masinute;
    string brand, tip_combustibil, nr_inmatriculare;
    uint16_t an_fabricatie;
    double consum_mediu;
    uint32_t km;
    char cerinta;
    for (int i = 0; i < n; i++) {
        cin >> brand >> tip_combustibil >> nr_inmatriculare >> an_fabricatie >> consum_mediu >> km;
        if (tip_combustibil == "benzina") {
            masinute.push_back(new PetrolCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
        } else if (tip_combustibil == "diesel") {
            masinute.push_back(new DieselCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
        } else if (tip_combustibil == "hibrid") {
            masinute.push_back(new HybridCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
        } else if (tip_combustibil == "electrica") {
            masinute.push_back(new ElectricCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
        }
    }
    cin >> cerinta;
    double suma_benzina = 0, suma_diesel = 0, suma_h = 0, suma_tot = 0, suma_el = 0;
    if (cerinta == 'b') {
        for (int i = 0; i < masinute.size(); i++) {
            if (masinute[i]->getType() == "benzina") {
                suma_benzina += masinute[i]->getFuelCost();
            } else if (masinute[i]->getType() == "diesel") {
                suma_diesel += masinute[i]->getFuelCost();
            } else if (masinute[i]->getType() == "hibrid") {
                suma_h += masinute[i]->getFuelCost();
            } else if (masinute[i]->getType() == "electrica") {
                suma_el += masinute[i]->getFuelCost();
            }
        }
        suma_tot = suma_benzina + suma_diesel + suma_h + suma_el;
        cout << suma_tot;
    }

    if (cerinta == 'c') {
        while (cin >> brand >> tip_combustibil >> nr_inmatriculare >> an_fabricatie >> consum_mediu >> km) {
            if (tip_combustibil == "benzina") {
                masinute.push_back(new PetrolCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
            } else if (tip_combustibil == "diesel") {
                masinute.push_back(new DieselCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
            } else if (tip_combustibil == "hibrid") {
                masinute.push_back(new HybridCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
            } else if (tip_combustibil == "electrica") {
                masinute.push_back(new ElectricCar(brand, nr_inmatriculare, an_fabricatie, consum_mediu, km));
            }
        }

        double nr_km = 0, suma_consum = 0;
        int a = masinute.size();
        for (int i = 0; i < masinute.size(); i++) {
            nr_km += masinute[i]->getNumberOfKilometers();
            suma_consum += masinute[i]->getAverageConsumption();
        }
        cout << nr_km << " km" << endl;
        cout << fixed << setprecision(2) << suma_consum / a << " L/100km";
    }

    int benzina = 0, diesel = 0, hibrid = 0, electrice = 0;
    if (cerinta == 'd') {
        for (int i = 0; i < masinute.size(); i++) {
            if (masinute[i]->getType() == "benzina") {
                benzina++;
            } else if (masinute[i]->getType() == "diesel") {
                diesel++;
            } else if (masinute[i]->getType() == "hibrid") {
                hibrid++;
            } else if (masinute[i]->getType() == "electrica") {
                electrice++;
            }
        }
        cout << "benzina -> " << benzina << endl;
        cout << "diesel -> " << diesel << endl;
        cout << "electrica -> " << electrice << endl;
        cout << "hibrid -> " << hibrid << endl;
    }

    if (cerinta == 'e') { //B53APOP
        for (int i = 0; i < masinute.size(); i++) {
            int ok = 1; //fals
            if (isupper(masinute[i]->mLicensePlate[0])) {
                if (isupper(
                        masinute[i]->mLicensePlate[1])) {
                    if (isdigit(masinute[i]->mLicensePlate[2])) {
                        if (isdigit(masinute[i]->mLicensePlate[3])) {
                            if (isdigit(masinute[i]->mLicensePlate[4])) {
                                if (isupper(masinute[i]->mLicensePlate[5]) &&
                                    isupper(masinute[i]->mLicensePlate[6]) &&
                                    isupper(masinute[i]->mLicensePlate[7]) &&
                                    masinute[i]->getLicensePlate().size() == 8) {
                                    ok = 0; //nr bun AB 123 CCC
                                }
                            } else if (isupper(masinute[i]->mLicensePlate[4]) &&
                                       isupper(masinute[i]->mLicensePlate[5]) &&
                                       isupper(masinute[i]->mLicensePlate[6]) &&
                                       masinute[i]->getLicensePlate().size() == 7) {
                                ok = 0; //nr bun AB 12 CCC
                            }
                        }
                    }
                } else if (isdigit(masinute[i]->mLicensePlate[1])) {
                    if (isdigit(masinute[i]->mLicensePlate[2])) {
                        if (isdigit(masinute[i]->mLicensePlate[3])) {
                            if (isupper(masinute[i]->mLicensePlate[4]) &&
                                isupper(masinute[i]->mLicensePlate[5]) &&
                                isupper(masinute[i]->mLicensePlate[6]) &&
                                masinute[i]->getLicensePlate().size() == 7) {
                                ok = 0; // nr bun A 123 CCC
                            }
                        } else if (isupper(masinute[i]->mLicensePlate[3]) &&
                                   isupper(masinute[i]->mLicensePlate[4]) &&
                                   isupper(masinute[i]->mLicensePlate[5]) &&
                                   masinute[i]->getLicensePlate().size() == 6) {
                            ok = 0; //nr bun A 12 CCC
                        }
                    }

                }
            }
            if (ok == 1) {
                cout << masinute[i]->getLicensePlate() << ": numar de inmatriculare invalid" << endl;
            }
        }

    }

    if (cerinta == 'a') {
        for (int i = 0; i < masinute.size() - 1; i++) {
            for (int j = i + 1; j < masinute.size(); j++) {
                if (masinute[i]->getYearOfFabrication() < masinute[j]->getYearOfFabrication()) {
                    swap(masinute[i], masinute[j]);
                }
            }
        }
        for (int i = 0; i < masinute.size() - 1; i++) {
            for (int j = i + 1; j < masinute.size(); j++) {
                if (masinute[i]->getNumberOfKilometers() > masinute[j]->getNumberOfKilometers() &&
                    masinute[i]->getYearOfFabrication() == masinute[j]->getYearOfFabrication()) {
                    swap(masinute[i], masinute[j]);
                }
            }
        }
        for (int i = 0; i < masinute.size() - 1; i++) {
            for (int j = i + 1; j < masinute.size(); j++) {
                if (masinute[i]->getFuelConsumption() > masinute[j]->getFuelConsumption() &&
                    masinute[i]->getNumberOfKilometers() > masinute[j]->getNumberOfKilometers() &&
                    masinute[i]->getYearOfFabrication() == masinute[j]->getYearOfFabrication()) {
                    swap(masinute[i], masinute[j]);
                }
            }
        }

        for (int i = 0; i < masinute.size(); i++) {
            cout << "Masina " << masinute[i]->getBrand() << " cu numarul de inmatriculare "
                 << masinute[i]->getLicensePlate() << " a parcurs " << masinute[i]->getNumberOfKilometers()
                 << "km si a consumat " << fixed << setprecision(3) << masinute[i]->getFuelConsumption()
                 << " litri." << endl;

        }
    }
    return 0;

}