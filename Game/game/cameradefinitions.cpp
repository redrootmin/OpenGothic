#include "cameradefinitions.h"

#include "gothic.h"

CameraDefinitions::CameraDefinitions(Gothic &gothic) {
  auto vm = gothic.createVm(u"_work/Data/Scripts/_compiled/Camera.dat");

  camModDialog = loadCam(*vm,"CamModDialog");
  }

Daedalus::GEngineClasses::CCamSys CameraDefinitions::loadCam(Daedalus::DaedalusVM& vm,const char *name) {
  Daedalus::GEngineClasses::CCamSys ret={};
  auto id = vm.getDATFile().getSymbolIndexByName(name);
  if(id==size_t(-1))
    return ret;
  vm.initializeInstance(&ret, id, Daedalus::IC_CamSys);
  return ret;
  }