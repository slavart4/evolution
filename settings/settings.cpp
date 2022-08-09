#include "settings.h"

namespace Settings {

    int hunterHp;
    int hunterSize;
    int hunterSpeed;
    int hunterMaxHunger;
    int hunterMaxAge;
    int hunterStrength;
    int hunterView;
    int hunterGrowthSpeed;
    std::string hunterColor;

    int peacefulHp;
    int peacefulSize;
    int peacefulSpeed;
    int peacefulMaxHunger;
    int peacefulMaxAge;
    int peacefulStrength;
    int peacefulView;
    int peacefulGrowthSpeed;
    std::string peacefulColor;

    int plantHp;
    int plantSize;
    int plantMaxAge;
    int plantGrowthSpeed;
    std::string plantColor;

    /**
     * Function that fills all units settings
     * @returns void
     */
    void fillUnitSettings() {
        json jsonData;
        std::ifstream settingsFile;
        settingsFile.open("unitSettings.json");

        try {
            settingsFile >> jsonData;

            hunterHp =              jsonData["unit"]["animal"]["hunter"]["hp"];
            hunterSize =            jsonData["unit"]["animal"]["hunter"]["size"];
            hunterSpeed =           jsonData["unit"]["animal"]["hunter"]["speed"];
            hunterMaxHunger =       jsonData["unit"]["animal"]["hunter"]["maxHunger"];
            hunterMaxAge =          jsonData["unit"]["animal"]["hunter"]["maxAge"];
            hunterStrength =        jsonData["unit"]["animal"]["hunter"]["strength"];
            hunterView =            jsonData["unit"]["animal"]["hunter"]["view"];
            hunterGrowthSpeed =     jsonData["unit"]["animal"]["hunter"]["growthSpeed"];
            hunterColor =           jsonData["unit"]["animal"]["hunter"]["color"];

            peacefulHp =            jsonData["unit"]["animal"]["peaceful"]["hp"];
            peacefulSize =          jsonData["unit"]["animal"]["peaceful"]["size"];
            peacefulSpeed =         jsonData["unit"]["animal"]["peaceful"]["speed"];
            peacefulMaxHunger =     jsonData["unit"]["animal"]["peaceful"]["maxHunger"];
            peacefulMaxAge =        jsonData["unit"]["animal"]["peaceful"]["maxAge"];
            peacefulStrength =      jsonData["unit"]["animal"]["peaceful"]["strength"];
            peacefulView =          jsonData["unit"]["animal"]["peaceful"]["view"];
            peacefulGrowthSpeed =   jsonData["unit"]["animal"]["peaceful"]["growthSpeed"];
            peacefulColor =         jsonData["unit"]["animal"]["peaceful"]["color"];

            plantHp =               jsonData["unit"]["plant"]["hp"];
            plantSize =             jsonData["unit"]["plant"]["size"];
            plantMaxAge =           jsonData["unit"]["plant"]["maxAge"];
            plantGrowthSpeed =      jsonData["unit"]["plant"]["growthSpeed"];
            plantColor =            jsonData["unit"]["plant"]["color"];
        } catch (...) {
            std::cout << "unitSettings parse error!" << std::endl;
            exit(50);
        }
    }
}