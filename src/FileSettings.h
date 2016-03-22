#ifndef __FILESETTINGS_H
#define __FILESETTINGS_H

#include "Settings.h"

class FileSettings : public Settings
{
  public:
    bool addSetting(std::string, std::string) { return true; };
    bool updateSetting(std::string, std::string) { return true; };
    std::string get_setting(std::string) { return ""; };
    bool removeSetting(std::string) { return true; };
    bool load_settings() { return true; };
    bool store_settings() { return true; }; 
};

#endif 
