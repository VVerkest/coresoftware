#ifndef __TRIGGERRUNINFOV1_H_
#define __TRIGGERRUNINFOV1_H_

#include <phool/PHObject.h>
#include "TriggerRunInfo.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdint>

class TriggerRunInfov1  : public TriggerRunInfo
{
public:
  
  TriggerRunInfov1();
  
  ~TriggerRunInfov1() override {}
  
  void setTrigger(int index, const std::string& name, int bit, int prescale) override;
  
  int getPrescaleByName(const std::string& name) const override ;

  void identify(std::ostream& os = std::cout) const override;

private:
    std::array<std::string, 64> trigger_names;
    std::array<int, 64> trigger_bits;
    std::array<int, 64> trigger_prescales;

 private:  // so the ClassDef does not show up with doc++
  ClassDefOverride(TriggerRunInfov1, 1);

};

#endif
