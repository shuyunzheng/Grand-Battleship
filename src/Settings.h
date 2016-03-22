#ifndef __SETTINGS_H
#define __SETTINGS_H

#include <string>

class Settings 
{
  public:
    virtual bool addSetting(std::string, std::string) = 0;
    virtual bool updateSetting(std::string, std::string) = 0;
    virtual std::string get_setting(std::string) = 0;
    virtual bool removeSetting(std::string) = 0;
    virtual bool load_settings() = 0;
    virtual bool store_settings() = 0; 
};

#endif
