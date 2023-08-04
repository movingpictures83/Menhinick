#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MenhinickPlugin.h"

void MenhinickPlugin::input(std::string file) {
 inputfile = file;
}

void MenhinickPlugin::run() {

}

void MenhinickPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime diversity alpha --i-table "+inputfile+" --p-metric menhinick --o-alpha-diversity "+file+"; unzip -jo "+file+" -d "+PluginManager::prefix()+"; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<MenhinickPlugin> MenhinickPluginProxy = PluginProxy<MenhinickPlugin>("Menhinick", PluginManager::getInstance());
