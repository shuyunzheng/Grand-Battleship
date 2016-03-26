#ifndef __FILESETTINGS_H
#define __FILESETTINGS_H

#include "Settings.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSETTINGNUMBER 100   //set the max number of setting

class FileSettings : public Settings
{
   struct ST{
	 string key;
	 string value;
   }a[MAXSETTINGNUMBER];
   int cntSettingNum = 0;
   FILE *fp;

  public:
   void printAllSetting(){
      for(int i = 0;i < cntSettingNum;i++){
	 cout << a[i].key << " " << a[i].value << endl;
      }
      cout << endl;
   }
   bool addSetting(std::string key, std::string value) {
      int indexKey = getIndex(key);
      if(indexKey < cntSettingNum){      //exit this key
	 cout << "add error" << endl;
	 return false;
      }
      a[cntSettingNum].key = key;
      a[cntSettingNum++].value = value;
      return true;
   };
   bool updateSetting(std::string key, std::string updateVal) {
      int indexKey = getIndex(key);
      if(indexKey == cntSettingNum){      //cannot find this key
	 return false;
      }
      a[indexKey].value = updateVal;
      return true;
   };
   int getIndex(string key){
      for(int i = 0;i < cntSettingNum;i++){
	 if(a[i].key.compare(key) == 0){
	    //cout << "index: "<< i << endl;
	    return i;
	 }
      }
      return cntSettingNum;
   }
   std::string get_setting(std::string key) {
      int indexKey = getIndex(key);
      if(indexKey == cntSettingNum){   //cannot find this key
	 return "";
      }
      return a[indexKey].value;
   };
   bool removeSetting(std::string key) {
      int indexKey = getIndex(key);
      if(indexKey == cntSettingNum){  //cannot find this key
	 return false;
      }
      for(int i = indexKey;i < cntSettingNum - 1;i++){
	 a[i].key = a[i + 1].key;
	 a[i].value = a[i + 1].value;
      }
      cntSettingNum--;
      return true;
   };
   void char2str(char s[],string &key,string &value){
      key = "";
      value = "";
      int i;
      for(i = 0;s[i] != '\0' && s[i] != ' ';i++){
	 key += s[i];
      }
      i++;
      while(s[i] != '\0' && s[i] != '\n'){
	 value += s[i++];
      }
      //cout <<  key << " *****  " << value << endl;
   }
   bool load_settings() {
      cntSettingNum = 0;
      char str[128];
      string  key = "",value = "";
      memset(str,0,sizeof(str));
      if((fp=fopen("setting.txt","r"))==NULL) {
	 printf("cannot open file\n");
	 return false;
      }
      while(!feof(fp)) {
	 if(fgets(str,128,fp) != NULL){
	    char2str(str,key,value);
	    a[cntSettingNum].key = key;
	    a[cntSettingNum++].value = value;
	 }
      }
      fclose(fp);
      //cout << cntSettingNum << endl;
      return true;
   };
   bool store_settings() {
      if((fp=fopen("setting.txt","w"))==NULL) {
	 printf("cannot open file\n");
	 return false;
      }
      string tmp;
      for(int i = 0;i < cntSettingNum;i++){
	 tmp = a[i].key + " " + a[i].value + "\n";
	 fputs(tmp.c_str(),fp);
      }
      fclose(fp);
      return true;
   };
};
#endif
