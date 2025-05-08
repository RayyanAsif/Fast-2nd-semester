#include <iostream>
using namespace std;

class HomeAssistant;
class EnergyMonitor;

class SmartDevice {
    string deviceName;
    int usage;
    string status;
public:
    SmartDevice(string d, int u, string s) : deviceName(d), usage(u), status(s) {}
    friend class HomeAssistant;
    friend class EnergyMonitor;
};

class HomeAssistant {
public:
    void changeStatus(SmartDevice& s, string newStat) {
        s.status = newStat;
    }
    friend class EnergyMonitor;
};

class EnergyMonitor {
    static int energy;
public:
    int energyConsumption(SmartDevice& s) {
        if (s.status == "on") {
            energy += s.usage;
        }
        return energy;
    }

    static int getEnergy() {
        return energy;
    }
};

int EnergyMonitor::energy = 0;

int main() {
    SmartDevice s1("Fan", 12, "off");
    SmartDevice s2("Light", 9, "on");
    SmartDevice s3("TV", 20, "off");

    HomeAssistant h;
    h.changeStatus(s3, "on");

    EnergyMonitor e;
    
    cout << "Energy consumed by Light: " << e.energyConsumption(s2) << endl;
    cout << "Energy consumed after turning on TV: " << e.energyConsumption(s3) << endl;

    cout << "Total energy consumption: " << EnergyMonitor::getEnergy() << endl;

    return 0;
}

