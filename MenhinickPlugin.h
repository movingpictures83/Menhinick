#ifndef MENHINICKPLUGIN_H
#define MENHINICKPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class MenhinickPlugin : public Plugin
{
public: 
 std::string toString() {return "Menhinick";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
